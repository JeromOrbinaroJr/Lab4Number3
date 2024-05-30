#pragma once
#include <string>

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
	const int& getKey() const;
	const std::string& getSurnameOwner() const;
	const std::string& getNameOwner() const;
	const std::string& getNumberCar() const;
	const std::string& getBrandCar() const;
	const bool getTheftInfo() const;

	//Setters
	void setKey(const int& numberCar);
	void setSurnameOwner(const std::string& surnameOwner);
	void setNameOwner(const std::string& nameOwner);
	void setNumberCar(const std::string& numberCar);
	void setBrandCar(const std::string& brandCar);
	void setTheftInfo(bool theftInfo);

	//Methods
	bool isTheft() const;

	//Operators Overloading
	//friend std::ostream operator<<(std::ostream os, const Car& car);

private:
	int m_key;
	std::string m_surnameOwner;
	std::string m_nameOwner;
	std::string m_numberCar;
	std::string m_brandCar;
	bool m_theftInfo;
};
