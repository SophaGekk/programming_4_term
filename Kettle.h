#ifndef KETTLE_H
#define KETTLE_H

#include "HeatingDevice.h"

class Kettle : public HeatingDevice {
public:
    Kettle(double maxTemperature, double heatingTime);

    void PrintInfo() const override;
    void CalculatePower() override;
};

#endif