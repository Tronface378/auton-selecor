using namespace vex;

//  these are include guards, they make sure you dont have an infinitely large file
#ifndef DRIVER_CONTROL_H
#define DRIVER_CONTROL_H
//  it doesn't matter how you set up the define because you can call them anything
//  this is just how I prefer to name them

//if you were to put #include "driver-control.h" inside driver-control.h, it would expand infinitely if you didnt have those


//this is where you go to declare functions/voids so they can be used elsewhere in your program

extern void driverControl();

#endif