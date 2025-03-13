#include <cstddef>
#include <iostream>
#include <vector>
#include <string>
#include <optional>


// Create class Cars 
class Car {
public:
    std::string make;
    std::string model;
    int year;
    std::optional<std::string> color;

// constructor 

    Car(
        const std::string &carMake,
        const std::string &carModel,
        int carYear,
        std::optional<std::string> carColor = std::nullopt)
        : make (carMake),
          model (carModel),
          year(carYear),
          color(carColor)
        {}
};

//define the vector of cars

std::vector<Car> Cars;


// define Cars printing function

void printCars(){
    for(const Car &car: Cars){
        std::cout << "Car make:" << car.make << std::endl<< "Car model:" << car.model << std::endl <<"Car year: " << car.year << std::endl;
        if (car.color){
            std::cout << "Car color: "<< *car.color << std::endl;
        }
        
    }
}


// print function
void toPrint(const std::string &input){
    std::cout << input << std::endl;
}



// addCar function 
void addCar (const Car &addedCar){
Cars.push_back(addedCar);
}



// deleteCar function
void deleteCar(size_t index){

if (Cars.size() < index){
    Cars.erase(Cars.begin()+ index);}
else {
    toPrint("Index invalid");
     }
}

