#ifndef CONNECTION_MAP_H_
#define CONNECTION_MAP_H_


#include "MKL25Z4_registers.h"


//this file describe the connection of extended board ports to the MKL25z4 ports

typedef struct
{
  Port d4;
  Port d5;
  Port d6;
  Port d7;
  Port enable;
  Port reset;
  Port readWrite;
}LCD;




#define NOT_USED NULL

#define P1_0  {BASE_D, 2}   //pb0
#define P1_1  {BASE_D, 3}   //pb1
#define P1_2  {BASE_D, 1}   //pb2
#define P1_3  {BASE_B, 3}   //analog

#define P1_4  {BASE_C, 1}    //d4
#define P1_5  {BASE_C, 2}    //d5
#define P1_6  {BASE_E, 30}   //d6
#define P1_7  {BASE_E, 29}   //d7

#define P2_0  {BASE_C, 5}        // test input pwm
#define P2_1  {BASE_A, 2}
#define P2_2  {BASE_A, 1}
#define P2_3  {BASE_C, 4}   // test output pwm
#define P2_4  {BASE_C, 5}
#define P2_5  {BASE_C, 6}       //e -
#define P2_6  {BASE_C, 10}      //rst
#define P2_7  {BASE_C, 11}      //r/w


extern Port PushButtons[4];
extern Port Switches[4];
extern Port Leds[8];
extern LCD lcd;

#endif
