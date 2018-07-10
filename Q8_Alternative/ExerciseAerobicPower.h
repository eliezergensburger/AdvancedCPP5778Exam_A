#pragma once
#include "Exercise.h"
#include "ExerciseAerobic.h"
#include "ExercisePower.h"
#include "DeviceAerobicPower.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class ExerciseAerobicPower :public ExercisePower, public ExerciseAerobic
{
protected:
	const DeviceAerobicPower* device;
public:
	ExerciseAerobicPower(const DeviceAerobicPower& apd, int s, int r, int m, int p) :
		ExercisePower(apd, s, r), ExerciseAerobic(apd, m, p),device(&apd)
	{}

	ExerciseAerobicPower() :ExercisePower(), ExerciseAerobic() {}

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

	virtual ~ExerciseAerobicPower() {}
};
