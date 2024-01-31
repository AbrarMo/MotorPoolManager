#include "Car.hpp"
#include <iostream>

Car::Car(std::string VIN, std::string make, std::string model, int year, float price, std::string category)
    : VIN(VIN), make(make), model(model), year(year), price(price), category(category) {}

std::string Car::getVIN() const { return VIN; }
std::string Car::getMake() const { return make; }
std::string Car::getModel() const { return model; }
int Car::getYear() const { return year; }
float Car::getPrice() const { return price; }
std::string Car::getCategory() const { return category; }

void Car::setVIN(const std::string &VIN) { this->VIN = VIN; }
void Car::setMake(const std::string &make) { this->make = make; }
void Car::setModel(const std::string &model) { this->model = model; }
void Car::setYear(int year) { this->year = year; }
void Car::setPrice(float price) { this->price = price; }
void Car::setCategory(const std::string &category) { this->category = category; }

void Car::displayInfo() const {
    std::cout << "VIN: " << VIN << ", Make: " << make << ", Model: " << model
              << ", Year: " << year << ", Price: $" << price << ", Category: " << category << std::endl;
}
