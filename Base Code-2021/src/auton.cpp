#include "vex.h"

int autonToRun = -1;

typedef struct _button {
    int    xpos;
    int    ypos;
    int    width;
    int    height;
    bool   state;
    vex::color offColor;
    vex::color onColor;
    const char *label;
} button;

/* If you want to learn more about this screen selector so you can program your own, go to 

https://www.vexforum.com/t/walshbots-autonomous-feature-selector/51534

then open/download the pdf, they have given very helpfull information on this topic
*/


// Button array definitions for each software button. The purpose of each button data structure
//  is defined above.  The array size can be extended, so you can have as many buttons as you 
//  wish as long as it fits on the brain screen.


// when counting buttons for their value, the first buttons value is [0]

// this first color code is the default color or when the button is not selected
//  the second color code is the color that 
button buttons[] = {
    {   30,  30, 60, 60,  false, 0xE00000, 0x0000E0, "Color" },/*0*/
    {  150,  30, 60, 60,  false, 0x303030, 0x0000E0, "Front"},/*1*/
    {  270,  30, 60, 60,  false, 0x303030, 0xE00000, "B-R" },/*2*/
    {  390,  30, 60, 60,  false, 0x303030, 0xE00000, "F-R" },/*3*/
    {   30, 150, 60, 60,  false, 0x303030, 0xC0C0C0, "B-R" },/*4*/
    {  150, 150, 60, 60,  false, 0x303030, 0xC0C0C0, "---" },/*5*/
    {  270, 150, 60, 60,  false, 0x303030, 0xC0C0C0, "---" },/*6*/
    {  390, 150, 60, 60,  false, 0x303030, 0xC0C0C0, "skills" }/*7*/
};

// color codes for the buttons
// 0xE00000 red
// 0x0000E0 blue
// 0x303030 black
// 0xC0C0C0 light grey
// 0x00f044 light green
// 0x1aa142 dark green

//DONT USE SUPER BRIGHT COLORS PEOPLE WILL HATE YOU
//DONT USE Yellow or Pink those are obnoxious when on a robot screen 


//--------------------------------------------------------------//
// The code below is what makes the screen selector work,
//  you should not have to change any of this code so dont
//  worry about it while you are just starting your code

// Below this section is where you will code your autons 
//  and set up the buttons for the robot to register

void displayButtonControls( int index, bool pressed );


int findButton(  int16_t xpos, int16_t ypos ) {
    int nButtons = sizeof(buttons) / sizeof(button);

    for( int index=0;index < nButtons;index++) {
      button *pButton = &buttons[ index ];
      if( xpos < pButton->xpos || xpos > (pButton->xpos + pButton->width) )
        continue;

      if( ypos < pButton->ypos || ypos > (pButton->ypos + pButton->height) )
        continue;

      return(index);
    }
    return (-1);
}

void initButtons() {
    int nButtons = sizeof(buttons) / sizeof(button);

    for( int index=0;index < nButtons;index++) {
      buttons[index].state = false;
    }
}

void userTouchCallbackPressed() {
    int index;
    int xpos = Brain.Screen.xPosition();
    int ypos = Brain.Screen.yPosition();

    if( (index = findButton( xpos, ypos )) >= 0 ) {
      displayButtonControls( index, true );
    }

}


void userTouchCallbackReleased() {
    int index;
    int xpos = Brain.Screen.xPosition();
    int ypos = Brain.Screen.yPosition();

    if( (index = findButton( xpos, ypos )) >= 0 ) {
      // clear all buttons to false, ie. unselected
      //      initButtons(); 

      // now set this one as true
      if( buttons[index].state == true) {
      buttons[index].state = false; }
      else    {
      buttons[index].state = true;}

      // save as auton selection
      autonToRun = index;

      displayButtonControls( index, false );
    }
}


void displayButtonControls( int index, bool pressed ) {
    vex::color c;
    Brain.Screen.setPenColor( vex::color(0xe0e0e0) );

    for(int i=0;i<sizeof(buttons)/sizeof(button);i++) {

      if( buttons[i].state )
        c = buttons[i].onColor;
      else
        c = buttons[i].offColor;

      Brain.Screen.setFillColor( c );

      // button fill
      if( i == index && pressed == true ) {
        Brain.Screen.drawRectangle( buttons[i].xpos, buttons[i].ypos, buttons[i].width, buttons[i].height, c );
      }
      else
        Brain.Screen.drawRectangle( buttons[i].xpos, buttons[i].ypos, buttons[i].width, buttons[i].height );

      // outline
      Brain.Screen.drawRectangle( buttons[i].xpos, buttons[i].ypos, buttons[i].width, buttons[i].height, vex::color::transparent );

// draw label
      if(  buttons[i].label != NULL )
        Brain.Screen.printAt( buttons[i].xpos + 8, buttons[i].ypos + buttons[i].height - 8, buttons[i].label );
    }
}

// End of what you dont need to worry about
//-------------------------------------------------------//





//This is where you can code your teams autons

/*------------------------Front-Blue------------------------*/
void front_Blue( void )
{
  //i have an example of a simple drive auton as an example
  DriveFwd(500, 100);

  left_drive.spinFor(fwd, 100, rotationUnits::deg, 100, velocityUnits::pct, false);
  right_drive.spinFor(reverse, 100, rotationUnits::deg, 100, velocityUnits::pct);

  // to understand lines 170-171 you need to know how the robot reads the code for autons
  //
  // The robot reads the code starting at the top line of code, then reads what is on that,
  //  if there is something on the line that tells it to run multiple lines of code, it will try to run  
  //  then the robot will execute any commands given to it, then it will check to see
  //
  // If a wheel is caught and the motor cannot rotate the program will not continue until the task is completed
  //
  // The false is used at the end of line 170 because the robot is asking the program, 
  //  "Is this the only line I have to run?" and if there is a false at the end, the robot 
  //  will run the next line of code
  //  the default for this is true
  //
  //  At the time of writing this I dont know how to run more than 2 lines at a time, I 
  //   dont know if that is just how it is, or if it's me not knowing
  // 
  // example
  //  left_drive.spinFor(fwd, 100, rotationUnits::deg, 100, velocityUnits::pct, false);
  //  right_drive.spinFor(reverse, 100, rotationUnits::deg, 100, velocityUnits::pct, false);
  //  intake.spinFor(fwd, 100, rotationUnits::deg, 100, velocityUnits::pct)
  //
  // the code will then try to run all other commands given in the auton all at the same time and the program won't work
 

}
  

/*------------------------Back-Blue------------------------*/
void back_Blue( void )
{

}  

/*------------------------Front-Red------------------------*/
void front_Red( void )
{

}


/*------------------------Back-Red------------------------*/
void back_Red( void )
{

} 
  
/*-------------------------skills-------------------------*/
void skillsRun( void )
{

}

// #include "screen_selector.h"
// int i = 0;
// extern int i;
void auton( void ) {

    // initialize capabilities from buttons
    // sets variable names for buttons and allows the screen selector to update the button variables
    bool allianceBlue = buttons[0].state;
    bool front = buttons[1].state;

    bool skills = buttons[7].state;
        // these bool's are what are used to set up the buttons for 
        //  the robot to register their values
        //
        // by setting them to bool's their only values can be true or false.

        // we use those true and false values down below when actually
        //  telling the robot what code to run
  
  

    // By putting an "!" in front of the variable or function, it means not.
    //  For example if i put !master.ButtonUp.pressing(), the 
    //  robot would see it as not pressing ButtonUp

    // if you go back to where i talked about bools these if 
    //  statements are asking is allianceBLue true? if yes/true then do this, 
    //  or if no/false than do this instead.
  if(!allianceBlue)//not blue
  {
    if(!front) //not back
    {
      back_Red();
    }
    else if(front) //is front
    {
      front_Red();
    }

  }
  else if(allianceBlue)//is blue
  {
    if(!front)//not front
    {
      back_Blue();
    }
    else if(front)//is front
    {
      front_Blue();
    }
  }
  else if(skills)//is skills
  {
    skillsRun();
  }
  
}