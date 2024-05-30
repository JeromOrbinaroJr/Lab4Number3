#include "CarSystem.h"


int main() {
    CarSystem carSystem;

    carSystem.loadFromTextFile("TXTFile.txt");
    carSystem.saveToBinaryFile("DOTFile.dot");
    carSystem.loadFromBinaryFile("DOTFile.dot");
    carSystem.displayAllCars();
    carSystem.markCarAsTheft("ABC123");
    //carSystem.removeCarByNumber("XYZ789");  
    carSystem.displayTheftCars();

    return 0;
}

//2
//Smith
//Jane
//XYZ789
//Oak
//1
