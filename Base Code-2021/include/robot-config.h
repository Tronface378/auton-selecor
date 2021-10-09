using namespace vex;

//these are include guards, they make sure you dont have an infinitely large file
#ifndef H_ROBOT_CONFIGFILE
#define H_ROBOT_CONFIGFILE
//it doesn't matter how you set up the define because you can call them anything
//  this is just how I prefer to name them

//if you were to put "#include driver-control.h" inside driver-control.h, it would expand infinitely if you didnt have those


//this is where you go to declare functions/voids/robot-configs so they can be used elsewhere in your program

extern brain Brain;

extern motor front_left;
extern motor back_left;

extern motor front_right;
extern motor back_right;

extern motor front_roller;
extern motor back_roller;

extern motor left_intake;
extern motor right_intake;

extern motor_group left_drive;
extern motor_group right_drive;

extern motor_group intake;

extern controller master;

extern competition Competition;

extern void vexcodeInit(void);

#endif