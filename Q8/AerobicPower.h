#pragma once
#include "Aerobic.h"
#include "Power.h"
#include "Device.h"
class AerobicPower: public Power,public Aerobic
{
public:
	AerobicPower(const Power &p, const Aerobic &a) :
		Device(p.getSerial(), p.getName()),Power(p),Aerobic(a) {}
	AerobicPower() :Power(),Aerobic(){}

	virtual ~AerobicPower() {}
};
