#pragma once
#include "AerobicDevice.h"
#include "PowerDevice.h"
#include "Device.h"

// inheritance here is used only to be able to classify 
// this class as belonging to both class types "PowerDevice"and "AerobicDevice"
// ortherwise we were using inheritance from "Device" only

class AerobicPowerDevice: virtual public PowerDevice, virtual public AerobicDevice
{
protected:
	int caloriesAP;
	string musclesGroupAP;
public:
	AerobicPowerDevice(int serialNumber, string name, int calories, string musclesGroup) :
		PowerDevice(), AerobicDevice(),
		Device(serialNumber, name), caloriesAP(calories), musclesGroupAP(musclesGroup)	{}

	AerobicPowerDevice() :PowerDevice(),AerobicDevice(),caloriesAP(0), musclesGroupAP("") {}

	//set & get
	//discard calories and musclesGroup from inherited classes
	int getCalories() const  override { return caloriesAP; }
	void setCalories(int calories) override { caloriesAP = calories; }

	string getMusclesGroup() const override { return musclesGroupAP; }
	void setMusclesGroup(string musclesGroup)override { musclesGroupAP = musclesGroup; }

	string  deviceInfo() const override
	{
		stringstream deviceDescription;
		deviceDescription << "device description: \n";
		deviceDescription << "******************* \n";

		deviceDescription << "Device name:   " << getName() << "\n";
		deviceDescription << "Device serial: " << getSerial() << "\n";
		deviceDescription << "MusclesGroup:  " << getMusclesGroup() << "\n";
		deviceDescription << "Calories:      " << getCalories();

		return deviceDescription.str();
	}


	virtual ~AerobicPowerDevice() {}
};
