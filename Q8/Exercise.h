#pragma once
#include "Device.h"
#include "Aerobic.h"
#include "Power.h"
#include "AerobicPower.h"
class Exercise	//abstract class
{
protected:
	const Device * device;
public:
	Exercise(const Device& d) :device(&d){ }
	Exercise() {}

	const Device * getDevice() const { return device ; }

	void virtual training() const = 0; //;pure virtual

	void virtual toString() const 
	{ 
		cout << "Device name:   " << device->getName() << endl;
		cout << "Device serial: " << device->getSerial() << endl;
	}
	virtual ~Exercise() {}
};