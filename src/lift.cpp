#include "main.h"


/*void set_lift(int input) {
  ldb_motor1.move(input);
  ldb_motor2.move(-input);
}


void lift_task() {
    pros::delay(2000);  // Optional delay for task initialization
    while (true) {
        double scaled_position = ldb_sensor.get_position(); 
        set_lift(liftPID.compute(scaled_position)); 

        pros::delay(ez::util::DELAY_TIME);  // Maintain consistent loop timing
    }
}

//auton
void lift_wait() {
  while (liftPID.exit_condition({ldb_motor1,ldb_motor2}, true) == ez::RUNNING) {
    pros::delay(ez::util::DELAY_TIME);
  }
}*/
