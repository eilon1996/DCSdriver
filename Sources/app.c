#ifndef APP_H_
#define APP_H_


#include "extended_board_devices.h"

initGPIO(){
    enableClkToPorts();
	enableGlobalInterrupts();
    initPushButton(0);
    initLed(0);

    initSIM();
    InitTPM_PWMOutput();
    InitPIT();

}




#endif