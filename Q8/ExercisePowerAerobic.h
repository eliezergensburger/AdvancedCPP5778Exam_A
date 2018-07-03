#pragma once
#include "Power.h"
#include "Aerobic.h"

class ExercisePowerAerobic :public Power, public Aerobic
{
public:
	ExercisePowerAerobic():Power(),Aerobic() {}
	virtual ~ExercisePowerAerobic() {}
};
