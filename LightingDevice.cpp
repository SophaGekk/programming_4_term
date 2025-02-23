#include "LightingDevice.h"

LightingDevice::LightingDevice(const std::string& name, double power, const std::string& type, int brightness) 
    : AbstractElectricalDevice(name, power), _lightType(type), _brightness(brightness) 
{
    // Определение максимальной яркости в зависимости от типа лампы
    if (_lightType == "Светодиодная") {
        _maxBrightness = 1000; //1000 люмен для светодиодной лампы
    } else if (_lightType == "Галогенная") {
        _maxBrightness = 1500; // 1500 люмен для галогенной лампы
    } else {
        _maxBrightness = 500;  // для других типов ламп
    }

    // Установка яркости с учетом максимального значения
    AdjustBrightness(brightness);

}

std::string LightingDevice::GetLightType() const {
    return _lightType;
}

int LightingDevice::GetBrightness() const {
    return _brightness;
}
int LightingDevice::GetMaxBrightness() const {
    return _maxBrightness;
}

void LightingDevice::AdjustBrightness(int newBrightness) {
    // Ограничение значения яркости
    _brightness = std::min(newBrightness, _maxBrightness);
}
