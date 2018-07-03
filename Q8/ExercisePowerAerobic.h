#pragma once
#include "ExercisePower.h"
#include "ExerciseAerobic.h"
#include <iostream>
using namespace std;

class ExercisePowerAerobic :public ExercisePower, public ExerciseAerobic
{
public:
	ExercisePowerAerobic(const Device& d, int s, int r, int m, int p) :
		Exercise(d), ExercisePower(), ExerciseAerobic() 
	{
		setSets(s);
		setReps(r);
		setMinutes(m);
		setPulse(p);
	}

	ExercisePowerAerobic():ExercisePower(), ExerciseAerobic() {}

	void training() const override
	{
		ExercisePower::training();
		ExerciseAerobic::training();
	}

	void toString()const override
	{
		//there is a bug here : name and serial will be printed twice
		ExercisePower::toString();
		ExerciseAerobic::toString();
	}

	virtual ~ExercisePowerAerobic() {}
};
