/*
 * main implementation: use this 'C' sample to create your own application
 *
 */





#include "derivative.h" /* include peripheral declarations */
#include "MKL25Z4_registers.h" /* include peripheral declarations */
#include "extended_board_devices.h"
#include "my_irq_handler.h"
#include "bsp.h"

int main(void)
{
	//GPIOconfig();
	//LEDsArrPortToggle(0xF);
	enableClkToPorts();
	enableGlobalInterrupts();
	initPushButton(0);
	initLed(0);
	for(;;) {

	}

	return 0;
}
