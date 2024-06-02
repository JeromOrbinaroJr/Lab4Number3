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

	// Serialization and Deserialization
	std::string serialize() const;
	static Car deserialize(const std::string& data);

private:
	int m_key;
	std::string m_numberCar;
	std::string m_brandCar;
	std::string m_surnameOwner;
	std::string m_nameOwner;
	bool m_theftInfo;
};

//struct Car {
//	int key;
//	std::string surnameOwner;
//	std::string& nameOwner;
//	std::string& numberCar;
//	std::string& brandCar;
//	bool theftInfo;
//
//	Car(int m_key, const std::string& m_surnameOwner, const std::string& m_nameOwner, const std::string& m_numberCar,
//		const std::string& m_brandCar, bool m_theftInfo)
//		: key(m_key), surnameOwner(m_surnameOwner), nameOwner(m_nameOwner), numberCar(m_numberCar), brandCar(m_brandCar), theftInfo(m_theftInfo) {}
//
//	Car() : key(0), theftInfo(false) {}
//};