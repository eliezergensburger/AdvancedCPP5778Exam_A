#pragma once
#include "Exercise.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class ExerciseAerobic: virtual public Exercise
{
protected:
	int minutes;
	int pulse;
	const AerobicDevice* device;

public:
	ExerciseAerobic() {}
	ExerciseAerobic(const AerobicDevice &ad,int minutes,int pulse)
		:device(&ad),minutes(minutes),pulse(pulse) {}

	int getMinutes()const { return minutes; }
	int getPulse()const { return pulse; }
	
	void setMinutes(int val) {  minutes = val; }
	void setPulse(int val) {  pulse = val; }

	const Device * getDevice() const override
	{
		return device;
	}

	string toString()const override
	{
		stringstream result;

		result << "Calories:  "<< device->getCalories()<< "\n"; 
		result << "Minutes:      "<< getMinutes()<< "\n"; 
		result << "Pulse Rate:   "<< getPulse()<< "\n";

		return result.str();
	}

	virtual ~ExerciseAerobic() {}
};
