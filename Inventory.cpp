#include "Inventory.hpp"
#include <iostream>
#include <algorithm>

void Inventory::addCar(const std::shared_ptr<Car>& car) {
    
    auto it = std::find_if(cars.begin(), cars.end(), [&car](const std::shared_ptr<Car>& existingCar) {
        return car->getVIN() == existingCar->getVIN();
    });

    if (it == cars.end()) {
        cars.push_back(car);
        std::cout << "Car added to inventory.\n";
    } else {
        std::cout << "Car with this VIN already exists in inventory.\n";
    }
}

void Inventory::sellCar(const std::string& VIN) {
    auto it = std::remove_if(cars.begin(), cars.end(), [&VIN](const std::shared_ptr<Car>& car) {
        return car->getVIN() == VIN;
    });

    if (it != cars.end()) {
        cars.erase(it, cars.end());
        std::cout << "Car sold.\n";
    } else {
        std::cout << "Car with this VIN not found.\n";
    }
}

std::vector<std::shared_ptr<Car>> Inventory::searchByMake(const std::string& make) const {
    std::vector<std::shared_ptr<Car>> foundCars;
    for (const auto& car : cars) {
        if (car->getMake() == make) {
            foundCars.push_back(car);
        }
    }
    return foundCars;
}

std::vector<std::shared_ptr<Car>> Inventory::searchByModel(const std::string& model) const {
    std::vector<std::shared_ptr<Car>> foundCars;
    for (const auto& car : cars) {
        if (car->getModel() == model) {
            foundCars.push_back(car);
        }
    }
    return foundCars;
}


std::vector<std::shared_ptr<Car>> Inventory::searchByYear(int year) const {
    std::vector<std::shared_ptr<Car>> foundCars;
    for (const auto& car : cars) {
        if (car->getYear() == year) {
            foundCars.push_back(car);
        }
    }
    return foundCars;
}


std::vector<std::shared_ptr<Car>> Inventory::searchByCategory(const std::string& category) const {
    std::vector<std::shared_ptr<Car>> foundCars;
    for (const auto& car : cars) {
        if (car->getCategory() == category) {
            foundCars.push_back(car);
        }
    }
    return foundCars;
}

std::vector<std::shared_ptr<Car>> Inventory::searchByPriceRange(float minPrice, float maxPrice) const {
    std::vector<std::shared_ptr<Car>> foundCars;
    for (const auto& car : cars) {
        float carPrice = car->getPrice();
        if (carPrice >= minPrice && carPrice <= maxPrice) {
            foundCars.push_back(car);
        }
    }
    return foundCars;
}


void Inventory::listAllCars() const {
    for (const auto& car : cars) {
        car->displayInfo();
    }
}
