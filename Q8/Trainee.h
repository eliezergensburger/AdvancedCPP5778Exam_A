#pragma once
#include "Device.h"
#include "Aerobic.h"
#include "Power.h"
#include "AerobicPower.h"
#include "Exercise.h"
#include <list>

class Trainee
{
	string name;
	string lastUpdate;
	list<Exercise> exercises;
public:
	Trainee();
	virtual ~Trainee();
};



Trainee::Trainee()
{
}


Trainee::~Trainee()
{
}
