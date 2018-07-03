#pragma once
#include "Exercise.h"
#include <iostream>
using namespace std;

class ExerciseAerobic: virtual public Exercise
{
protected:
	int minutes;
	int pulse;
public:
	ExerciseAerobic() {}
	ExerciseAerobic(const Device& d,int minutes,int pulse)
		:Exercise(d),minutes(minutes),pulse(pulse) {}

	int getMinutes()const { return minutes; }
	int getPulse()const { return pulse; }
	
	void setMinutes(int val) {  minutes = val; }
	void setPulse(int val) {  pulse = val; }

	void  training()const override
	{
		cout << "duration " << minutes << " with pulse rate " << pulse << endl;
	}

	void toString()const override
	{
		Exercise::toString();
		cout << "MusclesGroup:  " << (reinterpret_cast<const Aerobic *>(device))->getCalories() << endl;
		cout << "Minutes:      " << getMinutes() << endl;
		cout << "Pulse Rate:   " << getPulse() << endl;
	}

	virtual ~ExerciseAerobic() {}
};
