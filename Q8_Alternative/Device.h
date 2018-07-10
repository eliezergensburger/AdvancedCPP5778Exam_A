#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Device	// abstract class
{
	int serialNumber;
	string name;
public:
	Device() {}

	//get & set

	int getSerial() const { return serialNumber; }
	string getName() const { return name; }

	void setSerial(int serial) { serialNumber = serial; }
	void setName(string name) { this->name = name; }

	virtual string  deviceInfo() const = 0; // making the class abstract
	virtual string getType() const = 0;		// making the class abstract

	virtual ~Device() {}
};
