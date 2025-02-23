#include <iostream>
#include "Television.h"

Television::Television(const std::string& connectionType, const double& version)
    : SmartDevice("Телевизор", 100, connectionType, version) {} 

void Television::CalculatePower(){
    double calculatedPower;
    if(GetConnectionType() == "Wi-Fi")
    {
        calculatedPower = AbstractElectricalDevice::_powerConsumption  * 5; // Расчет потребляемой мощности
    }
    else if(GetConnectionType() == "Bluetooth")
    {
        calculatedPower = AbstractElectricalDevice::_powerConsumption  * 6; // Расчет потребляемой мощности
    }
    else if(GetConnectionType() == "Wi-Fi and Bluetooth")
    {
        calculatedPower = AbstractElectricalDevice::_powerConsumption  * 11; // Расчет потребляемой мощности
    }
    UpdatePowerConsumption(calculatedPower); // Обновление мощности в базовом классе
}

void Television::PrintInfo() const {
    std::cout << "Прибор: " << GetDeviceName() << ", Потребляемая мощность: " << GetPowerConsumption() << ", Подключен: " << (GetisPluggedIn() ? "Да" : "Нет") << ", Тип подключения: " << GetConnectionType()<< ", Текущая версия: " << GetVersion()<< "\n";
} 
