#include "Car.h"

//Constructors
Car::Car(const int key,
	const std::string& surnameOwner,
	const std::string& nameOwner,
	const std::string& numberCar,
	const std::string& brandCar,
	const bool theftInfo) :
	m_key(key), m_surnameOwner(surnameOwner), m_nameOwner(nameOwner), m_numberCar(numberCar),
	m_brandCar(brandCar), m_theftInfo(theftInfo) {}

//Getters
const int& Car::getKey() const { return m_key; }
const std::string& Car::getSurnameOwner() const { return m_surnameOwner; }
const std::string& Car::getNameOwner() const { return m_nameOwner; }
const std::string& Car::getNumberCar() const { return m_numberCar; }
const std::string& Car::getBrandCar() const { return m_brandCar; }
const bool Car::getTheftInfo() const { return m_theftInfo; }

//Setters
void Car::setKey(const int& key) { m_key = key; }
void Car::setSurnameOwner(const std::string& surnameOwner) { m_surnameOwner = surnameOwner; }
void Car::setNameOwner(const std::string& nameOwner) { m_nameOwner = nameOwner; }
void Car::setNumberCar(const std::string& numberCar) { m_numberCar = numberCar; }
void Car::setBrandCar(const std::string& brandCar) { m_brandCar = brandCar; }
void Car::setTheftInfo(bool theftInfo) { m_theftInfo = theftInfo; }

//Methods
bool Car::isTheft() const { return m_theftInfo; }

// Serialization and Deserialization
std::string Car::serialize() const {
    std::ostringstream oss;
    oss << m_key << " " << m_surnameOwner << " " << m_nameOwner << " " << m_numberCar << " " << m_brandCar << " " << m_theftInfo;
    return oss.str();
}

Car Car::deserialize(const std::string& data) {
    std::istringstream iss(data);
    int key;
    std::string surnameOwner, nameOwner, numberCar, brandCar;
    bool theftInfo;
    iss >> key >> surnameOwner >> nameOwner >> numberCar >> brandCar >> theftInfo;
    return Car(key, surnameOwner, nameOwner, numberCar, brandCar, theftInfo);
}