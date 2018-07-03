#pragma once
#include "Exercise.h"
#include <iostream>
using namespace std;

class ExercisePower:  virtual public Exercise
{
protected:
	int sets;
	int reps; //repeat
public:
	ExercisePower() {}
	ExercisePower(const Device& d,int sets, int reps) 
		:Exercise(d),sets(sets), reps(reps) {}

	int getSets() const{ return sets; }
	int getReps() const { return reps; }
	
	void setSets(int val) { sets = val; }
	void setReps(int val) {  reps = val; }


	void   training() const override 
	{ 
		cout << "doing " << sets << " in " << reps << " repetitions" << endl; 
	}
	
	void toString()const override
	{
		Exercise::toString();
		cout << "Sets :         " << getSets() << endl;
		cout << "Repetitions:   " << getReps() << endl;

	}

	virtual ~ExercisePower() {}
};