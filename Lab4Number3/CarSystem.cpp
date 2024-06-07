#include "CarSystem.h"

bool isFileEmpty(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    return file.peek() == std::ifstream::traits_type::eof(); // проверка, если peek возвращает EOF, то файл пуст.
}

void CarSystem::loadFromTextFile(const std::string& filename) {
    std::ifstream inFile(filename);

    if (!inFile.is_open()) { throw std::runtime_error("The file cannot be opened, or does not exist."); }
    if (isFileEmpty(filename)) { throw std::runtime_error("File is empty."); }

    int key;
    std::string surnameOwner, nameOwner, numberCar, brandCar;
    bool theftInfo;
    while (inFile >> key >> numberCar >> surnameOwner >> nameOwner >> brandCar >> theftInfo) {
        Car car(key, numberCar, surnameOwner, nameOwner, brandCar, theftInfo);
        m_cars.push_back(car);
    }
    inFile.close();
}

void CarSystem::saveToBinaryFile(const std::string& filename) {
    std::ofstream outFile(filename, std::ios::binary);

    if (!outFile.is_open()) { throw std::runtime_error("The file cannot be opened, or does not exist."); }

    for (const Car& car : m_cars) {
        std::string serializedCar = car.serialize();
        size_t size = serializedCar.size();
        outFile.write(reinterpret_cast<const char*>(&size), sizeof(size)); // записываетс€ размер данных в байтах
        outFile.write(serializedCar.c_str(), size); // записываютс€ сами данные, конвертиру€ string в array chaer 
    }
    outFile.close();
}

void CarSystem::loadFromBinaryFile(const std::string& filename) {
    std::ifstream inFile(filename, std::ios::binary);

    if (!inFile.is_open()) { throw std::runtime_error("The file cannot be opened, or does not exist."); }
    if (isFileEmpty(filename)) { throw std::runtime_error("File is empty."); }

    while (inFile) {
        size_t size;
        inFile.read(reinterpret_cast<char*>(&size), sizeof(size)); // считываетс€ размер данных в файле
        if (inFile.eof()) break; // проверка на достижение конца файла
        std::string serializedCar(size, ' ');
        inFile.read(&serializedCar[0], size);
        Car car = Car::deserialize(serializedCar);

        bool found = false;
        for (Car& existingCar : m_cars) {
            if (existingCar.getKey() == car.getKey()) {
                existingCar = car;
                found = true;
                break;
            }
        }
        if (!found) {
            m_cars.push_back(car);
        }
    }
    inFile.close();
}

void CarSystem::displayAllCars() {
    for (const Car& car : m_cars) {
        std::cout << car.getKey() << std::endl;
        std::cout << car.getNumberCar() << std::endl;
        std::cout << car.getSurnameOwner() << std::endl;
        std::cout << car.getNameOwner() << std::endl;
        std::cout << car.getBrandCar() << std::endl;
        std::cout << car.getTheftInfo() << std::endl;
        std::cout << "------------------------------" << std::endl;
    }
}

void CarSystem::markCarAsTheft(const std::string& numberCar) {//workWithBinary
    for (Car& car : m_cars) {
        if (car.getNumberCar() == numberCar) {
            car.setTheftInfo(true);
            return;
        }
    }
    throw std::runtime_error("Car with number " + numberCar + " not found.");
}

//////////////////////////////////
void CarSystem::markCarAsTheftBinary(const std::string& numberCar) {
    std::fstream file("DOTFile.bin", std::ios::in | std::ios::out | std::ios::binary);

    if (!file.is_open()) { throw std::runtime_error("The file cannot be opened, or does not exist."); }

    std::vector<Car> cars;
    while (file) {
        size_t size;
        file.read(reinterpret_cast<char*>(&size), sizeof(size));
        if (file.eof()) break;

        std::string serializedCar(size, ' ');
        file.read(&serializedCar[0], size);
        cars.push_back(Car::deserialize(serializedCar));
    }
    file.close();

    bool found = false;
    for (Car& car : cars) {
        if (car.getNumberCar() == numberCar) {
            car.setTheftInfo(true);
            found = true;
            break;
        }
    }
    if (!found) { throw std::runtime_error("Car with number " + numberCar + " not found."); }

    std::ofstream outFile("DOTFile.bin", std::ios::binary);
    if (!outFile.is_open()) { throw std::runtime_error("The file cannot be opened for writing."); }
    for (const Car& car : cars) {
        std::string serializedCar = car.serialize();
        size_t size = serializedCar.size();
        outFile.write(reinterpret_cast<const char*>(&size), sizeof(size));
        outFile.write(serializedCar.c_str(), size);
    }
    outFile.close();

    m_cars = cars;
}

///////////////////////////////////

void CarSystem::displayTheftCars() {
    for (const Car& car : m_cars) {
        if (car.getTheftInfo()) {
            std::cout << car.getKey() << " " << car.getNumberCar() << std::endl;
        }
    }
}

void CarSystem::removeCarByNumberCar(const std::string& number) {
    auto it = std::remove_if(m_cars.begin(), m_cars.end(), [&number](const Car& car) { return car.getNumberCar() == number; });
    if (it != m_cars.end()) {
        m_cars.erase(it, m_cars.end());
    }
    else {
        throw std::runtime_error("Car with number " + number + " not found.");
    }
}




