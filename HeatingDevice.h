#ifndef HEATINGDEVICE_H
#define HEATINGDEVICE_H

#include "AbstractElectricalDevice.h"

class HeatingDevice : public AbstractElectricalDevice {
public:
    HeatingDevice(const std::string& name, double power, double maxTemperature, double heatingTime);

    double GetMaxTemperature() const;
    double GetHeatingTime() const;

private:
    double _maxTemperature;   // Максимальная температура
    double _heatingTime;      // Время нагрева
};

#endif
