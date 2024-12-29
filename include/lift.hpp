

#pragma once
#include "EZ-Template/PID.hpp"
#include "api.h"

inline ez::PID liftPID{4, 0, .1, 0, "Lift"};

void set_lift(int input);
extern bool stop_on_detect; // Declare stop_on_detect here


void lift_task();
void lift_wait();