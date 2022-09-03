// Joypad handling library
// in order to have 4 direction and press
// should be apjoy.h
#ifndef MY_LIBRARY_H
#define MY_LIBRARY_H
#include <Arduino.h>

typedef enum Directions {
    NONE = 0,
    UP,
    DOWN,
    RIGHT,
    LEFT
} Direction;

typedef enum Btn_States {
    UNPRESSED = 0,
    PRESSED
} Btn_State;

class APJoy {
private:
	byte adx;
	byte ady;
	byte button;
    int thr_radius_x;
    int thr_radius_y;


public:
	APJoy(byte, byte, byte, int, int);
    void calib();
	Direction Read_dir();
	Btn_State Read_Button();
    int x;    //read raw values (no Volt)
    int y;    //read raw values
    int center_x;
    int center_y;
};

#endif
