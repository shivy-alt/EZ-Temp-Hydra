#include "main.h"

#pragma once
#include "api.h"

inline ez::PID liftPID{0.04, 0, .1, 0, "Lift"};

void set_lift(int input);
extern bool stop_on_detect; // Declare stop_on_detect here


void lift_task();
void lift_wait();