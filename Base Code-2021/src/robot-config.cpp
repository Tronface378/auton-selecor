#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

// Used to name your controller to make it easier to code
controller master;


motor front_left(PORT1, gearSetting::ratio18_1);
motor back_left(PORT2, gearSetting::ratio18_1);

motor front_right(PORT3, gearSetting::ratio18_1, false);
motor back_right(PORT4, gearSetting::ratio18_1, false);

motor front_roller(PORT5, gearSetting::ratio18_1);
motor back_roller(PORT6, gearSetting::ratio18_1, false);

motor left_intake(PORT7, gearSetting::ratio18_1);
motor right_intake(PORT8, gearSetting::ratio18_1, false);
//the false is telling the robot that the motor is reversed


// Motor groups make coding autonomous faster and cleaner by allowing you 
//  to use one line of code to run multiple motors
//  I will take these motor groups and put them in a function to simplify the code for auton
//  and I use the motor groups in a function for my auton
motor_group left_drive = motor_group(front_left, back_left);
motor_group right_drive = motor_group(front_right, back_right);

motor_group intake = motor_group(left_intake, right_intake);
// you can find more information on using motor groups on the vex website under tutorials


// In the helpers.cpp file I have an example of how I put motors into a 
//  custom motor group/functions that is easier to make and use, and will save a lot of time and effort

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // Nothing to initialize
}