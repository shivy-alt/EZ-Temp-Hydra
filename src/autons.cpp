#include "main.h"

int tile_length=24;
inline pros::Motor intake1(20,pros::MotorGearset::blue);
inline pros::Motor intake2(12,pros::MotorGearset::blue);
inline pros::adi::DigitalOut mogo_clamp(8);

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

  chassis.pid_turn_exit_condition_set(80_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_swing_exit_condition_set(80_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_drive_exit_condition_set(80_ms, 1_in, 250_ms, 3_in, 500_ms, 500_ms);

  chassis.pid_turn_chain_constant_set(3_deg);
  chassis.pid_swing_chain_constant_set(5_deg);
  chassis.pid_drive_chain_constant_set(3_in);

  chassis.slew_drive_constants_set(7_in, 80);
}

///
// Drive Example
///



// . . .
// Make your own autonomous functions here!
// . . .
void Four_Ring_Auto(){

  chassis.pid_drive_set(-0.8*tile_length,120,true);
  chassis.pid_wait();
  chassis.pid_turn_set(-30.5,127,true);
  chassis.pid_wait();
  chassis.pid_drive_set(-0.5*tile_length,100,true);
  chassis.pid_wait();
  mogo_clamp.set_value(true);
  pros::delay(500);
  intake1.move(-120);
  intake2.move(120);
  pros::delay(1000);
  intake1.move(0);
  intake2.move(0);

  chassis.pid_turn_set(-105,120,true);
  chassis.pid_wait();
  intake1.move(-120);
  intake2.move(120);
  pros::delay(100);
  chassis.pid_wait();
  pros::delay(300);
  chassis.pid_drive_set(0.85*tile_length,90,true);
  chassis.pid_wait();
  pros::delay(300);
  chassis.pid_drive_set(-0.5*tile_length,30,true);
  chassis.pid_wait();

  pros::delay(1500);
  intake1.move(0);
  intake2.move(0);
  pros::delay(500);

  //add other two rings + ladder contact

  



}
void Two_Ring_Auto(){
  chassis.pid_drive_set(-0.8*tile_length,120,true);
  chassis.pid_wait();
  chassis.pid_turn_set(30.5,127,true);
  chassis.pid_wait();
  chassis.pid_drive_set(-0.5*tile_length,100,true);
  chassis.pid_wait();
  mogo_clamp.set_value(true);
  pros::delay(500);
  intake1.move(-120);
  intake2.move(120);
  pros::delay(1000);
  intake1.move(0);
  intake2.move(0);

  chassis.pid_turn_set(105,120,true);
  chassis.pid_wait();
  intake1.move(-120);
  intake2.move(120);
  pros::delay(100);
  chassis.pid_wait();
  pros::delay(300);
  chassis.pid_drive_set(0.85*tile_length,90,true);
  chassis.pid_wait();
  pros::delay(300);
  chassis.pid_drive_set(-0.5*tile_length,60,true);
  chassis.pid_wait();

  pros::delay(1000);
  intake1.move(0);
  intake2.move(0);
  pros::delay(500);

  chassis.pid_turn_set(-240,127,true);
  chassis.pid_wait();
  chassis.pid_drive_set(1.35*tile_length,90,true);
  chassis.pid_wait();
  
  //add ladder touch for quals; add turn towards far positive for elims
  

 
}



void auton_skills(){
    
  intake1.move(-127);
  intake2.move(127);
  pros::delay(500);
  chassis.pid_turn_set(- 25,127,true);
  chassis.pid_wait();
  chassis.pid_drive_set(0.5*tile_length,110,true);
  chassis.pid_wait();
  pros::delay(750);
  intake1.move(0);
  intake2.move(0);

}

void corner_clear(){

}

void solo_winpoint(){

}
