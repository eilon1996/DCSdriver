#include "extended_board_devices.h"

//--------------- inits
void initPushButton(uint8_t push_button_id){
    setDiraction(PushButtons[push_button_id], INPUT);
    setPortRole(PushButtons[push_button_id], GPIO_ROLE);
    setIRQType(PushButtons[push_button_id], PUSH_BUTTON_DEFAULT_EDGE(push_button_id));
    setPassiveFilter(PushButtons[push_button_id]);
}

void initSwitch(uint8_t switch_id){
    setDiraction(Switches[switch_id], INPUT);
    setPortRole(Switches[switch_id], GPIO_ROLE);
    setIRQType(Switches[switch_id], INTERRUPT_ON_EITHER_EDGE);
}

void initLed(uint8_t led_id){
    setDiraction(Leds[led_id], OUTPUT);
    setPortRole(Leds[led_id], GPIO_ROLE);
    setOutputData(Leds[led_id], 0);
    setHighDriveStrength(Leds[led_id]);
    setSlowSlewRate(Leds[led_id]);
}

//---------------------

void turnOnLed(uint8_t led_id){
    setOutputData(Leds[led_id], 1);
}
void turnOffLed(uint8_t led_id){
    setOutputData(Leds[led_id], 0);
}
void toggleLed(uint8_t led_id){
    setOutputData(Leds[led_id], !getOutputData(Leds[led_id]));
}


//----------





DeviceId get_IRQ_source(PortBase base){

    if(getIRQFlag(PushButtons[0]) == 1 && PushButtons[0].base == base) {clearIRQFlag(PushButtons[0]);   return PUSH_BUTTON_0;}
    if(getIRQFlag(PushButtons[1]) == 1 && PushButtons[1].base == base) {clearIRQFlag(PushButtons[1]);   return PUSH_BUTTON_1;}
    if(getIRQFlag(PushButtons[2]) == 1 && PushButtons[2].base == base) {clearIRQFlag(PushButtons[2]);   return PUSH_BUTTON_2;}
    if(getIRQFlag(PushButtons[3]) == 1 && PushButtons[3].base == base) {clearIRQFlag(PushButtons[3]);   return PUSH_BUTTON_3;}

    if(getIRQFlag(Switches[0]) == 1 && Switches[0].base == base) {clearIRQFlag(Switches[0]);   return SWITCH_0;}
    if(getIRQFlag(Switches[1]) == 1 && Switches[1].base == base) {clearIRQFlag(Switches[1]);   return SWITCH_1;}
    if(getIRQFlag(Switches[2]) == 1 && Switches[2].base == base) {clearIRQFlag(Switches[2]);   return SWITCH_2;}
    if(getIRQFlag(Switches[3]) == 1 && Switches[3].base == base) {clearIRQFlag(Switches[3]);   return SWITCH_3;}

    // add one for PWM_IN

    //assert(0);               // if device not found we probably have a problem so we rise exception
    return DEVICE_NOT_FOUND; // the return is only to avoid warning
}
