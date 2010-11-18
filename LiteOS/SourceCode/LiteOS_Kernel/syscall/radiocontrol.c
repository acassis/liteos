#include "radiocontrol.h"
#include "../io/radio/socket.h"

 
radio_receiving_buffer radio_buf;

//-------------------------------------------------------------------------
void setRadioFrequencyTask()
{
    volatile uint16_t freq;
    asm volatile ("mov  %A0, r20" "\n\t" "mov  %B0, r21" "\n\t":"=r" (freq):);

    cc2420controlm_CC2420Control_TuneManual(freq);
    return;
}

//-------------------------------------------------------------------------
void setRadioChannelTask()
{
    volatile uint16_t freq;
    asm volatile ("mov  %A0, r20" "\n\t" "mov  %B0, r21" "\n\t":"=r" (freq):);

    cc2420controlm_CC2420Control_TuneChannel(freq);
    return;
}

//-------------------------------------------------------------------------
void setRadioPowerTask()
{
    volatile uint16_t powerlevel;
    asm volatile ("mov  %A0, r20" "\n\t" "mov  %B0, r21"
                  "\n\t":"=r" (powerlevel):);
    cc2420controlm_CC2420Control_TunePower(powerlevel);
    return;
}

void SocketRadioSend()
{
   	//debugrf230
    //Leds_redToggle(); 

    postTask(send_task, 9);
    //After it is woken up, return
    return;
}


//void getRadioInfo()  __attribute__((naked));
void *getRadioSendingBufferAddr()
{
    return (void *)&radiosocketdata;
    //asm volatile( "mov r20, %A0""\n\t""mov r21, %B0""\n\t": : "r"( addr ) );
    // asm volatile("ret"::); 
}

 
 
 //void getRadioInfo()  __attribute__((naked));
void *getRadioReceivingBufferAddr()
{
    return (void *)&radio_buf;
    //asm volatile( "mov r20, %A0""\n\t""mov r21, %B0""\n\t": : "r"( addr ) );
    // asm volatile("ret"::); 
}
 
 
 
//system call interface for registering an event 
void registerReceiverHandle_syscall()
{
    registerEvent(radio_buf.port, radio_buf.maxLength, radio_buf.dataReady,
                  radio_buf.data, radio_buf.packetinfo,
                  radio_buf.handlefunc);
}
