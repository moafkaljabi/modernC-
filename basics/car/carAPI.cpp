#include <iostream>
#include <string>
#include <optional>
#include <vector>

// Define the Car class
class Car {
public:
    std::string make;
    std::string model;
    int year;
    std::optional<std::string> color;

    // Constructor with member initializer list
    // Initializes member variables directly using constructor parameters
    Car(const std::string &carMake,
        const std::string &carModel,
        int carYear,
        std::optional<std::string> carColor = std::nullopt)
        : make(carMake), model(carModel), year(carYear), color(carColor) {}
};

// Define the global vector to store Car objects after the Car class definition
std::vector<Car> Cars;


// Function to print all cars
void printCars() {
    for (const Car &car : Cars) {
        std::cout << "Make: " << car.make << ", Model: " << car.model << ", Year: " << car.year;
        if (car.color) {
            std::cout << ", Color: " << *car.color;
        }
        std::cout << std::endl;
    }
}



// Function to print a string (not used in the current main.cpp, but kept here for completeness)
void toPrint(const std::string &input) {
    std::cout << input << std::endl;
}


// Function to add a car to the list
void addCar(const Car &newCar) {
    Cars.push_back(newCar);
}

// Function to delete a car from the list by index
void deleteCar(size_t index) {
    if (index < Cars.size()) {
        Cars.erase(Cars.begin() + index);
    } else {
        std::cout << "Invalid index" << std::endl;
    }
}

