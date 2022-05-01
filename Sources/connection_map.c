#include "connection_map.h"
//this file describe the connection of extended board ports to the MKL25z4 ports



Port PushButtons[4] = {
                                P1_0,
                                P1_1,
                                P1_2,
                                P1_3
                            };

Port Switches[4] = {
                                P2_0,
                                P2_1,
                                P2_2,
                                P2_3
                            };

Port Leds[8] = {
                                P2_3,
                                P2_1,
                                P2_2,
                                P2_3,
                                P2_0,
                                P2_1,
                                P2_2,
                                P2_3
                            };
LCD lcd = {
 		P1_4,		//lcd.d4
 		P1_5,		//lcd.d5
 		P1_6,		//lcd.d6
 		P1_7,		//lcd.d7
 		P2_5,		//lcd.enable
 		P2_6,		//lcd.reset
 		P2_7		//lcd.readWrite
};