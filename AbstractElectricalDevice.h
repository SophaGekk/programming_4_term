#ifndef ABSTRACT_ELECTRICAL_DEVICE_H
#define ABSTRACT_ELECTRICAL_DEVICE_H

#include <string>
#include <vector>

class AbstractElectricalDevice  {
public:
    AbstractElectricalDevice (const std::string& name, double power);
    virtual ~AbstractElectricalDevice ();

    std::string GetDeviceName() const;

    virtual double GetPowerConsumption() const; 
    void UpdatePowerConsumption(double power);   // Метод для обновления мощности
    

    bool GetisPluggedIn() const;
    void PlugIn();
    void Unplug();

    virtual void PrintInfo() const;
    virtual void CalculatePower();
    void InitializeRandomPluggedIn(); // Метод для случайной инициализации состояния подключения
    static double GetTotalPowerConsumption();

protected:
    std::string _deviceName;    // Название устройства
    double _powerConsumption = 1000;    // Потребляемая мощность
    bool _isPluggedIn;          // Состояние подключения
    static std::vector<AbstractElectricalDevice *> _allDevices;    // Статический вектор для хранения всех экземпляров
};

#endif
