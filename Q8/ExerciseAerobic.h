#pragma once
#include "Exercise.h"
class ExerciseAerobic: virtual public Exercise
{
	int minutes;
	int pulse;
public:
	ExerciseAerobic(int minutes,int pulse):minutes(minutes),pulse(pulse) {}
	ExerciseAerobic() {}

	int getMinutes() { return minutes; }
	int getPulse() { return pulse; }

	virtual ~ExerciseAerobic() {}
};
