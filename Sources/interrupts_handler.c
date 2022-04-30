
#include "interrupts_handler.h"

// IRQHandlers

void handle_IRQ(DeviceId deviceId){

    switch (deviceId)
    {
        // add cases
        case PUSH_BUTTON_0:
            turnOnLed(0);
            //LED_0_PDOR = !LED_0_PDOR;
        case PUSH_BUTTON_1:
            //LED_0_PDOR = 1;
    default:
        assert(0);
        break;
    }
}

// don't change
void PORTD_IRQHandler(void){
    //delaySec(debounceVal);
    DeviceId deviceId = get_IRQ_source(BASE_D);
    handle_IRQ(deviceId);
}

void PORTA_IRQHandler(void){
    //delaySec(debounceVal);
    DeviceId deviceId = get_IRQ_source(BASE_A);
    handle_IRQ(deviceId);
}
