/* The LiteOS Operating System Kernel */
/*
   The following is the license of LiteOS.
   This file is part of LiteOS.
   Copyright Qing Cao, 2007-2008, University of Illinois , qcao2@uiuc.edu
   LiteOS is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   LiteOS is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   You should have received a copy of the GNU General Public License
   along with LiteOS.  If not, see <http://www.gnu.org/licenses/>.
 */
 
#ifndef EVENTLOGGERH
#define EVENTLOGGERH
#include "../types/types.h"
//In the future, this file should be organized into central control point for differne types of
//hardware logging control
// #define TRACE_ENABLE
// #define SERIAL_TRACE
// #define TRACE_ENABLE_CONTEXTSWITCH
// #define TRACE_ENABLE_RADIOEVENT
// #define TRACE_ENABLE_ADCEVENT
// #define TRACE_ENABLE_LEDEVENT
// #define TRACE_ENABLE_THREADCREATE
// #define TRACE_ENABLE_THREADDESTROY


//Works at top level without being affected by TRACE_ENABLE
#define TRACE_ENABLE_SYSCALLEVENT
//Now this is a list of possible events under tracking
//PLATFORM SPECIFIC
//////////////////////////////////////////////////////////////////////
//MICAZ TRACE LOGGING UTILIITES FOR SYSTEM CALLS
//MICAZ ONLY.
//////////////////////////////////////////////////////////////////////
#if defined(PLATFORM_AVR)
#define TRACE_CONTEXTSWITCHTOUSERTHREAD     								1
#define TRACE_CONTEXTSWITCHFROMUSERTHREAD   								2
#define TRACE_RADIOEVENT_RECEIVEPACKET	    								3
#define TRACE_RADIOEVENT_SENDPACKET 												4
#define TRACE_ADCEVENT_READLIGHT            								5
#define TRACE_ADCEVENT_READTEMP 														6
#define TRACE_LEDEVENT_REDTOGGLE            								20
#define TRACE_LEDEVENT_GREENTOGGLE          								21
#define TRACE_LEDEVENT_YELLOWTOGGLE         								22
#define TRACE_THREADCREATE                                                  23
#define TRACE_THREADDESTROY													24
#define TRACE_ENABLE_SYSCALL_YIELDFUNCTION
#define TRACE_SYSCALL_YIELDFUNCTION											101
#define TRACE_ENABLE_SYSCALL_GREENTOGGLEFUNCTION
#define TRACE_SYSCALL_GREENTOGGLEFUNCTION   								102
#define TRACE_ENABLE_SYSCALL_REDTOGGLEFUNCTION
#define TRACE_SYSCALL_REDTOGGLEFUNCTION     								103
#define TRACE_ENABLE_SYSCALL_GETCURRENTTHREADADDRESS
#define TRACE_SYSCALL_GETCURRENTTHREADADDRESS 							104
#define TRACE_ENABLE_SYSCALL_GETRADIOMUTEX
#define TRACE_SYSCALL_GETRADIOMUTEX         								105
#define TRACE_ENABLE_SYSCALL_GETRADIOSENDFUNCTION
#define TRACE_SYSCALL_GETRADIOSENDFUNCTION  								106
#define TRACE_ENABLE_SYSCALL_MUTEXUNLOCKFUNCTION
#define TRACE_SYSCALL_MUTEXUNLOCKFUNCTION     							107
#define TRACE_ENABLE_SYSCALL_GETCURRENTTHREADINDEX
#define TRACE_SYSCALL_GETCURRENTTHREADINDEX  								108
#define TRACE_ENABLE_SYSCALL_GETFILEPATHADDR
#define TRACE_SYSCALL_GETFILEPATHADDR        								109
#define TRACE_ENABLE_SYSCALL_GETFILEMODEADDR
#define TRACE_SYSCALL_GETFILEMODEADDR        								110
#define TRACE_ENABLE_SYSCALL_GETFILEMUTEXADDR
#define TRACE_SYSCALL_GETFILEMUTEXADDR       								111
#define TRACE_ENABLE_SYSCALL_OPENFILESYSCALL
#define TRACE_SYSCALL_OPENFILESYSCALL        								112
#define TRACE_ENABLE_SYSCALL_CLOSEFILESYSCALL
#define TRACE_SYSCALL_CLOSEFILESYSCALL       								113
#define TRACE_ENABLE_SYSCALL_READFILESYSCALL
#define TRACE_SYSCALL_READFILESYSCALL        								114
#define TRACE_ENABLE_SYSCALL_WRITEFILESYSCALL
#define TRACE_SYSCALL_WRITEFILESYSCALL       								115
#define TRACE_ENABLE_SYSCALL_SEEKFILESYSCALL
#define TRACE_SYSCALL_SEEKFILESYSCALL      								116
#define TRACE_ENABLE_SYSCALL_ADCLIGHTSYSCALL
#define TRACE_SYSCALL_ADCLIGHTSYSCALL      								117
#define TRACE_ENABLE_SYSCALL_ADCTEMPSYSCALL
#define TRACE_SYSCALL_ADCTEMPSYSCALL       								118
#define TRACE_ENABLE_SYSCALL_ADCMAGXSYSCALL
#define TRACE_SYSCALL_ADCMAGXSYSCALL       								119
#define TRACE_ENABLE_SYSCALL_ADCMAGYSYSCALL
#define TRACE_SYSCALL_ADCMAGYSYSCALL       								120
#define TRACE_ENABLE_SYSCALL_ADCACCXSYSCALL
#define TRACE_SYSCALL_ADCACCXSYSCALL       								121
#define TRACE_ENABLE_SYSCALL_ADCACCYSYSCALL
#define TRACE_SYSCALL_ADCACCYSYSCALL       								122
#define TRACE_ENABLE_SYSCALL_POSTTASKSYSCALL
#define TRACE_SYSCALL_POSTTASKSYSCALL                                      123
#define TRACE_ENABLE_SYSCALL_GETCURRENTRADIOINFOADDRESS
#define TRACE_SYSCALL_GETCURRENTRADIOINFOADDRESS 						124
#define TRACE_ENABLE_SYSCALL_GETCURRENTRADIOHANDLEADDRESS
#define TRACE_SYSCALL_GETCURRENTRADIOHANDLEADDRESS 					125
#define TRACE_ENABLE_SYSCALL_GETCURRENTRADIOHANDLE
#define TRACE_SYSCALL_GETCURRENTRADIOHANDLE    							126
#define TRACE_ENABLE_SYSCALL_POSTTHREADTASK
#define TRACE_SYSCALL_POSTTHREADTASK           							127
#define TRACE_ENABLE_SYSCALL_DEBUGINFOTASK
#define TRACE_SYSCALL_DEBUGINFOTASK          								128
#define TRACE_ENABLE_SYSCALL_YELLOWTOGGLEFUNCTION
#define TRACE_SYSCALL_YELLOWTOGGLEFUNCTION    							129
#define TRACE_ENABLE_SYSCALL_REDONFUNCTION
#define TRACE_SYSCALL_REDONFUNCTION         								130
#define TRACE_ENABLE_SYSCALL_REDOFFFUNCTION
#define TRACE_SYSCALL_REDOFFFUNCTION        								131
#define TRACE_ENABLE_SYSCALL_YELLOWONFUNCTION
#define TRACE_SYSCALL_YELLOWONFUNCTION        							132
#define TRACE_ENABLE_SYSCALL_YELLOWOFFFUNCTION
#define TRACE_SYSCALL_YELLOWOFFFUNCTION     								133
#define TRACE_SYSCALL_GREENONFUNCTION        								134
#define TRACE_ENABLE_SYSCALL_GREENONFUNCTION
#define TRACE_SYSCALL_GREENOFFFUNCTION       								135
#define TRACE_ENABLE_SYSCALL_GREENOFFFUNCTION
#define TRACE_SYSCALL_BREAKFUNCTION          								136
#define TRACE_ENABLE_SYSCALL_BREAKFUNCTION
#define TRACE_SYSCALL_GETSERIALMUTEX         								137
#define TRACE_ENABLE_SYSCALL_GETSERIALMUTEX
#define TRACE_SYSCALL_GETCURRENTSERIALINFOADDRESS 					138
#define TRACE_ENABLE_SYSCALL_GETCURRENTSERIALINFOADDRESS
#define TRACE_SYSCALL_GETSERIALSENDFUNCTION    							139
#define TRACE_ENABLE_SYSCALL_GETSERIALSENDFUNCTION
#define TRACE_SYSCALL_GETCURRENTSERIALHANDLEADDRESS  				140
#define TRACE_ENABLE_SYSCALL_GETCURRENTSERIALHANDLEADDRESS
#define TRACE_SYSCALL_SETCURRENTSERIALHANDLEADDRESS  			141
#define TRACE_ENABLE_SYSCALL_SETCURRENTSERIALHANDLEADDRESS
#define TRACE_SYSCALL_GETCURRENTEEPROMHANDLEADDRESS   			142
#define TRACE_ENABLE_SYSCALL_GETCURRENTEEPROMHANDLEADDRESS
#define TRACE_SYSCALL_READFROMEEPROM   										143
#define TRACE_ENABLE_SYSCALL_READFROMEEPROM
#define TRACE_SYSCALL_WRITETOEEPROM    										144
#define TRACE_ENABLE_SYSCALL_WRITETOEEPROM
#define TRACE_SYSCALL_MALLOCFUNCTION    										145
#define TRACE_ENABLE_SYSCALL_MALLOCFUNCTION
#define TRACE_SYSCALL_FREEFUNCTION     										146
#define TRACE_ENABLE_SYSCALL_FREEFUNCTION
#define TRACE_SYSCALL_DISABLERADIOSTATE   									147
#define TRACE_ENABLE_SYSCALL_DISABLERADIOSTATE
#define TRACE_SYSCALL_GETRANDOMNUMBER   										148
#define TRACE_ENABLE_SYSCALL_GETRANDOMNUMBER
#define TRACE_SYSCALL_SETRADIOFREQUENCY 										149
#define TRACE_ENABLE_SYSCALL_SETRADIOFREQUENCY
#define TRACE_SYSCALL_SETRADIOCHANNEL   										150
#define TRACE_ENABLE_SYSCALL_SETRADIOCHANNEL
#define TRACE_SYSCALL_SETRADIOPOWER     										151
#define TRACE_ENABLE_SYSCALL_SETRADIOPOWER
#define TRACE_SYSCALL_GETNODEID         										152
#define TRACE_ENABLE_SYSCALL_GETNODEID
#define TRACE_SYSCALL_SETNODEID         										153
#define TRACE_ENABLE_SYSCALL_SETNODEID
#define TRACE_SYSCALL_GETTHREADCONTROLBLOCK                154
#define TRACE_ENABLE_SYSCALL_GETTHREADCONTROLBLOCK
#define TRACE_SYSCALL_GETTHREADCONTROLMUTEX    							    155
#define TRACE_ENABLE_SYSCALL_GETTHREADCONTROLMUTEX
#define TRACE_SYSCALL_CREATETHREAD												156
#define TRACE_ENABLE_SYSCALL_CREATETHREAD
#define TRACE_SYSCALL_SOUNDERONFUNCTION     					157
#define TRACE_ENABLE_SYSCALL_SOUNDERONFUNCTION
#define TRACE_SYSCALL_SOUNDEROFFFUNCTION     					158
#define TRACE_ENABLE_SYSCALL_SOUNDEROFFFUNCTION
#endif
void initTrace();
void addTrace(uint8_t traceid, uint8_t threadid);
void *getTracingBlockAddress();
void enabletracingfunction();
void disabletracingfunction();
void apptracepointfunction() __attribute__ ((naked));
#endif