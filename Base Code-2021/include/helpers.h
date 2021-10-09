using namespace vex;

//  below are include guards, they make sure you dont have an infinitely large file
#ifndef H_HELPERSFILE
#define H_HELPERSFILE
//  it doesn't matter how you set up the define because you can call them anything
//  this is just how I prefer to name them

//  if you were to put #include "driver-control.h" inside driver-control.h, it would expand infinitely if you didnt have those


// This is where you go to declare functions/voids so they can be used elsewhere 
//  in your program

// Make sure when declaring your functions, that you also put any variables used 
//  to run the function

extern void DriveFwd(double dist, double vel);
extern void intakeIn();
extern void intakeOff();


#endif