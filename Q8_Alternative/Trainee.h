#pragma once
#include "Device.h"
#include "DeviceAerobic.h"
#include "DevicePower.h"
#include "DeviceAerobicPower.h"
#include "Exercise.h"
#include <list>
#include <algorithm>

class Trainee
{
	string name;
	string lastUpdate;
	list<const Exercise*> exercises;

public:
	Trainee() {}
	Trainee(string name) :name(name) {}
	string getName() const { return name; }
	string getLastUpdate() const { return lastUpdate; }
	void setLastUpdate(string update) { lastUpdate = update; }

	void addExercise(const Exercise* p_ex, string update)
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
		string mytype;
		unsigned int found;
		for (auto ex : exercises)
		{
			mytype = ex->getDevice()->getType();
			found = mytype.find("DevicePower");
			if (found != string::npos)
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
		string mytype;
		unsigned int found;
		for (auto ex : exercises)
		{
			mytype = ex->getDevice()->getType();
			found = mytype.find("DeviceAerobic");
			if (found != string::npos)
			{
				cout << "AerobicExercise: " << endl;
				cout << "------------------------" << endl;
				cout << ex->getDevice()->deviceInfo() << endl;
				cout << ex->toString() << endl;
				cout << "------------------------" << endl;
			}
		}
	}

	void removeExercise(int serial, string update)
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
			cout << "**** workout ";
			cout << p_ex->getDevice()->getSerial();
			cout << " ****" << endl;
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
