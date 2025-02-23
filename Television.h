#ifndef TELEVISION_H
#define TELEVISION_H
#include "SmartDevice.h"

class Television : public SmartDevice {
public:
    Television(const std::string& connectionType, const double& version);
    void PrintInfo() const override;
    void CalculatePower() override;
};

#endif