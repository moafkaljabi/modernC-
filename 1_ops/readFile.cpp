#include <iostream>
#include <future>
#include <thread>
#include <chrono>
#include <memory>
#include <vector>
#include <fstream>



void ReadFile(){
    
    // Create a file objec to read  the file 
    std::ifstream file("data.txt");
    
    // Create a Vector to store the data
    std::vector<std::string> data;
    
    if(file.is_open()){
    
        std::string line;

    while(std::getline(file,line)){
        data.push_back(line);
        
        std::cout << line << std::endl;
    }

    file.close();
    }

    else {

        std::cout << "Unabele to open the file\n";
    }
}


int main() {
 
    ReadFile();
}