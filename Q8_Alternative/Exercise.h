#pragma once
#include "Device.h"

class Exercise	// interface class
{
public:
	Exercise() {}

	virtual const Device * getDevice() const = 0; // pure virtual
	string virtual toString() const = 0; // pure virtual

	void  training() const
	{
		cout << "Training with: " << endl;
		cout << getDevice()->deviceInfo() << endl;
		cout << toString() << endl;
		cout << "-----------------------" << endl;
	}

	virtual ~Exercise() {}
};