// Demo_Overshoot.ino
// -*- mode: C++ -*-
//
// Check overshoot handling
// which sets a new target position and then waits until the stepper has 
// achieved it. This is used for testing the handling of overshoots
//
// Copyright (C) 2009 Mike McCauley

#include "AccelStepperSpark/AccelStepperSpark.h"

// Define a stepper and the pins it will use
AccelStepper stepper; // Defaults to AccelStepper::FULL4WIRE (4 pins) on D2, D3, D4, D5

void setup()
{  
  stepper.setMaxSpeed(150);
  stepper.setAcceleration(100);
}

void loop()
{    
  stepper.moveTo(500);
  while (stepper.currentPosition() != 300) // Full speed up to 300
    stepper.run();
  stepper.runToNewPosition(0); // Cause an overshoot then back to 0
}
