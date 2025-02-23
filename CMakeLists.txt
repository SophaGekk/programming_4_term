cmake_minimum_required(VERSION 3.5.0)
project(lab3 VERSION 0.1.0 LANGUAGES C CXX)

add_executable(lab3 AbstractElectricalDevice.cpp HeatingDevice.cpp Kettle.cpp Lamp.cpp LightingDevice.cpp main.cpp SmartDevice.cpp Television.cpp)

