#ifndef CONNECTION_MAP_H_
#define CONNECTION_MAP_H_


#include "MKL25Z4_registers.h"


//this file describe the connection of extended board ports to the MKL25z4 ports

#define NOT_USED NULL

#define P1_0  {BASE_D, 2}
#define P1_1  {BASE_D, 3}
#define P1_2  {BASE_D, 1}
#define P1_3  {BASE_D, 1}
#define P1_4  {BASE_C, 1}
#define P1_5  NOT_USED
#define P1_6  NOT_USED
#define P1_7  NOT_USED

#define P2_0  {BASE_A, 1}
#define P2_1  {BASE_A, 2}
#define P2_2  {BASE_A, 1}
#define P2_3  {BASE_A, 1}
#define P2_4  {BASE_C, 5}
#define P2_5  NOT_USED
#define P2_6  NOT_USED
#define P2_7  NOT_USED


extern Port PushButtons[4];
extern Port Switches[4];
extern Port Leds[8];

#endif
