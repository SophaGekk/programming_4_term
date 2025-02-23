#include "AbstractElectricalDevice.h"
// Инициализация статического вектора
std::vector<AbstractElectricalDevice *> AbstractElectricalDevice ::_allDevices;

AbstractElectricalDevice ::AbstractElectricalDevice (const std::string& name, double power): _deviceName(name), _powerConsumption(power) 
{
    InitializeRandomPluggedIn(); // Инициализация состояния подключения
    _allDevices.push_back(this); // Добавляем текущий экземпляр в вектор
}

std::string AbstractElectricalDevice ::GetDeviceName() const {
    return _deviceName;
}

double AbstractElectricalDevice ::GetPowerConsumption() const {
    return _powerConsumption; // Возвращаем потребляемую мощность
}

void AbstractElectricalDevice ::UpdatePowerConsumption(double power) {
    _powerConsumption = power; // Обновляем потребляемую мощность
}

bool AbstractElectricalDevice ::GetisPluggedIn() const {
    return _isPluggedIn;
}

void AbstractElectricalDevice ::PlugIn() {
    _isPluggedIn = true;
}

void AbstractElectricalDevice ::Unplug() {
    _isPluggedIn = false;
}

void AbstractElectricalDevice ::PrintInfo() const {}
void AbstractElectricalDevice ::CalculatePower() {}

void AbstractElectricalDevice ::InitializeRandomPluggedIn() {
    _isPluggedIn = rand() % 2; // Состояние подключения (включен/выключен)
}


// Статический метод для подсчета общей потребляемой мощности
double AbstractElectricalDevice ::GetTotalPowerConsumption() {
    double totalPower = 0.0;
    for (AbstractElectricalDevice * device : _allDevices) {
        if (device->GetisPluggedIn()) {
            totalPower += device->GetPowerConsumption();
        }
    }
    return totalPower;
}

AbstractElectricalDevice ::~AbstractElectricalDevice () {
    // Удаляем прибор из вектора
    for (size_t i = 0; i < _allDevices.size(); ++i) {
        if (_allDevices[i] == this) {
            _allDevices.erase(_allDevices.begin() + i);
            break;
        }
    }
}