#pragma once
#include "Device.h"
#include "AerobicDevice.h"
#include "PowerDevice.h"
#include "AerobicPowerDevice.h"
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
		//not found
		exercises.push_back(p_ex);
		setLastUpdate(update);
	}
	void printAllPowerExercises()
	{
		for (auto ex : exercises)
		{
			if (dynamic_cast<const PowerDevice*>(ex->getDevice())!= nullptr)
			{
				cout << "PowerExercise: " << endl;
				cout << "------------------------" << endl;
				cout << ex->getDevice()->deviceInfo() << endl;
				cout << ex->toString() << endl;
				cout << "------------------------" << endl;
			}
		}
	}
	void printAllAerobicExercises()
	{
		for (auto ex : exercises)
		{
	//		if (strcmp(typeid(*(ex->getDevice())).name(), "class AerobicDevice") == 0)
			if (dynamic_cast<const AerobicDevice*>(ex->getDevice()) != nullptr)
			{
				cout << "AerobicExercise: " << endl;
				cout << "------------------------" << endl;
				cout << ex->getDevice()->deviceInfo() << endl;
				cout << ex->toString() << endl;
				cout << "------------------------" << endl;
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
		const Exercise* p_ex= nullptr;
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
			cout << "**** workout ";
			cout << p_ex->getDevice()->getSerial();
			cout << " ****"<< endl;
			p_ex->training();
		}
	}

	void fullworkout()
	{
		cout << "**** full workout ****" << endl;
		for (auto ex : exercises)
		{
			ex->training();
		}
		cout << "*** end of full workout ***" << endl;
	}
};
