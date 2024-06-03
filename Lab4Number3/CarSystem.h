#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Car.h"

class CarSystem {
public:
	void loadFromTextFile(const std::string& filename);	
	void saveToBinaryFile(const std::string& filename);
	void loadFromBinaryFile(const std::string& filename);
	void displayAllCars();
	void removeCarByNumberCar(const std::string& number);
	
	//Список автомобилей, числящихся в угоне
	void displayTheftCars();

	//Установка факта угона с заданным номером
	void markCarAsTheft(const std::string& numberCar);

private:
	std::string m_fileName;
	std::vector<Car> m_cars;
};

