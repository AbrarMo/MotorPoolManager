#ifndef CAR_H
#define CAR_H

#include <string>

class Car {
protected:
    std::string VIN;
    std::string make;
    std::string model;
    int year;
    float price;
    std::string category;

public:
    Car(std::string VIN, std::string make, std::string model, int year, float price, std::string category);
    virtual ~Car() {}

    std::string getVIN() const;
    std::string getMake() const;
    std::string getModel() const;
    int getYear() const;
    float getPrice() const;
    std::string getCategory() const;

    void setVIN(const std::string &VIN);
    void setMake(const std::string &make);
    void setModel(const std::string &model);
    void setYear(int year);
    void setPrice(float price);
    void setCategory(const std::string &category);


    virtual void displayInfo() const;
};

#endif 
