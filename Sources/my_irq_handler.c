#include "my_irq_handler.h"
#include "arm_cm0.h"


void enableGlobalInterrupts(){
    GIE();                              // Enable global Interrupts

	enable_irq(INT_PORTD-16);           // Enable Interrupts to port D
	set_irq_priority (INT_PORTD-16,0);  // Interrupt priority = 0 = max

	enable_irq(INT_PORTA-16);           // Enable Interrupts to port A
	set_irq_priority (INT_PORTA-16,0);  // Interrupt priority = 0 = max
}

void handle_IRQ(DeviceId deviceId){

    switch (deviceId)
    {
        case PUSH_BUTTON_0:
            //toggleLed(0);
            break;
            //LED_0_PDOR = !LED_0_PDOR;
        case PUSH_BUTTON_1:
            //toggleLed(0);
            break;
        case PUSH_BUTTON_2:
            //toggleLed(0);
            break;
            //LED_0_PDOR = 1;
    default:
        //assert(0);
        break;
    }
}

// don't change
#define   ITERS_PER_SEC    0x240000
void delaySec(float sec){  // t[msec]
	volatile unsigned int iters = (int)(ITERS_PER_SEC * sec);
	for(; iters>0; iters--);
}

void PORTD_IRQHandler(void){
    delaySec(debounceVal);
    DeviceId deviceId = get_IRQ_source(BASE_D);
    handle_IRQ(deviceId);
}

void PORTA_IRQHandler(void){
    delaySec(debounceVal);
    DeviceId deviceId = get_IRQ_source(BASE_A);
    handle_IRQ(deviceId);
}



void FTM0_IRQHandler(){
    //static int freqVal = 0;
    //static int currentFreq = 0;
    //unsigned int tempFreq;

    int currentCount;

    if (TPM0_C0SC&0x80){
        currentCount = TPM0_C0V;                // Holds the value of the TPMcounter - input capture mode
        // LCDupdatefreq();
        TPM0_C0SC |= 0x80;                     //clear CHF bit

    }
        //tempFreq = CPUFREQ / FTM0_C0V;
        //currentFreq = (abs(currentFreq-freqVal) > 1) ? freqVal : currentFreq;

        //lcd_puts("Measured frquency\n%d [Hz]", currentFreq);
}
