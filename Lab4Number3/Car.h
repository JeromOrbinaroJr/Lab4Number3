#pragma once
#include <string>
#include <sstream>

class Car {
public:
	//Constructors
	Car() = default;
	Car(const int key,
		const std::string& surnameOwner,
		const std::string& nameOwner,
		const std::string& numberCar,
		const std::string& brandCar,
		const bool theftInfo);

	//Getters
	const int getKey() const;
	const std::string& getSurnameOwner() const;
	const std::string& getNameOwner() const;
	const std::string& getNumberCar() const;
	const std::string& getBrandCar() const;
	const bool getTheftInfo() const;

	//Setters
	void setKey(const int numberCar);
	void setSurnameOwner(const std::string& surnameOwner);
	void setNameOwner(const std::string& nameOwner);
	void setNumberCar(const std::string& numberCar);
	void setBrandCar(const std::string& brandCar);
	void setTheftInfo(bool theftInfo);

	//Methods
	bool isTheft() const;

	// Serialization and Deserialization
	std::string serialize() const; // преобразует объект Car в строку. Он использует std::ostringstream,
	//чтобы собрать значения полей объекта в одну строку, разделяя их пробелами.
	static Car deserialize(const std::string& data); //восстанавливает объект Car из строки,
	//созданной методом serialize. Он использует std::istringstream, чтобы извлечь значения полей из строки и создать новый объект Car.
	//static, чтобы его можно было вызвать без создания экземпляра класса Car.

private:
	int m_key;
	std::string m_numberCar;
	std::string m_brandCar;
	std::string m_surnameOwner;
	std::string m_nameOwner;
	bool m_theftInfo;
};