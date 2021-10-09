#include "vex.h"

// 'double' is a fundamental data type built into the compiler and 
//   used to define numeric variables holding numbers with decimal points. 
//   'double' can be used for whole numbers as well

// This is how you create a function for autonomous. this makes creating 
//  autons much easier

// to create a function you need to give it a name, then decide if you want it to run 
//  continuously until told to stop, or if you want it to run for a certain distance.
//  this can also be used to set velocity or other variables


void DriveFwd(double dist, double vel)
{
 
  left_drive.spinFor(fwd, dist, rotationUnits::deg, vel, velocityUnits::pct);
  right_drive.spinFor(fwd, dist, rotationUnits::deg, vel, velocityUnits::pct);
}
// Now when you are in the autonomous file, you can use the code
//  DriveFwd(1000, 100);
//  to make the robot drive forward for 1000 degrees of motor rotation at 100% velocity

// You can use other units for rotation and velocity, but they are my personal preference 










// This is how you can use a function to run continuously or until the motors are told 
//  to stop by another function
void intakeIn()
{
  intake.spin(fwd, 100, velocityUnits::pct);
}

void intakeOff()
{
  intake.stop(coast);
}






// Once you have your helpers and functions completed go to the 'helpers.h' file