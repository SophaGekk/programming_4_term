#ifndef LAMP_H
#define LAMP_H
#include "LightingDevice.h"

class Lamp : public LightingDevice {
public:
    Lamp(std::string lightType, int brightness);

    void PrintInfo() const override;
    void CalculatePower() override;
};

#endif