#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Device
{
	int serialNumber;
	string name;
public:
	Device(int serialNumber, string name) : serialNumber(serialNumber), name(name) {}
	Device() {}
	//Device(Device& d):serialNumber(d.serialNumber),name(d.name){}
	
	//get & set
	int getSerial() const { return serialNumber; }
	string getName() const { return name; }

	void setSerial(int serial) { serialNumber = serial ;}
	void setName(string name) { this->name = name; }

	string  description() const
	{
		stringstream deviceDescription;
		deviceDescription << "device description: \n";
		deviceDescription << "******************* \n";

		deviceDescription << "Device name:   "<< getName() << "\n";
		deviceDescription << "Device serial: "<< getSerial()<< "\n";

		return deviceDescription.str();
	}


	virtual ~Device() {}
};
