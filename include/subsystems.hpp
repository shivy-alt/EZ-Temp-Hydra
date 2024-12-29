#pragma once

#include "api.h"
#include "pros/motor_group.hpp"
#include "pros/motors.h"
#include "pros/motors.hpp"

// Your motors, sensors, etc. should go here.  Below are examples

// inline pros::Motor intake(1);
// inline pros::adi::DigitalIn limit_switch('A');
inline pros::Motor intake1(20,pros::MotorGearset::blue);
inline pros::adi::DigitalOut mogo_clamp(2);
inline pros::Controller control(pros::E_CONTROLLER_MASTER);
inline pros::adi::DigitalOut sweeper(1);

inline pros::Rotation ldb_sensor(9);
inline pros::Motor ldb_motor1(10); 



inline pros::Motor ldb_motor2(8);



