#pragma once
#include <string>
#include "Device.h"
class PowerDevice : virtual public Device
{
protected:
	string musclesGroup;
public:
	PowerDevice(int serialNumber, string name, string musclesGroup) :
		Device(serialNumber, name), musclesGroup(musclesGroup) {}
	PowerDevice() {}

	//set & get
    virtual string getMusclesGroup() const { return musclesGroup; }
	virtual void setMusclesGroup(string musclesGroup) { musclesGroup = musclesGroup; }
	
	string  deviceInfo() const override
	{
		stringstream deviceDescription;
		deviceDescription << "device description: \n";
		deviceDescription << "******************* \n";

		deviceDescription << "Device name:   " << getName() << "\n";
		deviceDescription << "Device serial: " << getSerial() << "\n";
		deviceDescription << "MusclesGroup:  " << getMusclesGroup() ;

		return deviceDescription.str();
	}

	virtual ~PowerDevice() {}
};
