#pragma once
#include "Device.h"
#include "DeviceAerobic.h"
#include "DevicePower.h"
#include "DeviceAerobicPower.h"
#include "Exercise.h"
#include "ExerciseAerobic.h"
#include "ExercisePower.h"
#include "ExerciseAerobicPower.h"
#include "Trainee.h"
#include <iostream>
#include <algorithm>

using namespace std;

class Gym
{
	list<Trainee*> trainees;
	list<Device*> devices;
public:
	//zil gmor: nigmar li hakoach
	Gym() {}

	~Gym()
	{
		//doesn't free memory that was dynamicly allocated
		trainees.clear();
		devices.clear();
	}

	list<Trainee*> getAllTrainees()
	{
		return list<Trainee*>(trainees);
	}

	Trainee* getTrainee(string name)
	{
		auto it = find_if(trainees.begin(), trainees.end(), [name](Trainee* t) { return t->getName() == name; });
		if (it != trainees.end())
		{
			return *it;
		}
		return nullptr;
	}

	list<Device*> getAllDevices()
	{
		return list<Device*>(devices);
	}

	bool addTrainee(Trainee* trainee)
	{
		if (trainees.empty())
		{
			trainees.push_back(trainee);
			return true;
		}
		auto it = find(trainees.begin(), trainees.end(), trainee);
		if (it != trainees.end())
		{
			return false;
		}
		trainees.push_back(trainee);
		return true;
	}

	bool addDevice(Device* device)
	{
		if (devices.empty())
		{
			devices.push_back(device);
			return true;
		}
		auto it = find(devices.begin(), devices.end(), device);
		if (it != devices.end())
		{
			return false;
		}
		devices.push_back(device);
		return true;
	}
};
