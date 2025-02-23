#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H
#include "AbstractElectricalDevice.h"

class SmartDevice : public AbstractElectricalDevice {
public:
    SmartDevice(const std::string& name, double power, const std::string& connectionType, const double version);
    std::string GetConnectionType() const;
    double GetVersion() const;

private:
    std::string _connectionType; // Тип подключения (Wi-Fi, Bluetooth и т.д.)
    double _version;
};

#endif
