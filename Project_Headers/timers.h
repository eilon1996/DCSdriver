#ifndef TIMERS_H_
#define TIMERS_H_

#include "MKL25Z4_registers.h"
#include "timers_driver.h"
#include "mcg.h"
#include "arm_cm0.h"

void InitPIT();
void initPTM();
void initSIM();


#endif
