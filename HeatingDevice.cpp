#include "HeatingDevice.h"

HeatingDevice::HeatingDevice(const std::string& name, double power, double maxTemperature, double heatingTime)
    : AbstractElectricalDevice(name, power), _maxTemperature(maxTemperature), _heatingTime(heatingTime) {}

double HeatingDevice::GetMaxTemperature() const {
    return _maxTemperature;
}

double HeatingDevice::GetHeatingTime() const {
    return _heatingTime;
}
