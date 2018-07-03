#pragma once
#include "Aerobic.h"
#include "AerobicPower.h"
#include "Device.h"
#include "Exercise.h"
#include "ExerciseAerobic.h"
#include "ExercisePower.h"
#include "ExercisePowerAerobic.h"
#include "Power.h"
#include "Trainee.h"
#include <iostream>
using namespace std;

class Gym
{
public:
	list<Trainee> trainees;
	list<Device> devices;
	//zil gmor: nigmar li hakoach
	Gym() {}
	virtual ~Gym() {}
};

