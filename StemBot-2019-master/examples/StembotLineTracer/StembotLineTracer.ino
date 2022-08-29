/* 
  OLED screen is deactivate for this combined (RC/auto) program
  because Arduino is out of memmory
 */
#define OLED //activate this line to use OLED screen

#include "StemBot2019.h"

/*
   INSTRUCTIONS Setup
   bot_setup(IR sensor calibration time in seconds);
   alignment(reduce left speed, reduce right speed, inverted left, inverted right, test);
   LED(green, yellow, red);
 */
void setup() {
  //input time in parentheses
  bot_setup(4);

  //reduce left speed, reduce right speed, invert left, invert right, test)
  alignment(0, 0, 0, 0, 0);
  LED(1, 0, 1);
  KP = 0.15, KI = 0, KD = 5;
}

/*
   INSTRUCTIONS loop
   junction(speed, trace back, junction, action, delay b4 turn, turn speed, turn duration, line color 1=black 0=white, IR offset);
  
   types of junctions
          robot                type 1         type 2                       type 3                              type 4
        direction              left           right                        middle                 follow line (dont care any junction) 
       
            H                   HH            HH                HHHHHHHHHHHH        HH              
          HHHHH                 HH            HH                     HH             HH
        HHHHHHHHH          HHHHHHH            HHHHHHH                HH             HH
           HHH                  HH            HH                     HH        HHHHHHHHHHHH
           HHH                  HH            HH                     HH             HH
           HHH                  HH            HH                     HH             HH
           HHH                  HH            HH                     HH             HH
 */
 
void loop() {
    // speed, traceback, junction type, action, delay b4 turn, turn speed, turn duration, line color 1=black 0=white, IR offset

    //Middle junction turn left
    junction( /*speed*/ 90, /*traceback*/ 100, /*junction type*/ 3, /*action*/ 11, /*delay b4 turn*/ 50, /*turn speed*/ 10, /*turn duration*/ 200, /*line color*/ 1, /*IR offset*/ 0);
    
    //Middle junction turn right
    junction( /*speed*/ 100, /*traceback*/ 100, /*junction type*/ 3, /*action*/ 22, /*delay b4 turn*/ 50, /*turn speed*/ 10, /*turn duration*/ 200, /*line color*/ 1, /*IR offset*/ 0);

    //Middle junction turn right
    junction( /*speed*/ 100, /*traceback*/ 100, /*junction type*/ 3, /*action*/ 22, /*delay b4 turn*/ 50, /*turn speed*/ 10, /*turn duration*/ 200, /*line color*/ 1, /*IR offset*/ 0);
    
    //Middle junction turn left
    junction( /*speed*/ 100, /*traceback*/ 100, /*junction type*/ 3, /*action*/ 11, /*delay b4 turn*/ 50, /*turn speed*/ 10, /*turn duration*/ 200, /*line color*/ 1, /*IR offset*/ 0);

    //Middle junction turn right
    junction( /*speed*/ 100, /*traceback*/ 100, /*junction type*/ 3, /*action*/ 22, /*delay b4 turn*/ 50, /*turn speed*/ 10, /*turn duration*/ 200, /*line color*/ 1, /*IR offset*/ 0);

    //Speed through it
    junction( /*speed*/ 255, /*traceback*/ 100, /*junction type*/ 4, /*action*/ 33, /*delay b4 turn*/ -1, /*turn speed*/ 10, /*turn duration*/ 200, /*line color*/ 1, /*IR offset*/ 0);
//
//    //white line
//    junction( /*speed*/ 255, /*traceback*/ 100, /*junction type*/ 4, /*action*/ 33, /*delay b4 turn*/ -1, /*turn speed*/ 10, /*turn duration*/ 200, /*line color*/ 0, /*IR offset*/ 0);
//
//    //black line
//    junction( /*speed*/ 255, /*traceback*/ 100, /*junction type*/ 4, /*action*/ 33, /*delay b4 turn*/ -1, /*turn speed*/ 10, /*turn duration*/ 200, /*line color*/ 1, /*IR offset*/ 0);
//
//    //white line
//    junction( /*speed*/ 255, /*traceback*/ 100, /*junction type*/ 4, /*action*/ 33, /*delay b4 turn*/ -1, /*turn speed*/ 10, /*turn duration*/ 200, /*line color*/ 0, /*IR offset*/ 0);
//
//    //black line
//    junction( /*speed*/ 255, /*traceback*/ 100, /*junction type*/ 4, /*action*/ 33, /*delay b4 turn*/ -1, /*turn speed*/ 10, /*turn duration*/ 200, /*line color*/ 1, /*IR offset*/ 0);
//
//    //right junction turn right
//    junction( /*speed*/ 255, /*traceback*/ 100, /*junction type*/ 2, /*action*/ 22, /*delay b4 turn*/ 50, /*turn speed*/ 10, /*turn duration*/ 200, /*line color*/ 0, /*IR offset*/ 0);
//
//    //middle junction turn right
//    junction( /*speed*/ 255, /*traceback*/ 100, /*junction type*/ 3, /*action*/ 22, /*delay b4 turn*/ 50, /*turn speed*/ 10, /*turn duration*/ 200, /*line color*/ 0, /*IR offset*/ 0);
//      

    Stop();
    display_finishTime();
}
