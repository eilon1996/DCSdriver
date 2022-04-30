#include "MKL25Z4_registers.h"

GPIO_MemMapPtr GpioPortArray[BASE_NUM] =  { PTA_BASE_PTR, PTB_BASE_PTR, PTC_BASE_PTR, PTD_BASE_PTR, PTE_BASE_PTR };
PORT_MemMapPtr xxxPortArray[BASE_NUM] = {PORTA_BASE_PTR, PORTB_BASE_PTR, PORTC_BASE_PTR, PORTD_BASE_PTR, PORTE_BASE_PTR};

void enableClkToPorts(){
    SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK | SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTC_MASK | SIM_SCGC5_PORTD_MASK | SIM_SCGC5_PORTE_MASK;
}

void setDiraction(Port port, bit_t value){
    WRITE_BIT(GpioPortArray[port.base]->PDDR, port.bit, value);
}
bit_t getDiraction(Port port){
    return GET_BIT_VALUE(GpioPortArray[port.base]->PDDR, port.bit);
}
//-----------
bit_t getInputData(Port port){
    //assert(getDiraction(port) == INPUT);
    return GET_BIT_VALUE(GpioPortArray[port.base]->PDOR, port.bit);
}
//--------
void setOutputData(Port port, bit_t value){
    //assert(getDiraction(port) == OUTPUT);
    WRITE_BIT(GpioPortArray[port.base]->PDOR, port.bit, value);
}

bit_t getOutputData(Port port){
    //assert(getDiraction(port) == OUTPUT);
    return GET_BIT_VALUE(GpioPortArray[port.base]->PDOR, port.bit);
}
//--------
void clearIRQFlag(Port port){
    xxxPortArray[port.base]->ISFR |= BIT(port.bit);     // clear ISFR is done by writing 1
}
bit_t getIRQFlag(Port port){
    //assert(port.base == BASE_A || port.base == BASE_D);
    return GET_BIT_VALUE(xxxPortArray[port.base]->ISFR, port.bit);
}
//--------
void setPortRole(Port port, PortRole role){
	// Not all pins support all pin muxing slots (can cause exception)
    WRITE_MASK(xxxPortArray[port.base]->PCR[port.bit], PORT_PCR_MUX_MASK, PORT_PCR_MUX_SHIFT, role);
}
PortRole getPortRole(Port port){
    return (PortRole)GET_MASK_VALUE(xxxPortArray[port.base]->PCR[port.bit],PORT_PCR_MUX_MASK, PORT_PCR_MUX_SHIFT);
}
//--------
void setIRQType(Port port, IRQType irqType){
    WRITE_MASK(xxxPortArray[port.base]->PCR[port.bit], PORT_PCR_IRQC_MASK, PORT_PCR_IRQC_SHIFT, irqType);
}
IRQType getIRQType(Port port){
    return (IRQType)GET_MASK_VALUE(xxxPortArray[port.base]->PCR[port.bit],PORT_PCR_IRQC_MASK,  PORT_PCR_IRQC_SHIFT);
}
//--------
void setHighDriveStrength(Port port){
    xxxPortArray[port.base]->PCR[port.bit] |= PORT_PCR_DSE_MASK;
}
bit_t getDriveStrength(Port port){
    return (bit_t)GET_MASK_VALUE(xxxPortArray[port.base]->PCR[port.bit],PORT_PCR_DSE_MASK,  PORT_PCR_DSE_SHIFT);
}
//--------
void setSlowSlewRate(Port port){
    xxxPortArray[port.base]->PCR[port.bit] |= PORT_PCR_SRE_MASK;
}
bit_t getSlewRate(Port port){
    return (bit_t)GET_MASK_VALUE(xxxPortArray[port.base]->PCR[port.bit],PORT_PCR_SRE_MASK,  PORT_PCR_SRE_SHIFT);
}//--------
void setPullEnable(Port port){
    xxxPortArray[port.base]->PCR[port.bit] |= PORT_PCR_PE_MASK;
}
bit_t getPullEnable(Port port){
    return (bit_t)GET_MASK_VALUE(xxxPortArray[port.base]->PCR[port.bit],PORT_PCR_PE_MASK,  PORT_PCR_PE_SHIFT);
}//--------
void setPullSelect(Port port){
    xxxPortArray[port.base]->PCR[port.bit] |= PORT_PCR_PS_MASK;
}
bit_t getPullSelect(Port port){
    return (bit_t)GET_MASK_VALUE(xxxPortArray[port.base]->PCR[port.bit],PORT_PCR_PS_MASK,  PORT_PCR_PS_SHIFT);
}
//--------
void setPassiveFilter(Port port){
    xxxPortArray[port.base]->PCR[port.bit] |= PORT_PCR_PFE_MASK;
}
bit_t getPassiveFilter(Port port){
    return (bit_t)GET_MASK_VALUE(xxxPortArray[port.base]->PCR[port.bit],PORT_PCR_PFE_MASK,  PORT_PCR_PFE_SHIFT);
}
//--------


