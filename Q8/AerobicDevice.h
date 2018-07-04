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
	virtual int getCalories() const { return calories; }
	virtual void setCalories(int calories) { calories = calories; }

	string  deviceInfo() const override 
	{
		stringstream deviceDescription;
		deviceDescription << "device description: \n";
		deviceDescription << "******************* \n";

		deviceDescription << "Device name:   " << getName() << "\n";
		deviceDescription << "Device serial: " << getSerial() << "\n";
		deviceDescription << "Calories:   " << getCalories() ;

		return deviceDescription.str();
	}

	virtual ~AerobicDevice() {}
};


