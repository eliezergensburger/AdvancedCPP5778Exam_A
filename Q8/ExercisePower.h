#pragma once
#include "Exercise.h"
class ExercisePower:  virtual public Exercise
{
	int sets;
	int reps; //repeat
public:
	ExercisePower() {}
	ExercisePower(int sets, int reps) :sets(sets), reps(reps) {}

	int getSets() { return sets; }
	int getReps() { return reps; }

	virtual ~ExercisePower() {}
};