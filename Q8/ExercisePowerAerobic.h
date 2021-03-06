#pragma once
#include "ExercisePower.h"
#include "ExerciseAerobic.h"
#include "AerobicPowerDevice.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class ExercisePowerAerobic :public ExercisePower, public ExerciseAerobic
{
protected:
	const AerobicPowerDevice* device;
public:
	ExercisePowerAerobic(const AerobicPowerDevice& apd, int s, int r, int m, int p) :
		 ExercisePower(apd,s,r), ExerciseAerobic(apd,m,p), device(&apd)
	{
		setSets(s);
		setReps(r);
		setMinutes(m);
		setPulse(p);
	}

	ExercisePowerAerobic() :ExercisePower(), ExerciseAerobic() {}

	string toString()const override
	{
		string result = "";

		result += ExercisePower::toString();
		result += "\n";
		result += ExerciseAerobic::toString();

		return result;

	}
	const Device * getDevice() const override
	{
		return device;
	}

	virtual ~ExercisePowerAerobic() {}
};
