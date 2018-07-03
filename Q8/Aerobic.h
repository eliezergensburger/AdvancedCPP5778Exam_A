#pragma once
#include <string>
#include "Device.h"
class Aerobic : virtual public Device
{
protected:
	int calories;
public:
	Aerobic(int serialNumber, string name, int calories) :
		Device(serialNumber, name), calories(calories) {}
	Aerobic() {}


	//set & get
	int getCalories() const { return calories; }
	void setCalories(int calories) { calories = calories; }

	virtual ~Aerobic() {}
};


