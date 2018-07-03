#pragma once
#include "Device.h"
#include "Aerobic.h"
#include "Power.h"
#include "AerobicPower.h"
#include "Exercise.h"
#include <list>
#include<algorithm>

class Trainee
{
	string name;
	string lastUpdate;
	list<const Exercise*> exercises;

public:
	Trainee() {}
	Trainee(string name) :name(name) {}

	string getLastUpdate() const { return lastUpdate; }
	void setLastUpdate(string update) { lastUpdate = update; }

	void addExercise(const Exercise* p_ex,string update)
	{
		const Device * pd = p_ex->getDevice();
		for (auto it = exercises.begin(); it != exercises.end(); it++)
		{
			if ((*it)->getDevice() == pd)
			{
				return; //quit the function
			}
		}
		//not foud
		exercises.push_back(p_ex);
		setLastUpdate(update);
	}
	void printAllPowerExercises()
	{
		for (auto ex : exercises)
		{
			if (strcmp(typeid(ex->getDevice()).name(),"Power*")==0)
			{
				ex->toString();
			}
		}
	}
	void printAllAerobicExercises()
	{
		for (auto ex : exercises)
		{
			if (strcmp(typeid(ex->getDevice()).name(), "Aerobic*") == 0)
			{
				ex->toString();
			}
		}
	}
	void printAllPowerAerobicExercises()
	{
		for (auto ex : exercises)
		{
			if (strcmp(typeid(ex->getDevice()).name(), "PowerAerobic*") == 0)
			{
				ex->toString();
			}
		}
	}

	void removeExercise(int serial,string update)
	{
		const Exercise* p_ex = nullptr;
		for (auto ex : exercises)
		{
			if (ex->getDevice()->getSerial() == serial)
			{
				p_ex = ex;
				break;
			}
		}
		if (p_ex)
		{
			exercises.remove(p_ex);
			setLastUpdate(update);
		}

	}

	void workout(int serial)
	{
		const Exercise* p_ex;
		for (auto ex : exercises)
		{
			if (ex->getDevice()->getSerial() == serial)
			{
				p_ex = ex;
				break;
			}
		}
		p_ex->training();
	}

	void fullworkout()
	{
		for (auto ex : exercises)
		{
			ex->training();
		}		
	}
};