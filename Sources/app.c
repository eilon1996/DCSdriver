
#include "app.h"
#include "extended_board_devices.h"

void initGPIO(){

    enableClkToPorts();
	enableGlobalInterrupts();
    initPushButton(0);
    initPushButton(1);
    initPushButton(2);
    initLed(0);
    lcd_init();


    initSIM();
    // InitTPM_PWMOutput(0, 0);
    // InitPIT();
    Port a = {0,0};
    InitTPM_InputCapture('a',a);

}

