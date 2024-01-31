#ifndef NEWCAR_H
#define NEWCAR_H

#include "Car.hpp"
#include <string>

class NewCar : public Car {
private:
    std::string warrantyProvider;

public:
    NewCar(std::string VIN, std::string make, std::string model, int year, float price, std::string category, std::string warrantyProvider);
    virtual ~NewCar() {}

    std::string getWarrantyProvider() const;
    void setWarrantyProvider(const std::string &warrantyProvider);

    virtual void displayInfo() const override;
};

#endif
