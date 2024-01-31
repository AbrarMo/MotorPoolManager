#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <memory>
#include "Car.hpp"
#include "NewCar.hpp"
#include "OldCar.hpp"

class Inventory {
private:
    std::vector<std::shared_ptr<Car>> cars;

public:
    
    void addCar(const std::shared_ptr<Car>& car);
    void sellCar(const std::string& VIN);

    std::vector<std::shared_ptr<Car>> searchByMake(const std::string& make) const;
    std::vector<std::shared_ptr<Car>> searchByModel(const std::string& model) const;
    std::vector<std::shared_ptr<Car>> searchByYear(int year) const;
    std::vector<std::shared_ptr<Car>> searchByCategory(const std::string& category) const;
    std::vector<std::shared_ptr<Car>> searchByPriceRange(float minPrice, float maxPrice) const;

    void listAllCars() const;
};

#endif 
