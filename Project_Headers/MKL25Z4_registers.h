#ifndef MKL25Z4_REGISTERS_H_
#define MKL25Z4_REGISTERS_H_

#include "MKL25Z4.h"
#include "general_macros.h"



typedef enum{
    BASE_A = 0,
    BASE_B,
    BASE_C,
    BASE_D,
    BASE_E,
    BASE_NUM
} PortBase;


typedef struct
{
    PortBase base;
    uint8_t bit;
}Port;


void enableClkToPorts();

void setDiraction(Port port, bit_t value);
bit_t getDiraction(Port port);
//-----------
bit_t getInputData(Port port);
//--------
void setOutputData(Port port, bit_t value);
bit_t getOutputData(Port port);
//--------
void clearIRQFlag(Port port);
bit_t getIRQFlag(Port port);
//--------
void setPortRole(Port port, PortRole role);
PortRole getPortRole(Port port);
//--------
void setIRQType(Port port, IRQType irqType);
IRQType getIRQType(Port port);
//--------
void setHighDriveStrength(Port port);
bit_t getDriveStrength(Port port);
//--------
void setSlowSlewRate(Port port);
//--------
void setPullEnable(Port port);
bit_t getPullEnable(Port port);
void setPullSelect(Port port);
bit_t getPullSelect(Port port);
//--------
void setPassiveFilter(Port port);
bit_t getPassiveFilter(Port port);
//--------


#endif
