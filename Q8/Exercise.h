#pragma once
#include "Device.h"
#include "AerobicDevice.h"
#include "PowerDevice.h"
#include "AerobicPowerDevice.h"
class Exercise	// abstract class
{
public:
	Exercise() {}

	virtual const Device * getDevice() const = 0; // pure virtual
	string virtual toString() const = 0; // pure virtual

	void  training() const 
	{
		cout << "Training with: " << endl;
		cout << getDevice()->description() << endl;
		cout << toString() << endl;
	}

	virtual ~Exercise() {}
};