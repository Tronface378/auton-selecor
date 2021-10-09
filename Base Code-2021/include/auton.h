using namespace vex;

//  below are include guards, they make sure you dont have an infinitely large file
#ifndef H_AUTON_FILE
#define H_AUTON_FILE
//  it doesn't matter how you set up the define because you can call them anything
//  this is just how I prefer to name them

//  if you were to put #include "driver-control.h" inside driver-control.h, it would expand infinitely if you didnt have those


//  this is where you go to declare functions/voids so they can be used elsewhere in your program

extern int autonToRun;

extern bool frontBlue;
extern bool backBlue;
extern bool frontRed;
extern bool backRed;
extern bool allianceBlue;

extern void userTouchCallbackPressed();
extern void userTouchCallbackReleased();
extern void displayButtonControls( int index, bool pressed);

extern void auton();

#endif