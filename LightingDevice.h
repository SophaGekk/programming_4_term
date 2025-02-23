#ifndef LIGHTINGDEVICE_H
#define LIGHTINGDEVICE_H
#include "AbstractElectricalDevice.h"

class LightingDevice : public AbstractElectricalDevice {
public:
    LightingDevice(const std::string& name, double power, const std::string& type, int brightness);

    std::string GetLightType() const;
    int GetBrightness() const;
    void AdjustBrightness(int newBrightness);
    int GetMaxBrightness() const; // Метод для получения максимальной яркости

private:
    std::string _lightType;
    int _brightness;
    int _maxBrightness;      // Максимальная яркость для типа лампы
};

#endif