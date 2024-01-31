#include "OldCar.hpp"
#include <iostream>

OldCar::OldCar(std::string VIN, std::string make, std::string model, int year, float price, std::string category, int mileage)
    : Car(VIN, make, model, year, price, category), mileage(mileage) {}


int OldCar::getMileage() const { return mileage; }
void OldCar::setMileage(int mileage) { this->mileage = mileage; }


void OldCar::displayInfo() const {
    Car::displayInfo();
    std::cout << "Mileage: " << mileage << " miles" << std::endl;
}
