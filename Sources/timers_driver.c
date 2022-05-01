#include "timers_driver.h"

//----TPM
TPM_MemMapPtr tpm_Array[3] = {TPM0_BASE_PTR, TPM1_BASE_PTR, TPM2_BASE_PTR};

void setPrescale(uint8_t tpm_id, ClockDivider clockdivider){WRITE_MASK(tpm_Array[tpm_id]->SC, TPM_SC_PS_MASK, TPM_SC_PS_SHIFT, clockdivider);}
void enablePTMInterrupt(uint8_t tpm_id){WRITE_MASK(tpm_Array[tpm_id]->SC, TPM_SC_TOIE_MASK, TPM_SC_TOIE_SHIFT, 1);}	// write 0 for DMA request
bit_t getPTMIRQFlag(uint8_t tpm_id){return GET_MASK_VALUE(tpm_Array[tpm_id]->SC, TPM_SC_TOF_MASK, TPM_SC_TOF_SHIFT);}
void enablePTMDMA(uint8_t tpm_id){WRITE_MASK(tpm_Array[tpm_id]->SC, TPM_SC_DMA_MASK, TPM_SC_DMA_SHIFT, 1);}
void setPTMCountTo(uint8_t tpm_id, uint16_t countTo){tpm_Array[tpm_id]->MOD = countTo;}
void setPTMChannelConfig(uint8_t tpm_id, uint8_t channel, PTMChannelConfig cofig){WRITE_MASK(tpm_Array[tpm_id]->CONTROLS[channel].CnSC, 0x3C, 2, cofig);}
void enableChannelInterrupt(uint8_t tpm_id, uint8_t channel){WRITE_BIT(tpm_Array[tpm_id]->CONTROLS[channel].CnSC, 5, 1);}
uint16_t getCaptureTime(uint8_t tpm_id, uint8_t channel){return tpm_Array[tpm_id]->CONTROLS[channel].CnV & 0xFFFF;}
void setPTMCompareValue(uint8_t tpm_id, uint8_t channel, uint16_t value){tpm_Array[tpm_id]->CONTROLS[channel].CnV |= value;}
bit_t getChannelIRQFlag(uint8_t tpm_id, uint8_t channel){return GET_BIT_VALUE(tpm_Array[tpm_id]->STATUS, channel);}
bit_t getChannelIRQFlag_TOF(uint8_t tpm_id, uint8_t channel){return GET_BIT_VALUE(tpm_Array[tpm_id]->STATUS, 8);}
void setPTMToworkInDebug(uint8_t tpm_id){WRITE_MASK(tpm_Array[tpm_id]->CONF, TPM_CONF_DBGMODE_MASK, TPM_CONF_DBGMODE_SHIFT, PTMOnDebug_WORK);}
void PTMKeepCountingAfterOverFlow(uint8_t tpm_id){WRITE_MASK(tpm_Array[tpm_id]->CONF, TPM_CONF_CSOO_MASK, TPM_CONF_CSOO_SHIFT, 1);}
void reloadCounterOnTrigger(uint8_t tpm_id){WRITE_MASK(tpm_Array[tpm_id]->CONF, TPM_CONF_CROT_MASK, TPM_CONF_CROT_SHIFT, 1);}
void enableClockToPTM(){ SIM_SCGC6 |= SIM_SCGC6_TPM0_MASK | SIM_SCGC6_TPM1_MASK | SIM_SCGC6_TPM2_MASK;}


//----SIM
void selectClockSource(ClockSource source){WRITE_MASK(SIM_SOPT2, SIM_SOPT2_TPMSRC_MASK,SIM_SOPT2_TPMSRC_SHIFT, source&0X3); WRITE_MASK(SIM_SOPT2, SIM_SOPT2_PLLFLLSEL_MASK,SIM_SOPT2_PLLFLLSEL_SHIFT, (source==MCGFLLCLK_DIV2));}

//----PIT
void enableClockToPIT(){ SIM_SCGC6 |= SIM_SCGC6_PIT_MASK;}
void setPITCountTo(uint8_t countToIndex, uint32_t countTo){ PIT_BASE_PTR->CHANNEL[countToIndex].LDVAL = countTo;}
void PITEnable(){ PIT_TCTRL0 |= BIT(PIT_TCTRL_TEN_MASK);}
void PITIRQEnable(){ PIT_TCTRL0 |= BIT(PIT_TCTRL_TIE_MASK);}
void PITEnbleInDebug(){WRITE_MASK(PIT_MCR, PIT_MCR_FRZ_MASK, PIT_MCR_FRZ_SHIFT, 0);}

