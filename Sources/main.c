/*
 * main implementation: use this 'C' sample to create your own application
 *
 */





#include "derivative.h" /* include peripheral declarations */
#include "MKL25Z4_registers.h" /* include peripheral declarations */
#include "extended_board_devices.h"
#include "my_irq_handler.h"
#include "app.h"

int main(void)
{
	initGPIO();
	lcd_data('a');
	for(;;) {
		//setPITCountTo(0, 0x01FAF080);
		//toggleLed(0);

	}

	return 0;
}


void PIT_IRQHandler(){

}
