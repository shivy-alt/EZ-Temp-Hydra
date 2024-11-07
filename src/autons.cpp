#include "autons.hpp"
#include "main.h"

int tile_length=24;

void intake_on(){
  intake1.move(-117);
  intake2.move(117);
}
void intake_off(){
  intake1.move(0);
  intake2.move(0);
}

void intake_reverse(){
  intake1.move(117);
  intake2.move(-117);
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
  chassis.pid_drive_set(0.92*tile_length,60,true);
  chassis.pid_wait();
  chassis.pid_drive_set(-tile_length*0.25,110,true);
  chassis.pid_wait();
  pros::delay(500);
  chassis.pid_turn_relative_set(-29.5,100,true);
  chassis.pid_wait();
  chassis.pid_drive_set(0.4*tile_length,110,true);
  chassis.pid_wait();
  pros::delay(500);
  chassis.pid_drive_set(-tile_length*0.75,120,true);
  chassis.pid_wait();
  pros::delay(100);
  chassis.pid_turn_relative_set(-48,120,true);
  chassis.pid_wait();
  chassis.pid_drive_set(0.7*tile_length,100,true);
  chassis.pid_wait();
  
  pros::delay(750);
  chassis.pid_drive_set(-tile_length*1.25,75,true);
  chassis.pid_wait();


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
  chassis.pid_drive_set(0.92*tile_length,60,true);
  chassis.pid_wait();
  chassis.pid_drive_set(-tile_length*0.25,110,true);
  chassis.pid_wait();
  pros::delay(500);
  chassis.pid_turn_relative_set(29.5,100,true);
  chassis.pid_wait();
  chassis.pid_drive_set(0.4*tile_length,110,true);
  chassis.pid_wait();
  pros::delay(500);
  chassis.pid_drive_set(-tile_length*0.75,120,true);
  chassis.pid_wait();
  pros::delay(100);
  chassis.pid_turn_relative_set(48,120,true);
  chassis.pid_wait();
  chassis.pid_drive_set(0.7*tile_length,100,true);
  chassis.pid_wait();
  
  pros::delay(750);
  chassis.pid_drive_set(-tile_length*1.25,75,true);
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
  chassis.pid_drive_set(0.85*tile_length,90,true);
  chassis.pid_wait();
  pros::delay(300);
  chassis.pid_drive_set(-0.5*tile_length,60,true);
  chassis.pid_wait();

  pros::delay(1000);
  intake_off();
  pros::delay(500);

  chassis.pid_turn_relative_set(90,120,true);
  chassis.pid_wait();

  chassis.pid_drive_set(tile_length,110,true);
  chassis.pid_wait();

  chassis.pid_turn_relative_set(-50,120,true);
  chassis.pid_wait();

  hang.set_value(true);

  chassis.pid_drive_set(0.65*tile_length,65,true);
  chassis.pid_wait();

  chassis.pid_turn_relative_set(-147,90,true);
  chassis.pid_wait();

  hang.set_value(false);

  chassis.pid_drive_set(tile_length*2,110,true);
  chassis.pid_wait();

  chassis.pid_turn_relative_set(-35,110,true);
  chassis.pid_wait();

  chassis.pid_drive_set(0.5*tile_length,100,true);
  chassis.pid_wait();

  sweeper.set_value(true);
  

  /*chassis.pid_turn_set(240,127,true);
  chassis.pid_wait();
  chassis.pid_drive_set(1.35*tile_length,90,true);
  chassis.pid_wait();*/
  
  //add ladder touch for quals; add turn towards far positive for elims
  

 
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

chassis.pid_turn_set(90,115);

  //scoring preload onto alliance stake
  intake_on();
  pros::delay(500);
  intake_off();

  //turning mogo clamp towards flat side of mogo and driving back
  chassis.pid_turn_set(210.5,115,true);
  chassis.pid_wait();
  chassis.pid_drive_set(-1.75*tile_length,110,true);
  chassis.pid_wait();

}
void auto_skills(){
    chassis.pid_targets_reset();
    chassis.drive_imu_reset();
    chassis.drive_sensor_reset();
    // chassis.drive_brake_set(MOTOR_BRAKE_HOLD);
    //preload is in the bot
    
    // Step 1: Start intake and move forward to clamp mobile goal
    intake_on();
    pros::delay(100);
    chassis.pid_drive_set(2*tile_length, 90, true);
    chassis.pid_turn_set(-225, 127, true);
    pros::delay(100);
    chassis.pid_drive_set(-0.3*tile_length,100,true);
    mogo_clamp.set_value(true);

    // Step 2: Turn 45 degrees and move backward 2 ft
    chassis.pid_turn_set(-45,127,true);
    pros::delay(100);
    chassis.pid_drive_set(-6*tile_length,100,true);
    intake_on(); // Wait for 1.5 seconds to intake 1 ring
    pros::delay(100);

    // Step 3: Turn 60 degrees and move backward 3 ft
    chassis.pid_turn_set(60,127,true);
    pros::delay(100);
    chassis.pid_drive_set(-1.5*tile_length,100,true);
    intake_on(); // Wait for 1.5 seconds to intake another ring
    pros::delay(100);

    // Step 4: Turn 180 + 45 degrees and move backward 0.75 ft
    chassis.pid_turn_set(225,100,true);
    pros::delay(100);
    chassis.pid_drive_set(4.5*tile_length,100,true);
    intake_on(); // Wait for 1.5 seconds to intake another ring
    pros::delay(100);

    // Step 5: Turn 15 degrees and go backward 2 ft
    chassis.pid_turn_set(15,127,true);
    pros::delay(100);
    chassis.pid_drive_set(-12*tile_length,100,true);
    intake_on(); // Wait for 1.5 seconds to intake another ring
    pros::delay(100);

    // Move forward 0.25 ft
    chassis.pid_drive_set(1.5*tile_length,100,true);
    intake_on(); // Wait for 1.5 seconds to intake another ring
    pros::delay(100);

    // Step 6: Turn 90 + 45 degrees, go backward 0.75 ft
    chassis.pid_turn_set(135,127,true);
    pros::delay(100);
    chassis.pid_drive_set(-4.5*tile_length,100,true);
    intake_on(); // Wait for 1.5 seconds to intake another ring
    pros::delay(100);

    // Step 7: Turn 90 degrees and go back 1.75 ft
    chassis.pid_turn_set(90,127,true);
    pros::delay(100);
    chassis.pid_turn_set(-10.5*tile_length,10,true);
    mogo_clamp.set_value(false); // Unclamp the mobile goal

    // Step 8: Turn 80 degrees and travel 5 ft backward to the other mobile goal
    chassis.pid_turn_set(80,127,true);
    pros::delay(100);
    chassis.pid_drive_set(-2.5*tile_length,100,true);
    mogo_clamp.set_value(true); // Clamp onto the new mobile goal

    // Step 9: Turn 165 degrees and move backward 2 ft
    chassis.pid_turn_set(165,127,true);
    pros::delay(100);
    chassis.pid_drive_set(tile_length,100,true);
    intake_on(); // Wait for 1.5 seconds to intake another ring
    pros::delay(100);

//     // Step 10: Move backward 1 ft
//     move(-12, 100); // Move backward 1 ft
//     intake_on(750); // Wait for 1.5 seconds to intake another ring

//     // Step 11: Turn 90 + 45 degrees and move backward 2 ft
//     turn(135, 100);
//     chassis.PID_wait();
//     move(-24, 100); // Move backward 2 ft
//     intake_on(750); // Wait for 1.5 seconds

//     // Step 12: Turn 60 degrees and move backward 2 ft
//     turn(60, 100);
//     chassis.PID_wait();
//     move(-24, 100); // Move backward 2 ft
//     intake_on(750); // Wait for 1.5 seconds

//     // Step 13: Turn 90 + 45 degrees and move backward 4 ft
//     turn(135, 100);
//     chassis.PID_wait();
//     move(-48, 100); // Move backward 4 ft
//     intake_on(750); // Wait for 1.5 seconds

//     // Step 14: Turn 45 degrees, move backward 2 ft, unclamp, and then move forward 3 ft
//     turn(45, 100);
//     chassis.PID_wait();
//     move(-24, 100); // Move backward 2 ft
//     setMogoClamp(false); // Unclamp the mobile goal
//     move(36, 100); // Move forward 3 ft
  
}