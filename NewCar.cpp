#include "NewCar.hpp"
#include <iostream>

NewCar::NewCar(std::string VIN, std::string make, std::string model, int year, float price, std::string category, std::string warrantyProvider)
    : Car(VIN, make, model, year, price, category), warrantyProvider(warrantyProvider) {}

std::string NewCar::getWarrantyProvider() const { return warrantyProvider; }
void NewCar::setWarrantyProvider(const std::string &warrantyProvider) { this->warrantyProvider = warrantyProvider; }

void NewCar::displayInfo() const {
    Car::displayInfo();
    std::cout << "Warranty Provider: " << warrantyProvider << std::endl;
}
