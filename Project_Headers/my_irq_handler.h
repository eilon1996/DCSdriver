
#ifndef INTERRUPT_HANDLER_H
#define INTERRUPT_HANDLER_H
#include "extended_board_devices.h"
#include "general_macros.h"
#include "arm_cm0.h"    // Global interrupt enable/disable is in this file

void handle_IRQ(DeviceId deviceId);
void enableGlobalInterrupts();
//    Note: only Port A and Port D can act as interrupt

#endif