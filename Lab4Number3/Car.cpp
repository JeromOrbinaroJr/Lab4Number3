#include "Car.h"

//Constructors
Car::Car(const int key,
    const std::string& numberCar,
	const std::string& surnameOwner,
	const std::string& nameOwner,
	const std::string& brandCar,
	const bool theftInfo) :
	m_key(key), m_numberCar(numberCar), m_surnameOwner(surnameOwner), m_nameOwner(nameOwner),
	m_brandCar(brandCar), m_theftInfo(theftInfo) {}

//Getters
const int Car::getKey() const { return m_key; }
const std::string& Car::getNumberCar() const { return m_numberCar; }
const std::string& Car::getSurnameOwner() const { return m_surnameOwner; }
const std::string& Car::getNameOwner() const { return m_nameOwner; }
const std::string& Car::getBrandCar() const { return m_brandCar; }
const bool Car::getTheftInfo() const { return m_theftInfo; }

//Setters
void Car::setKey(const int key) { m_key = key; }
void Car::setNumberCar(const std::string& numberCar) { m_numberCar = numberCar; }
void Car::setSurnameOwner(const std::string& surnameOwner) { m_surnameOwner = surnameOwner; }
void Car::setNameOwner(const std::string& nameOwner) { m_nameOwner = nameOwner; }
void Car::setBrandCar(const std::string& brandCar) { m_brandCar = brandCar; }
void Car::setTheftInfo(bool theftInfo) { m_theftInfo = theftInfo; }

// Serialization and Deserialization
std::string Car::serialize() const {
    std::ostringstream oss; // чтобы собрать значени€ полей объекта в одну строку, раздел€€ их пробелами.
    oss << m_key << " " << m_numberCar << " " << m_surnameOwner << " " << m_nameOwner << " " << m_brandCar << " " << m_theftInfo;
    return oss.str();
}

Car Car::deserialize(const std::string& data) {
    std::istringstream iss(data); // чтобы извлечь значени€ полей из строки и создать новый объект Car.
    int key;
    std::string surnameOwner, nameOwner, numberCar, brandCar;
    bool theftInfo;
    iss >> key >> numberCar >> surnameOwner >> nameOwner >> brandCar >> theftInfo;
    return Car(key, numberCar, surnameOwner, nameOwner, brandCar, theftInfo);
}