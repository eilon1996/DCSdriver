#ifndef TIMERS_H_
#define TIMERS_H_

#include "MKL25Z4_registers.h"
#include "mcg.h"
#include "arm_cm0.h"

typedef enum{
	DEVICE_CLOCK_BY_1   = 0,
	DEVICE_CLOCK_BY_2   = 1,
	DEVICE_CLOCK_BY_4   = 2,
	DEVICE_CLOCK_BY_8   = 3,
	DEVICE_CLOCK_BY_16  = 4,
	DEVICE_CLOCK_BY_32  = 5,
	DEVICE_CLOCK_BY_64  = 6,
	DEVICE_CLOCK_BY_128 = 7
}ClockDivider;
typedef enum{
	CHANNEL_DISSABLED = 0,
	INPUT_CAPTURE_RISING_EDGE = 1,
	INPUT_CAPTURE_FALLING_EDGE = 2,
	INPUT_CAPTURE_EITHER_EDGE = 3,
	SOFTWARE_COMPARE = 4,
	OUTPUT_COMPARE_TOGGLE_OUTPUT_ON_MATCH = 5,
	OUTPUT_COMPARE_CLEAR_OUTPUT_ON_MATCH = 6,
	OUTPUT_COMPARE_SET_OUTPUT_ON_MATCH = 7,
	EDGE_ALIGNED_PWM_LOW_TRUE = 8,	//clear output on match set on reload
	EDGE_ALIGNED_PWM_HIGH_TRUE = 9, //clear output on match set on reload
	OUTPUT_COMPARE_HIGH_OUTPUT_ON_MATCH = 14,
	OUTPUT_COMPARE_LOW_OUTPUT_ON_MATCH = 15
}PTMChannelConfig;

typedef enum{
	DISABLED = 0,
	PTMOnDebug_WORK = 3,
}PTMOnDebug;


//----------------

typedef enum{
	ClockSource_DISABLED = 0,
	MCGFLLCLK = 1,
	OSCERCLK = 2,
	MCGIRCLK = 3,
	MCGFLLCLK_DIV2 = 5,

}ClockSource;

void InitPIT();
void InitTPM_PWMOutput(uint8_t tpm_id, uint8_t channel);
void InitTPM_InputCapture(char x, Port port);
void initSIM();

void setPITCountTo(uint8_t countToIndex, uint32_t countTo);

#endif
