#include "CarSystem.h"

void CarSystem::loadFromTextFile(const std::string& filename) {
	std::ifstream inFile(filename);
	if (!inFile.is_open()) { throw std::runtime_error("The file cannot be opened, or does not exist."); }
	int key;
	std::string surnameOwner, nameOwner, numberCar, brandCar;
	bool theftInfo;
	while (inFile >> key >> surnameOwner >> nameOwner >> numberCar >> brandCar >> theftInfo) {
		Car car(key, surnameOwner, nameOwner, numberCar, brandCar, theftInfo);
		m_cars.push_back(car);
	}
	inFile.close();
}

void CarSystem::saveToBinaryFile(const std::string& filename) {
	std::ofstream outFile(filename, std::ios::binary);
	if (!outFile.is_open()) { throw std::runtime_error("The file cannot be opened, or does not exist."); }

	for (const Car& car : m_cars) {
		outFile.write(reinterpret_cast<const char*>(&car), sizeof(car));
	}
	outFile.close();
}

void CarSystem::loadFromBinaryFile(const std::string& filename) {
	std::ifstream inFile(filename);
	if (!inFile.is_open()) { throw std::runtime_error("The file cannot be opened, or does not exist."); }
	Car car;
	while (inFile.read(reinterpret_cast<char*>(&car), sizeof(Car))) {
		m_cars.push_back(car);
	}
	inFile.close();
}

void CarSystem::displayAllCars() {
	for (const Car& car : m_cars) {
		std::cout << car.getKey() << std::endl;
		std::cout << car.getSurnameOwner() << std::endl;
		std::cout << car.getNameOwner() << std::endl;
		std::cout << car.getNumberCar() << std::endl;
		std::cout << car.getBrandCar() << std::endl;
		std::cout << car.getTheftInfo() << std::endl;
		std::cout << "------------------------------" << std::endl;
	}
}

void CarSystem::markCarAsTheft(const std::string& numberCar) {
	for (Car& car : m_cars) {
		if (car.getNumberCar() == numberCar) {
			car.setTheftInfo(true);
			return;
		}
	}
	std::runtime_error("Car with number " + numberCar + " not found.");
}

void CarSystem::displayTheftCars() {
	for (const Car& car : m_cars) {
		if (car.getTheftInfo()) {
			std::cout << car.getKey() << " " << car.getNumberCar() << std::endl;
		}
	}
}

void CarSystem::removeCarByNumber(const std::string& number) {
	std::vector<Car>::iterator it = std::remove_if(m_cars.begin(), m_cars.end(), [&number](const Car& car) {
		return car.getNumberCar() == number;
	});
	if (it != m_cars.end()) {
		m_cars.erase(it, m_cars.end());
	}
	else {
		std::runtime_error("Car with number " + number + " not found.");
	}
}



