#include <string>
#include "carAPI.cpp"


int main() {
    // Add some cars
    addCar(Car("Ford", "Mustang", 2023, "Red"));
    addCar(Car("Toyota", "Camry", 2021));
    addCar(Car("Honda", "Civic", 2022, "Blue"));

    toPrint("Initial car list:");
    printCars();

    // Delete a car
    deleteCar(1);


    toPrint("After deletion:");
    
    printCars();

    return 0;
}
