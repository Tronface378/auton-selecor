#include "vex.h"

void driverControl()
{
  while(true)
  {

    //this is where you write your driver control code

    
    //the code below is actual drive code set up for mecanum wheels
    front_left.spin(fwd, master.Axis3.value() + master.Axis1.value(), pct); //this allows the motor to not only be controlled by Axis3 but also by Axis1
    back_left.spin(fwd, master.Axis3.value() - master.Axis1.value(), pct);
    front_right.spin(fwd, master.Axis3.value() + master.Axis1.value(), pct);
    back_right.spin(fwd, master.Axis3.value() - master.Axis1.value(), pct);

    //the +/- between the two Axis.value() determines the direction is positive and negative on the axis

    /*---------------------- this is the intake controlls ----------------------*/
    if(master.ButtonR1.pressing())
    {
      intake.spin(fwd, 100, velocityUnits::pct);
    }
    else if (!master.ButtonR1.pressing() && intake.velocity(pct) != 0)//the !master.ButtonR1.pressing() is saying when buttonR1 is not pressing run this
    {
      intake.spin(fwd, 0, velocityUnits::pct);
    }
    else
    {
      //empty else so the intakes can be used elsewhere
    }
/*  ---------------------- intake out ---------------------- */
    if(master.ButtonR2.pressing())
    {
      intake.spin(reverse, 100, velocityUnits::pct);
    }
    else if (!master.ButtonR1.pressing() && intake.velocity(pct) != 0)
  {
    intake.spin(reverse, 0, velocityUnits::pct);
  }
  else
    {
      //empty else so the intakes can be used elsewhere
    }
    /*---------------------- this is the roller up controlls ----------------------*/
    if(master.ButtonL1.pressing())
    {
      front_roller.spin(fwd, 100, velocityUnits::pct);
      back_roller.spin(fwd, 100, velocityUnits::pct);
    }
    else if(!master.ButtonL1.pressing() && front_roller.velocity(pct) != 0 && back_roller.velocity(pct) != 0)
    {
      front_roller.spin(fwd, 0, velocityUnits::pct);
      back_roller.spin(fwd, 0, velocityUnits::pct);    
    }
    else
    {
      //empty else so the rollers can be used elsewhere
    }

    /*---------------------- this is the rollers controlls for spitting the ball out the back ----------------------*/
    if(master.ButtonL2.pressing())
    {
      front_roller.spin(forward, 100, velocityUnits::pct);
      back_roller.spin(reverse, 100, velocityUnits::pct);
    }
    else if(!master.ButtonL2.pressing() && front_roller.velocity(pct) != 0 && back_roller.velocity(pct) != 0)
    {
      front_roller.spin(forward, 0, velocityUnits::pct);
      back_roller.spin(reverse, 0, velocityUnits::pct);
    }
    else
    {
      //empty else so the rollers can be used elsewhere
    }
  }
}
