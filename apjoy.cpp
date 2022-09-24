// C++ program to include the
// custom header file

// Include statement to include
// custom header file
#include <math.h>
#include "apjoy.h"

#define    CALIB_CYLES     10

APJoy::APJoy(byte adx, byte ady, byte button, int thrx, int thry)
{
    this->adx = adx;
    this->ady = ady;
    this->button = button;
    this->thr_radius_x = thrx;
    this->thr_radius_y = thry;
}

// Function Calibration for center values
void APJoy::calib()
{
    this->center_x = 512;
    this->center_y = 512;

    int i = 0;
    for(i=0;i< CALIB_CYLES;i++){
        this->center_x += analogRead(this->adx);
	    this->center_y += analogRead(this->ady);
    }

    this->center_x /= CALIB_CYLES;
    this->center_y /= CALIB_CYLES; 
}

Direction APJoy::Read_dir()
{

    Direction ret1 = NONE;
    Direction ret2 = NONE;

    this->x = analogRead(this->adx);
    this->y = analogRead(this->ady);

    this->x -= this->center_x;
    this->y -= this->center_y;

    if((abs(this->x) < this->thr_radius_x) && (abs(this->y) < this->thr_radius_y)){
        return NONE;
    }

    if(this->x >= this->thr_radius_x)
        ret1 = RIGHT;
    
    if(this->x <= -this->thr_radius_x)
        ret1 = LEFT;

    if(this->y >= this->thr_radius_y)
        ret2 = UP;
    
    if(this->y <= -this->thr_radius_y)
        ret2 = DOWN;

    if(abs(this->y) > abs(this->x))
        return ret2;
    else
        return ret1;
}

Btn_State APJoy::Read_Button()
{
    return (Btn_State)digitalRead(this->button);
}

void APJoy::Debug(int *x, int *y)
{
    *x = this->x;
    *y = this->y;
}



