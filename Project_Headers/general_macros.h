
#ifndef GENERAL_MACROS_H_
#define GENERAL_MACROS_H_

#include <stdint.h>

// our definitions
#define     debounceVal      0.25
#define     NOT_ACTIVE       0

// universal definitions
#define OUTPUT 1
#define INPUT  0

#define true   1
#define false  0


// -------------- arithmetic ---------------- //
#define   SEC_TO_MILLI(x)  (x*1000)
#define   MILLI_TO_SEC(x)  (x/1000.0f)
#define   ITERS_PER_SEC    0x240000
#define   KILO             1000
#define   FREQ_TO_TIME(x)  (1/(float)x)

// -------------- bit manicpulation ---------------- //

#define PORT_LOC(x)         ((uint32_t)(1<<x))
#define BIT(x)              (1<<x)
// #define WRITE_BIT(var, bit_num, value) (if(value){var |= BIT(bit_num);} else{var &=~ BIT(bit_num);})
#define WRITE_BIT(var, bit_num, value) ((value)? (var |= BIT(bit_num)) : (var &=~ BIT(bit_num)))
#define GET_BIT_VALUE(var, bit_num) ((var &= BIT(bit_num)) >> bit_num)

#define GET_MASK_VALUE(var, mask, shift) ((var & mask) >> shift);
#define WRITE_MASK(var, mask, shift, value)  (var = (uint32_t)(var&(uint32_t)(~(uint32_t)mask)) | (uint32_t)((uint32_t)value << shift))
typedef uint8_t bit_t; // indicate that the value should be 1 or 0

#pragma pack(1)
typedef struct {
  uint8_t b0 : 1;
  uint8_t b1 : 1;
  uint8_t b2 : 1;
  uint8_t b3 : 1;
  uint8_t b4 : 1;
  uint8_t b5 : 1;
  uint8_t b6 : 1;
  uint8_t b7 : 1;
  uint8_t b8 : 1;
  uint8_t b9 : 1;
  uint8_t b10 : 1;
  uint8_t b11 : 1;
  uint8_t b12 : 1;
  uint8_t b13 : 1;
  uint8_t b14 : 1;
  uint8_t b15 : 1;
  uint8_t b16 : 1;
  uint8_t b17 : 1;
  uint8_t b18 : 1;
  uint8_t b19 : 1;
  uint8_t b20 : 1;
  uint8_t b21 : 1;
  uint8_t b22 : 1;
  uint8_t b23 : 1;
  uint8_t b24 : 1;
  uint8_t b25 : 1;
  uint8_t b26 : 1;
  uint8_t b27 : 1;
  uint8_t b28 : 1;
  uint8_t b29 : 1;
  uint8_t b30 : 1;
  uint8_t b31 : 1;
} volatile *Bit_Map;
#pragma pack()

#pragma pack(1)
typedef enum {
  b0 = 0,
  b1,
  b2,
  b3,
  b4,
  b5,
  b6,
  b7,
  b8,
  b9,
  b10,
  b11,
  b12,
  b13,
  b14,
  b15,
  b16,
  b17,
  b18,
  b19,
  b20,
  b21,
  b22,
  b23,
  b24,
  b25,
  b26,
  b27,
  b28,
  b29,
  b30,
  b31,
} Bit_Map_Enum;
#pragma pack()

//-------  interrupt config---------------------------------------------
#define IRQ 1
#define DMA 0
#define IRQ_OR_DMA_BIT      b19
#define FALLING_EDGE_BIT    b17
#define RISING_EDGE_BIT     b16


#pragma pack(1)
typedef struct {
  uint8_t irq_enable    : 5; // 0:pull enable , 1: pull select, 4: filter for hig frequencies
  uint8_t not_used      : 3; // maybe will be used in later
  uint8_t role          : 3; // called MUX
  uint8_t reserved1     : 5;
  uint8_t irq_edge      : 3;
  uint8_t irq_or_dma    : 1;
  uint8_t reserved2     : 4;
  uint8_t irq_flag      : 1;
  uint8_t reserved3     : 7;
} volatile *pcr_Bit_Map;
#pragma pack()

#define DMA 0
#define IRQ 1

#define IRQ_ENABLE              0X13
#define IRQ_DISABLE             0X0

// #define PULL_UP            		IRQ_CONFIG_FALLING_EDGE
// #define PULL_DOWN           	IRQ_CONFIG_RISING_EDGE


typedef enum {
  DISABLE_ROLE        = 0,
  GPIO_ROLE           = 1,
  INPUT_CAPTURE_ROLE  = 4,
} PortRole;


typedef enum {
  IRQ_DISABALED                = 0x0,
  DMA_ON_RISING_EDGE           = 0x1,
  DMA_ON_FALLIING_EDGE         = 0x2,
  DMA_ON_EITHER_EDGE           = 0x3,
  INTERRUPT_ON_ZERO            = 0x8,
  INTERRUPT_ON_RISING_EDGE     = 0x9,
  INTERRUPT_ON_FALLIING_EDGE   = 0xA,
  INTERRUPT_ON_EITHER_EDGE     = 0xB,
  INTERRUPT_ON_ONE             = 0xC
} IRQType;

#endif
