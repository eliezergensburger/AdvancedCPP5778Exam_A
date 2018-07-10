#pragma once
#include <string>
#include "Device.h"
class DevicePower : virtual public Device
{
protected:
	string musclesGroup;
public:
	DevicePower(int serialNumber, string name, string musclesGroup) : Device(), musclesGroup(musclesGroup) 
	{
		setSerial(serialNumber);
		setName(name);
	}
	DevicePower() {}

	//set & get
	virtual string getMusclesGroup() const { return musclesGroup; }
	virtual void setMusclesGroup(string musclesGroup) { musclesGroup = musclesGroup; }

	string getType() const override { return "Power"; }
	string  deviceInfo() const override
	{
		stringstream deviceDescription;
		deviceDescription << "device description: \n";
		deviceDescription << "******************* \n";

		deviceDescription << "Device name:   " << getName() << "\n";
		deviceDescription << "Device type:   " << getType() << "\n";
		deviceDescription << "Device serial: " << getSerial() << "\n";
		deviceDescription << "MusclesGroup:  " << getMusclesGroup();

		return deviceDescription.str();
	}

	virtual ~DevicePower() {}
};
