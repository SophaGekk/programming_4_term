#include <iostream>
#include <cstdlib> // Для rand()
#include <ctime>   // Для time()
#include "Lamp.h"
#include "Kettle.h"
#include "Television.h"

int main() {
   srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел

   // Создаем экземпляры различных классов.
   Lamp lamp("Светодионные", 45);
   lamp.CalculatePower();
   Kettle kettle(100,5);
   kettle.CalculatePower();
   Television tv("Wi-Fi", 21.5);
   tv.CalculatePower();
   
   // Вывод информации о приборах.
   std::cout << std::endl;
   lamp.PrintInfo();
   std::cout << std::endl;
   kettle.PrintInfo();
   std::cout << std::endl;
   tv.PrintInfo();
   std::cout << std::endl;
   

   // Подсчет общей потребляемой мощности всех приборов.
   double totalPowerConsumption = AbstractElectricalDevice::GetTotalPowerConsumption();

   std::cout << "\nОбщая потребляемая мощность всех приборов: " << totalPowerConsumption  << " Вт\n";

   return 0; 
}
