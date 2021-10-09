/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Evan Johnson                                              */
/*    Created:      Monday Jan 18 2021                                        */
/*    Description:  A Screen saver for the 2131 robotics club                 */
/*                  to help futer members of the                              */ 
/*                  robotics club so they don't have to figure out screen     */
/*                  selecting on their own like I had to                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/


#include "vex.h"
#include <iostream>
competition Competition;
using namespace vex;

//
//
//
int main() {

    // Set up callbacks for autonomous and driver control periods.
    Competition.autonomous( auton );
    Competition.drivercontrol( driverControl );

    // register events for button selection
    Brain.Screen.pressed( userTouchCallbackPressed );
    Brain.Screen.released( userTouchCallbackReleased );

    // makes the background
    Brain.Screen.setFillColor( vex::color(0x404040) );
    Brain.Screen.setPenColor( vex::color(0x404040) );
    Brain.Screen.drawRectangle( 0, 0, 480, 120 );
    Brain.Screen.setFillColor( vex::color(0x808080) );
    Brain.Screen.setPenColor( vex::color(0x808080) );
    Brain.Screen.drawRectangle( 0, 120, 480, 120 );

    // initial display
    displayButtonControls( 0, false );

    while(1) {
        // Allow other tasks to run

        if( !Competition.isEnabled() )
        Brain.Screen.setFont(fontType::mono40);
        Brain.Screen.setFillColor( vex::color(0x303030) );

        Brain.Screen.setPenColor( vex::color(0xc11f27));
        // Brain.Screen.printAt( 0,  132, "         Team Name        " ); 
        //  Currently the comment on line 51 lies over the print below, you can have it be 2 seperate lines but you will have to re-size most 
        //  things on the brain screen. I believe you can change the text size but im not sure how to currently myself
        Brain.Screen.printAt( 0,  132, "            2131          " );
        // those spaces before and after Team Name and 2131 are not needed but are there to position the text  
        //  you can display anything in that box, for example team name, or team number.
        this_thread::sleep_for(10);
    }
}