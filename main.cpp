#include <cstdlib>
#include <iostream>
#include <memory>
#include "Inventory.hpp"
#include "Car.hpp"
#include "NewCar.hpp"
#include "OldCar.hpp"

void addCarToInventory(Inventory& inventory);
void sellCarFromInventory(Inventory& inventory);
void searchInInventory(const Inventory& inventory);
void searchByPriceRange(Inventory& inventory);

int main() {
    Inventory inventory;
          inventory.addCar(std::make_shared<NewCar>("VIN001", "Toyota", "Camry", 2022, 30000, "New", "ToyotaCare"));
          inventory.addCar(std::make_shared<NewCar>("VIN002", "Toyota", "Camry", 2021, 40000, "New", "ToyotaCare"));
          inventory.addCar(std::make_shared<NewCar>("VIN003", "Honda", "Civic", 2021, 25000, "New", "HondaCare"));
          inventory.addCar(std::make_shared<NewCar>("VIN004", "Ford", "Mustang", 2023, 35000, "New", "FordCare"));
          inventory.addCar(std::make_shared<NewCar>("VIN005", "Tesla", "Model 3", 2022, 50000, "New", "TeslaCare"));
          inventory.addCar(std::make_shared<NewCar>("VIN006", "BMW", "3 Series", 2021, 45000, "New", "BMWCare"));

          inventory.addCar(std::make_shared<OldCar>("VIN007", "Toyota", "Corolla", 2018, 15000, "Old", 60000));
          inventory.addCar(std::make_shared<OldCar>("VIN008", "Honda", "Accord", 2017, 14000, "Old", 70000));
          inventory.addCar(std::make_shared<OldCar>("VIN009", "Ford", "F-150", 2016, 20000, "Old", 80000));
          inventory.addCar(std::make_shared<OldCar>("VIN010", "Chevrolet", "Impala", 2015, 13000, "Old", 50000));
          inventory.addCar(std::make_shared<OldCar>("VIN011", "Nissan", "Altima", 2014, 12000, "Old", 90000));

    int choice;

    do {
        std::cout << "\n================ Abrar's Premier Dealership  ================\n";
        std::cout << "1. Search Inventory\n";
        std::cout << "2. Sell Car\n";
        std::cout << "3. Add Car to Inventory\n";
        std::cout << "4. List All Cars\n";
        std::cout << "5. Search by Price Range\n";
        std::cout << "6. Exit\n";
        std::cout << "======================================================\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                searchInInventory(inventory);
                break;
            case 2:
                sellCarFromInventory(inventory);
                break;
            case 3:
                addCarToInventory(inventory);
                break;
            case 4:
                inventory.listAllCars();
                break;
            case 5:
                searchByPriceRange(inventory);
                break;
            case 6:
                std::cout << "Exiting the system.\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}

void addCarToInventory(Inventory& inventory) {
    std::string VIN, make, model, category, warrantyProvider;
    int year, choice;
    float price;
    int mileage;

    std::cout << "Enter in car details:\n";
    std::cout << "VIN: ";
    std::cin >> VIN;
    std::cout << "Make: ";
    std::cin >> make;
    std::cout << "Model: ";
    std::cin >> model;
    std::cout << "Year: ";
    std::cin >> year;
    std::cout << "Price $: ";
    std::cin >> price;
    std::cout << "Category (Enter 1 for New, 2 for Old): ";
    std::cin >> choice;

    if (choice == 1) {
        category = "New";
        std::cout << "Warranty Provider: ";
        std::cin >> warrantyProvider;
        auto newCar = std::make_shared<NewCar>(VIN, make, model, year, price, category, warrantyProvider);
        inventory.addCar(newCar);
    } else if (choice == 2) {
        category = "Old";
        std::cout << "Mileage: ";
        std::cin >> mileage;
        auto oldCar = std::make_shared<OldCar>(VIN, make, model, year, price, category, mileage);
        inventory.addCar(oldCar);
    } else {
        std::cout << "Invalid category.\n";
    }
}


void sellCarFromInventory(Inventory& inventory) {
    std::string VIN;
    std::cout << "Enter VIN of the car to sell: ";
    std::cin >> VIN;
    inventory.sellCar(VIN);
}

void searchInInventory(const Inventory& inventory) {
    int searchChoice;
    std::cout << "Search by:\n";
    std::cout << "1. Make\n";
    std::cout << "2. Model\n";
    std::cout << "3. Year\n";
    std::cout << "4. Category\n";
    std::cout << "Enter your choice: ";
    std::cin >> searchChoice;

    std::string inputStr;
    int inputInt;
    std::vector<std::shared_ptr<Car>> results;

    switch (searchChoice) {
        case 1:
            std::cout << "Enter make: ";
            std::cin >> inputStr;
            results = inventory.searchByMake(inputStr);
            break;
        case 2:
            std::cout << "Enter model: ";
            std::cin >> inputStr;
            results = inventory.searchByModel(inputStr);
            break;
        case 3:
            std::cout << "Enter year: ";
            std::cin >> inputInt;
            results = inventory.searchByYear(inputInt);
            break;
        case 4:
            std::cout << "Enter category: ";
            std::cin >> inputStr;
            results = inventory.searchByCategory(inputStr);
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            return;
    }

    if (results.empty()) {
        std::cout << "No cars found matching your provided criteria.\n";
    } else {
        std::cout << "Cars found:\n";
        for (const auto& car : results) {
            car->displayInfo();
        }
    }
}
void searchByPriceRange(Inventory& inventory) {
    float minPrice, maxPrice;
    std::vector<std::shared_ptr<Car>> results;

    std::cout << "Enter minimum price $: ";
    std::cin >> minPrice;
    std::cout << "Enter maximum price $: ";
    std::cin >> maxPrice;

    results = inventory.searchByPriceRange(minPrice, maxPrice);

    if (results.empty()) {
        std::cout << "No cars found within the given price range.\n";
    } else {
        std::cout << "Cars found within the given price range:\n";
        for (const auto& car : results) {
            car->displayInfo();
        }
    }
}
