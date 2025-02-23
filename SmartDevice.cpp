#include "SmartDevice.h"

SmartDevice::SmartDevice(const std::string& name, double power, const std::string& connectionType, const double version)
    : AbstractElectricalDevice(name, power), _connectionType(connectionType), _version(version) {};

std::string SmartDevice::GetConnectionType() const
{
    return _connectionType;
}

double SmartDevice::GetVersion() const
{
    return _version;
}
