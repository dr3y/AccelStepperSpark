// Demo_Random.ino
// -*- mode: C++ -*-
//
// Make a single stepper perform random changes in speed, position and acceleration
//
// Copyright (C) 2009 Mike McCauley

#include "AccelStepperSpark/AccelStepperSpark.h"

// Define a stepper and the pins it will use
AccelStepper stepper; // Defaults to AccelStepper::FULL4WIRE (4 pins) on D2, D3, D4, D5

void setup()
{  
}

void loop()
{
    if (stepper.distanceToGo() == 0)
    {
	// Random change to speed, position and acceleration
	// Make sure we dont get 0 speed or accelerations
	delay(1000);
	stepper.moveTo(rand() % 200);
	stepper.setMaxSpeed((rand() % 200) + 1);
	stepper.setAcceleration((rand() % 200) + 1);
    }
    stepper.run();
}
