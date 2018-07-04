#pragma once
#include "Exercise.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class ExercisePower:  virtual public Exercise
{
protected:
	int sets;
	int reps; //repeat
	const PowerDevice* device;
public:
	ExercisePower() {}
	ExercisePower(const PowerDevice& pd,int sets, int reps)
		:device(&pd),sets(sets), reps(reps) {}

	int getSets() const{ return sets; }
	int getReps() const { return reps; }
	
	void setSets(int val) { sets = val; }
	void setReps(int val) {  reps = val; }


	const Device * getDevice() const override
	{
		return device;
	}

	string toString()const override
	{
		stringstream result ;

		result << "+++++++++++++++++\n";
		result << "** Exercise: **\n";
		result << "Sets :       " << getSets() << "\n";
		result << "Repetitions: "<<  getReps()<< "\n";
		result << "+++++++++++++++++";

		return result.str();
	}

	virtual ~ExercisePower() {}
};