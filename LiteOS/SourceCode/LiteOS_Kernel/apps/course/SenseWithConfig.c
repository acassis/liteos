#include "leds.h"
#include "system.h"
#include "liteoscommon.h"
#include "thread.h"
#include "radio.h"
#include "stringutil.h"
#include "file.h"
#include "adc.h"

 MYFILE *fileptr;
 MYFILE *configptr; 
 uint16_t reading;
 uint16_t type; 
 uint16_t sleeptime; 
 uint16_t samples;

int main()
{ 
uint8_t config[17]; 
  
if((configptr = mfopen("/config", "r"))){ 
 	mfread(configptr, config, 16);
 	mfclose(configptr);
 	config[16]='\0';
	
	type = hex2value(config[0]); 
 	sleeptime = hex2value(config[1])*1000+hex2value(config[2])*100+hex2value(config[3])*10+hex2value(config[4]);
 	samples = hex2value(config[5])*100 + hex2value(config[6])*10 + hex2value(config[7]);
 	
 }
else{
	type = 1; 
      sleeptime = 100; 
      samples = 30;
}

 fileptr = mfopen("/deposit", "w");

 while (1)
 {
 
   if (samples >0)
   	samples--; 
   else
   	break; 
    
   sleepThread(sleeptime);

   if (type == 1)
   	reading = get_light();
   else if (type == 2)
   	reading = get_accx();
   else if (type == 3)
   	reading = get_temp(); 
   else
  	reading = 0; 

   redToggle(); 

   char _tempbuffer[32];
   char *_temp1 = "The reading is ";
   char *_temp2 = String_intToString(reading);
   char *_temp3 = "\n";
   uint8_t lengthstring;
    
   _tempbuffer[0] = '\0';
   String_append(_tempbuffer, _temp1);
   String_append(_tempbuffer, _temp2);
   String_append(_tempbuffer, _temp3);

   lengthstring = String_length(_tempbuffer); 

   mfwrite(fileptr, _tempbuffer, lengthstring);
   mfseek(fileptr, lengthstring, 1);
}
yellowToggle();

mfclose(fileptr);
return 0; 
}

