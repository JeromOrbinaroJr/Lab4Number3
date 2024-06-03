#include "CarSystem.h"

bool isFileEmpty(const std::string& filename) {
    std::ifstream file(filename);
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
    std::ofstream outFile(filename, std::ios::binary); // бинарный режим
    if (!outFile.is_open()) { throw std::runtime_error("The file cannot be opened, or does not exist."); }

    for (const Car& car : m_cars) {
        std::string serializedCar = car.serialize();
        size_t size = serializedCar.size();
        outFile.write(reinterpret_cast<const char*>(&size), sizeof(size)); // записывается размер данных в байтах
        outFile.write(serializedCar.c_str(), size); // записываются сами данные 
    }
    outFile.close();
}

void CarSystem::loadFromBinaryFile(const std::string& filename) {
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile.is_open()) { throw std::runtime_error("The file cannot be opened, or does not exist."); }

    while (inFile) {
        size_t size;
        inFile.read(reinterpret_cast<char*>(&size), sizeof(size)); // считывает размер данных в файле
        if (inFile.eof()) break; // проверка на достижение конца файла
        std::string serializedCar(size, ' ');
        inFile.read(&serializedCar[0], size);
        Car car = Car::deserialize(serializedCar);

        bool found = false;
        for (Car& existingCar : m_cars) {
            if (existingCar.getKey() == car.getKey()) {
                existingCar = car; // Обновляем информацию о машине
                found = true;
                break;
            }
        }
        if (!found) {
            m_cars.push_back(car); // Если машина не найдена, добавляем её в вектор
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

void CarSystem::markCarAsTheft(const std::string& numberCar) {
    for (Car& car : m_cars) {
        if (car.getNumberCar() == numberCar) {
            car.setTheftInfo(true);
            return;
        }
    }
    throw std::runtime_error("Car with number " + numberCar + " not found.");
}

void CarSystem::displayTheftCars() {
    for (const Car& car : m_cars) {
        if (car.getTheftInfo()) {
            std::cout << car.getKey() << " " << car.getNumberCar() << std::endl;
        }
    }
}

void CarSystem::removeCarByNumber(const std::string& number) {
    auto it = std::remove_if(m_cars.begin(), m_cars.end(), [&number](const Car& car) { return car.getNumberCar() == number; }); // Алгоритм std::remove_if принимает диапазон элементов (в данном случае, от m_cars.begin() до m_cars.end()) и предикатную функцию (здесь лямбда-функцию), которая определяет условие для удаления элементов. Лямбда-функция проверяет номер каждой машины и возвращает true, если он равен указанному номеру number.
    if (it != m_cars.end()) {
        m_cars.erase(it, m_cars.end());
    }
    else {
        throw std::runtime_error("Car with number " + number + " not found.");
    }
}




