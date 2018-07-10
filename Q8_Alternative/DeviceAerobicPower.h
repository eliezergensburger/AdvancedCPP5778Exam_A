#pragma once
#include "Device.h"
#include "DeviceAerobic.h"
#include "DevicePower.h"

// inheritance here is used only to be able to classify 
// this class as belonging to both class types "DevicePower"and "DeviceAerobic"
// and to access to their gettters and setters and inheriting their parent "Device"

class DeviceAerobicPower : virtual public DevicePower, virtual public DeviceAerobic
{
public:
	DeviceAerobicPower(int serialNumber, string name, int calories, string musclesGroup) 
		: Device(),DeviceAerobic(), DevicePower()
	{
		setCalories(calories);
		setMusclesGroup(musclesGroup);
	}

	DeviceAerobicPower() :Device(),DeviceAerobic(), DevicePower() {}

	string getType() const override 
	{
		string result = "";
		result += DeviceAerobic::getType();
		result += " and ";
		result += DevicePower::getType();
		return result;
	}
	string  deviceInfo() const override
	{
		stringstream deviceDescription;
		deviceDescription << "device description: \n";
		deviceDescription << "******************* \n";

		deviceDescription << "Device name:   " << getName() << "\n";
		deviceDescription << "Device type:   " << getType() << "\n";
		deviceDescription << "Device serial: " << getSerial() << "\n";
		deviceDescription << "MusclesGroup:  " << getMusclesGroup() << "\n";
		deviceDescription << "Calories:      " << getCalories();

		return deviceDescription.str();
	}

	virtual ~DeviceAerobicPower() {}
};
