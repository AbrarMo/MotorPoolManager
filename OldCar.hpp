#ifndef OLDCAR_H
#define OLDCAR_H

#include "Car.hpp"
#include <string>

class OldCar : public Car {
private:
    int mileage;

public:
    OldCar(std::string VIN, std::string make, std::string model, int year, float price, std::string category, int mileage);
    virtual ~OldCar() {}

    int getMileage() const;
    void setMileage(int mileage);

    virtual void displayInfo() const override;
};

#endif
