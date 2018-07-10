#pragma once
#include <string>
#include "Device.h"
class DeviceAerobic : virtual public Device
{
protected:
	int calories;
public:
	DeviceAerobic(int serialNumber, string name, int calories) :Device(), calories(calories) 
	{ 
		setSerial(serialNumber);
		setName(name);
	}
	DeviceAerobic() {}


	//set & get
	virtual int getCalories() const { return calories; }
	virtual void setCalories(int calories) { calories = calories; }

	string getType() const override { return "Aerobic"; }
	string  deviceInfo() const override
	{
		stringstream deviceDescription;
		deviceDescription << "device description: \n";
		deviceDescription << "******************* \n";

		deviceDescription << "Device name:   " << getName() << "\n";
		deviceDescription << "Device type:   " << getType() << "\n";
		deviceDescription << "Device serial: " << getSerial() << "\n";
		deviceDescription << "Calories:   " << getCalories();

		return deviceDescription.str();
	}

	virtual ~DeviceAerobic() {}
};


