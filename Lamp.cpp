#include <iostream>
#include "Lamp.h"

Lamp::Lamp(std::string lightType, int brightness)
    : LightingDevice("Лампа", 100, lightType, brightness) {
        AdjustBrightness(brightness);
    } 

void Lamp::CalculatePower(){
    double calculatedPower = GetPowerConsumption() * GetBrightness();
    UpdatePowerConsumption(calculatedPower); // Обновление мощности в базовом классе
}

void Lamp::PrintInfo() const {
    std::cout << "Прибор: " << GetDeviceName() << ", Потребляемая мощность: " << GetPowerConsumption() << ", Подключен: " << (GetisPluggedIn() ? "Да" : "Нет") << ", Тип освещения: " << GetLightType() << ", Яркость: " << GetBrightness() << "\n";
} 

