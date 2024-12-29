#include "autons.hpp"
#include "main.h"

int tile_length=24;

void intake_on(){
  intake1.move(-117);
  
}
void intake_off(){
  intake1.move(0);
  
}

void intake_reverse(){
  intake1.move(117);

}




/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

// These are out of 127
const int DRIVE_SPEED = 110;
const int TURN_SPEED = 90;
const int SWING_SPEED = 90;

///
// Constants
///
void default_constants() {
  chassis.pid_heading_constants_set(11, 0, 20);
  chassis.pid_drive_constants_set(20, 0, 100);
  chassis.pid_turn_constants_set(3, 0.05, 20, 15);
  chassis.pid_swing_constants_set(6, 0, 65);

  chassis.pid_turn_exit_condition_set(80, 3, 250, 7, 500, 500);
  chassis.pid_swing_exit_condition_set(80, 3, 250, 7, 500, 500);
  chassis.pid_drive_exit_condition_set(80, 1, 250, 3, 500, 500);

  chassis.pid_turn_chain_constant_set(3);
  chassis.pid_swing_chain_constant_set(5_deg);
  chassis.pid_drive_chain_constant_set(3_in);

  chassis.slew_drive_constants_set(7_in, 80);
}

///
// Drive Example
///
void corner_clear_func(){
  sweeper.set_value(true);
  chassis.pid_turn_relative_set(45,120,true);
  sweeper.set_value(false);
}


// . . .
// Make your own autonomous functions here!
// . . .
void Four_ring_auto_red_side(){
  chassis.pid_drive_set(-0.8*tile_length,120,true);
  chassis.pid_wait();
  chassis.pid_turn_set(29,127,true);
  chassis.pid_wait();
  chassis.pid_drive_set(-0.5*tile_length,90,true);
  chassis.pid_wait();
  mogo_clamp.set_value(true);


  intake_on();
  pros::delay(200);
  chassis.pid_turn_set(148,120,true);
  chassis.pid_wait();
  pros::delay(300);

  intake_on();
  chassis.pid_drive_set(0.95*tile_length,60,true);
  chassis.pid_wait();
  chassis.pid_drive_set(-tile_length*0.28,110,true);
  chassis.pid_wait();
  pros::delay(500);
  chassis.pid_turn_relative_set(-28.5,100,true);
  chassis.pid_wait();
  chassis.pid_drive_set(0.43*tile_length,110,true);
  chassis.pid_wait();
  pros::delay(500);
  chassis.pid_drive_set(-tile_length*0.75,120,true);
  chassis.pid_wait();
  pros::delay(100);
  chassis.pid_turn_relative_set(-48,120,true);
  chassis.pid_wait();
  chassis.pid_drive_set(0.7*tile_length,100,true);
  chassis.pid_wait();
  
  pros::delay(500);
  chassis.pid_drive_set(-tile_length*1.25,75,true);
  chassis.pid_wait();

  /*chassis.pid_turn_relative_set(-190,100,true);
  chassis.pid_wait();*/


}

void Four_ring_auto_blue_side(){
chassis.pid_drive_set(-0.8*tile_length,120,true);
  chassis.pid_wait();
  chassis.pid_turn_set(-29,127,true);
  chassis.pid_wait();
  chassis.pid_drive_set(-0.5*tile_length,90,true);
  chassis.pid_wait();
  mogo_clamp.set_value(true);


  intake_on();
  pros::delay(200);
  chassis.pid_turn_set(-148,120,true);
  chassis.pid_wait();
  pros::delay(300);

  intake_on();
  chassis.pid_drive_set(1.1*tile_length,60,true);
  chassis.pid_wait();
  chassis.pid_drive_set(-tile_length*0.28,110,true);
  chassis.pid_wait();
  pros::delay(500);
  chassis.pid_turn_relative_set(26,100,true);
  chassis.pid_wait();
  chassis.pid_drive_set(0.47*tile_length,110,true);
  chassis.pid_wait();
  pros::delay(500);
  chassis.pid_drive_set(-tile_length*0.75,120,true);
  chassis.pid_wait();
  pros::delay(100);
  chassis.pid_turn_relative_set(48,120,true);
  chassis.pid_wait();
  chassis.pid_drive_set(0.7*tile_length,100,true);
  chassis.pid_wait();
  
  pros::delay(500);
  chassis.pid_drive_set(-tile_length*1.325,75,true);
  chassis.pid_wait();
}
void Two_Ring_Corner_Clear_Auto_RED(){
  chassis.pid_drive_set(-0.8*tile_length,120,true);
  chassis.pid_wait();
  chassis.pid_turn_set(-30.5,127,true);
  chassis.pid_wait();
  chassis.pid_drive_set(-0.5*tile_length,100,true);
  chassis.pid_wait();
  mogo_clamp.set_value(true);
  pros::delay(500);
  intake_on();
  pros::delay(1000);
  intake_off();

  chassis.pid_turn_set(-105,120,true);
  chassis.pid_wait();
  intake_on();
  pros::delay(100);
  chassis.pid_wait();
  pros::delay(300);
  chassis.pid_drive_set(0.7*tile_length,90,true);
  chassis.pid_wait();
  pros::delay(300);
  chassis.pid_drive_set(-0.5*tile_length,60,true);
  chassis.pid_wait();

  pros::delay(1000);
  intake_off();
  pros::delay(500);

  chassis.pid_turn_relative_set(90,120,true);
  chassis.pid_wait();

  chassis.pid_drive_set(1.05*tile_length,110,true);
  chassis.pid_wait();

  chassis.pid_turn_relative_set(-50,120,true);
  chassis.pid_wait();

  sweeper.set_value(true);

  chassis.pid_drive_set(0.65*tile_length,65,true);
  chassis.pid_wait();

  chassis.pid_turn_relative_set(-160,90,true);
  chassis.pid_wait();

  sweeper.set_value(false);

  chassis.pid_drive_set(tile_length*2,110,true);
  chassis.pid_wait();

  /*chassis.pid_turn_relative_set(-35,110,true);
  chassis.pid_wait();

  chassis.pid_drive_set(0.5*tile_length,100,true);
  chassis.pid_wait();*/

 
  

  chassis.pid_turn_set(240,127,true);
  chassis.pid_wait();
  chassis.pid_drive_set(1.35*tile_length,90,true);
  chassis.pid_wait();
  
  //add ladder touch for quals; add turn towards far positive for elims
  

 
}
void Two_Ring_Corner_Clear_Auto_BLUE(){
  chassis.pid_drive_set(-0.8*tile_length,120,true);
  chassis.pid_wait();
  chassis.pid_turn_set(30.5,127,true);
  chassis.pid_wait();
  chassis.pid_drive_set(-0.5*tile_length,100,true);
  chassis.pid_wait();
  mogo_clamp.set_value(true);
  pros::delay(500);
  intake_on();

  
  pros::delay(200);
  

  chassis.pid_turn_set(105,120,true);
  chassis.pid_wait();
  intake_on();
  pros::delay(100);
  chassis.pid_wait();
  pros::delay(300);
  chassis.pid_drive_set(0.7*tile_length,90,true);
  chassis.pid_wait();
  pros::delay(300);
  chassis.pid_drive_set(-0.5*tile_length,60,true);
  chassis.pid_wait();

  pros::delay(1000);
  intake_off();
  pros::delay(500);

  chassis.pid_turn_relative_set(-90,120,true);
  chassis.pid_wait();

  chassis.pid_drive_set(tile_length,110,true);
  chassis.pid_wait();

  chassis.pid_turn_relative_set(40,120,true);
  chassis.pid_wait();

  sweeper.set_value(true);

  chassis.pid_drive_set(0.65*tile_length,65,true);
  chassis.pid_wait();

  chassis.pid_turn_relative_set(-180,90,true);
  chassis.pid_wait();

  sweeper.set_value(false);

  chassis.pid_drive_set(tile_length*2,110,true);
  chassis.pid_wait();

  chassis.pid_turn_relative_set(-35,110,true);
  chassis.pid_wait();

  chassis.pid_drive_set(0.25*tile_length,100,true);
  chassis.pid_wait();



  
  

  /*chassis.pid_turn_set(240,127,true);
  chassis.pid_wait();
  chassis.pid_drive_set(1.35*tile_length,90,true);
  chassis.pid_wait();*/
  
  //add ladder touch for quals; add turn towards far positive for elims
  

 
}
void positive_side_goal_rush(){

}



void corner_clear(){
  //scoring preload onto alliance stake
  intake_on();
  pros::delay(500);
  intake_off();

  //turning towards the positive corner
  chassis.pid_turn_set(-90,127,true);
  chassis.pid_wait();

  //driving towards positive corner
  chassis.pid_drive_set(2.5*tile_length,115,true);
  chassis.pid_wait();

  //ramming into corner to clear it
  intake_on();
  pros::delay(500);
  corner_clear_func();
  pros::delay(250);
  chassis.pid_turn_set(-10,127,true);
  chassis.pid_wait();
  


}
void solo_winpoint(){
  chassis.pid_drive_set(-0.7*tile_length,100,true);
  chassis.pid_wait();
  chassis.pid_turn_relative_set(89,100,true);
  chassis.pid_wait();
  chassis.pid_drive_set(-0.37*tile_length,100,true);
  chassis.pid_wait();
  intake1.move(-127);
  
  pros::delay(700);
  intake1.move(0);
  
  chassis.pid_drive_set(0.375*tile_length,100,true);
  chassis.pid_wait();
  chassis.pid_turn_relative_set(144,120,true);
  chassis.pid_wait();
  chassis.pid_drive_set(-1.7*tile_length,65,true);
  chassis.pid_wait();
  pros::delay(500);
  mogo_clamp.set_value(true);
  pros::delay(300);
  chassis.pid_turn_relative_set(-190,100,true);
  chassis.pid_wait();

  intake_on();
  chassis.pid_drive_set(1.25*tile_length,60,true);
  chassis.pid_wait();
  chassis.pid_drive_set(-tile_length*0.25,110,true);
  chassis.pid_wait();
  pros::delay(500);
  chassis.pid_turn_relative_set(-25,100,true);
  chassis.pid_wait();
  chassis.pid_drive_set(0.7*tile_length,110,true);
  chassis.pid_wait();
  pros::delay(500);
  chassis.pid_drive_set(-tile_length*0.75,120,true);
  chassis.pid_wait();
  pros::delay(100);
  chassis.pid_turn_relative_set(-52.5,120,true);
  chassis.pid_wait();
  chassis.pid_drive_set(0.7*tile_length,100,true);
  chassis.pid_wait();
  
  pros::delay(700);
  chassis.pid_drive_set(-tile_length*1,75,true);
  chassis.pid_wait();
  chassis.pid_turn_relative_set(25,100,true);
  chassis.pid_drive_set(-0.5*tile_length,100,true);
  chassis.pid_wait();

  


}
void auto_skills(){
 //scoring preload onto alliance stake
    intake_on();
    pros::delay(500);

    //going for first mogo + scoring 6 rings
    chassis.pid_drive_set(0.6*tile_length, 100, true);
    chassis.pid_wait();
    pros::delay(350);
    chassis.pid_turn_set(-90, 115, true);
    pros::delay(500);
    chassis.pid_drive_set(-0.65*tile_length,100,true);
    chassis.pid_wait();
    mogo_clamp.set_value(true);
    pros::delay(250);          

    chassis.pid_turn_relative_set(139,115,true);
    chassis.pid_wait();
    intake_on();
    chassis.pid_drive_set(1.55*tile_length,110,true);
    chassis.pid_wait();
    chassis.pid_turn_relative_set(-25,100,true);
    chassis.pid_wait();
    chassis.pid_drive_set(0.8*tile_length,65,true);
    chassis.pid_wait();
    pros::delay(500);

    chassis.pid_turn_set(171,120,true);
    chassis.pid_wait();

    chassis.pid_drive_set(1.55*tile_length,115,true);
    chassis.pid_wait();
    pros::delay(350);
    chassis.pid_drive_set(-0.6*tile_length,100,true);
    chassis.pid_wait();
    chassis.pid_turn_relative_set(28,80,true);
    chassis.pid_wait();
    chassis.pid_drive_set(0.9*tile_length,80,true);
    chassis.pid_wait();
    chassis.pid_turn_relative_set(-10,100,true);
    chassis.pid_wait();
    chassis.pid_drive_set(0.43*tile_length,100,true);
    chassis.pid_wait();
    chassis.pid_drive_set(-0.6*tile_length,100,true);
    chassis.pid_wait();
    intake_on();
    chassis.pid_turn_relative_set(117,100,true);
    chassis.pid_wait();
    chassis.pid_drive_set(1.15*tile_length,100,true);
    chassis.pid_wait();
    pros::delay(500);
    chassis.pid_turn_relative_set(10,100,true);
    chassis.pid_wait();
    chassis.pid_drive_set(-1.8*tile_length,60,true);
    chassis.pid_wait();
    mogo_clamp.set_value(false);
    pros::delay(300);
    chassis.pid_wait();
    
    //drive to other side and clamp onto mogo #2
    chassis.pid_drive_set(0.53*tile_length, 180, true);
    pros::delay(500);
    chassis.pid_turn_relative_set(135, 90, true);
    pros::delay(300);
    chassis.pid_drive_set(-2.9*tile_length, 160, true);
    pros::delay(500);
    chassis.pid_wait();
    mogo_clamp.set_value(true);
    chassis.pid_wait();
    pros::delay(500);

    //score ring #1 into mogo #2
    chassis.pid_turn_relative_set(-140,115,true);
    chassis.pid_wait();
    intake_on();
    chassis.pid_drive_set(1.55*tile_length,110,true);
    chassis.pid_wait();

    //score ring #2 onto mogo #2
    chassis.pid_turn_relative_set(30,100,true);
    chassis.pid_wait();
    chassis.pid_drive_set(0.8*tile_length,65,true);
    chassis.pid_wait();

    //score ring #3 onto mogo #2
    chassis.pid_turn_relative_set(-175,100,true);
    pros::delay(500);
    chassis.pid_wait();
    pros::delay(500);
    chassis.pid_drive_set(1.57*tile_length,115,true);
    chassis.pid_wait();
    pros::delay(350);

    //score ring #4 into mogo #2
    chassis.pid_drive_set(-0.61*tile_length,100,true);
    chassis.pid_wait();
    chassis.pid_turn_relative_set(28,80,true);
    chassis.pid_wait();
    chassis.pid_drive_set(1*tile_length,80,true);
    chassis.pid_wait();
    
    //score ring #5 onto mogo #2
    chassis.pid_drive_set(-0.61*tile_length, 100, true);
    chassis.pid_wait();
    chassis.pid_turn_relative_set(-30,100,true);
    chassis.pid_wait();
    chassis.pid_drive_set(1.14*tile_length,100,true);
    chassis.pid_wait();
    intake_on();

    //score ring #6 onto mogo #2
    chassis.pid_turn_relative_set(-125,100,true);
    chassis.pid_wait();
    chassis.pid_drive_set(1.5*tile_length,100,true);
    chassis.pid_wait();
    pros::delay(500);

    //score mogo #2 into corner
    chassis.pid_turn_relative_set(10,100,true);
    chassis.pid_wait();
    chassis.pid_drive_set(-2*tile_length,60,true);
    chassis.pid_wait();
    mogo_clamp.set_value(false);
    pros::delay(300);

    //clamp onto mogo #3
    // chassis.pid_drive_set(0.9*tile_length, 180, true);
    // chassis.pid_wait();
    // chassis.pid_turn_relative_set(135, 100, true);
    // pros::delay(500);
    // chassis.pid_drive_set(-3*tile_length, 180, true);
    // chassis.pid_wait();
    // pros::delay(500);
    // chassis.pid_turn_relative_set(30, 100, true);
    // pros::delay(500);
    // chassis.pid_drive_set(0.2*tile_length, 100, true);
    // pros::delay(500);
    // chassis.pid_wait();
    // mogo_clamp.set_value(true);
    // pros::delay(500);
    // chassis.pid_wait();


    // //score mogo #3 into corner
    // chassis.pid_drive_set(0.6*tile_length, 100, true);
    // pros::delay(500);
    // chassis.pid_turn_relative_set(180, 100, true);
    // pros::delay(500);
    // chassis.pid_drive_set(1*tile_length, 180, true);
    // pros::delay(500);
    // corner_clear_func();
    // chassis.pid_turn_relative_set(-30, 100, true);
    // mogo_clamp.set_value(false);
    // pros::delay(500);
    // chassis.pid_wait();

    //hang
    chassis.pid_drive_set(3*tile_length, 200, true);
    sweeper.set_value(true);
    pros::delay(500);
    chassis.pid_drive_set(-0.25*tile_length, 200, true);

    // //score mogo #4 in corner
    // chassis.pid_drive_set(0.55*tile_length, 200, true);
    // pros::delay(500);
    // chassis.pid_wait();
    // chassis.pid_turn_relative_set(132, 100, true);
    // pros::delay(500);
    // chassis.pid_drive_set(-3.1*tile_length, 200, true);
    // pros::delay(500);
    // chassis.pid_wait();
    // mogo_clamp.set_value(true);
    // pros::delay(500);
    // chassis.pid_wait();
    // chassis.pid_turn_relative_set(-30, 100, true);
    // pros::delay(500);
    // chassis.pid_drive_set(-2*tile_length, 200, true);
    // pros::delay(500);
    // chassis.pid_wait();
    // mogo_clamp.set_value(false);
    // pros::delay(500);

//     //hang
//     chassis.pid_turn_relative_set(-45, 100, true);
//     pros::delay(500);
//     hang.set_value(true);
//     pros::delay(500);
//     chassis.pid_drive_set(2.8*tile_length, 200, true);
//     pros::delay(500);
//     chassis.pid_drive_set(-0.3*tile_length, 200, true);
//     pros::delay(500);

} 

//blah