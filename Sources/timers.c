#include "timers_driver.h"


void InitTPM_PWMOutput(uint8_t tpm_id, uint8_t channel){
	enableClockToPTM();
	setPrescale(tpm_id, DEVICE_CLOCK_BY_128);
	enablePTMInterrupt(tpm_id);
	setPTMChannelConfig(tpm_id, channel, EDGE_ALIGNED_PWM_HIGH_TRUE);
	setPTMToworkInDebug(tpm_id);
    //setPTMCompareValue(tpm_id, channel, 0xFFFF);	// is this a key word or not?
	//setPTMCountTo(tpm_id, 0x2EE0);
}


void initSIM(){
	pll_init(8000000, LOW_POWER, CRYSTAL,4,24,MCGOUT); //Core Clock is now at 48MHz using the 8MHZ Crystal
	selectClockSource(MCGFLLCLK_DIV2);
}

void InitPIT(){
    enableClockToPIT();
	PITEnable(); //enable PIT0 and its interrupt
    PITIRQEnable();
	PITEnbleInDebug();
	enable_irq(INT_PIT-16); //  //Enable PIT IRQ on the NVIC
	set_irq_priority(INT_PIT-16,0);  // Interrupt priority = 0 = max

    //setPITCountTo(countToIndex, countTo);
}
