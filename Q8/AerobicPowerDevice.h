#pragma once
#include "AerobicDevice.h"
#include "PowerDevice.h"
#include "Device.h"
class AerobicPowerDevice: public PowerDevice,public AerobicDevice
{
public:
	AerobicPowerDevice(const PowerDevice &p, const AerobicDevice &a) :
		Device(p.getSerial(), p.getName()),PowerDevice(p),AerobicDevice(a) {}
	AerobicPowerDevice() :PowerDevice(),AerobicDevice(){}

	virtual ~AerobicPowerDevice() {}
};
