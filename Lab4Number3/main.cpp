#include "CarSystem.h"


int main() {
    CarSystem carSystem;

    try {
        carSystem.loadFromTextFile("TXTFile.txt");
        std::cout << "List of Cars: " << std::endl;
        carSystem.displayAllCars();

        carSystem.saveToBinaryFile("DOTFile.bin");
        carSystem.loadFromBinaryFile("DOTFile.bin");

        carSystem.markCarAsTheft("ABC123");
        carSystem.removeCarByNumber("XYZ789");

        std::cout << "List of Cars: " << std::endl;
        carSystem.displayAllCars();

        std::cout << "List of Theft Cars: " << std::endl;
        carSystem.displayTheftCars();
    }
    catch (const std::exception& ex) {
        std::cout << "Error: " << ex.what() << std::endl;
    }

    return 0;
}
