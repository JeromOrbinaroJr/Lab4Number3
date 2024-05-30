#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include "Car.h"

class CarSystem {
public:
	void loadFromTextFile(const std::string& filename);	
	void saveToBinaryFile(const std::string& filename);
	void loadFromBinaryFile(const std::string& filename);
	void displayAllCars();
	void markCarAsTheft(const std::string& numberCar);
	void displayTheftCars();
	void removeCarByNumber(const std::string& number);

private:
	std::string m_fileName;
	std::vector<Car> m_cars;
};

