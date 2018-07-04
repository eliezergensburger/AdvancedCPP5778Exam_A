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
	string getMusclesGroup() const { return musclesGroup; }
	void setMusclesGroup(string musclesGroup) { musclesGroup = musclesGroup; }

	virtual ~PowerDevice() {}
};
