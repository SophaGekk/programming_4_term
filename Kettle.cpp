#include "Kettle.h"
#include <iostream>

Kettle::Kettle(double maxTemperature, double heatingTime)
    : HeatingDevice("Чайник", 100, maxTemperature, heatingTime) {} // Максимальная температура 100°C и время нагрева 1 минута.

void Kettle::CalculatePower(){
    double calculatedPower = GetMaxTemperature() * GetHeatingTime(); // Расчет потребляемой мощности
    UpdatePowerConsumption(calculatedPower); // Обновление мощности в базовом классе
}

void Kettle::PrintInfo() const {
    std::cout << "Прибор: " << GetDeviceName() << ", Потребляемая мощность: " << GetPowerConsumption() << ", Подключен: " << (GetisPluggedIn() ? "Да" : "Нет") <<", Макссимальная температура: " << GetMaxTemperature()<< ", Время нагрева: " << GetHeatingTime()<< "\n";
} 
