#pragma once
#include <string>
#include "Device.h"
class Power : virtual public Device
{
protected:
	string musclesGroup;
public:
	Power(int serialNumber, string name, string musclesGroup) :
		Device(serialNumber, name), musclesGroup(musclesGroup) {}
	Power() :Device(){}

	//set & get
	string getMusclesGroup() const { return musclesGroup; }
	void settMusclesGroup(string musclesGroup) { musclesGroup = musclesGroup; }

	virtual ~Power() {}
};
