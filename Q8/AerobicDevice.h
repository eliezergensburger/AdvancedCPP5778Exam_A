#pragma once
#include <string>
#include "Device.h"
class AerobicDevice : virtual public Device
{
protected:
	int calories;
public:
	AerobicDevice(int serialNumber, string name, int calories) :
		Device(serialNumber, name), calories(calories) {}
	AerobicDevice() {}


	//set & get
	int getCalories() const { return calories; }
	void setCalories(int calories) { calories = calories; }

	virtual ~AerobicDevice() {}
};


