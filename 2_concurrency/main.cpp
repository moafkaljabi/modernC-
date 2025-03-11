#include <iostream>
#include <thread>
#include <vector>
#include <fstream>
#include <memory>

// std::vector<std::shared_ptr<std::ofstream>> files;

jthread create_thread()
{
    return jthread([]{
        std::cout << "Hello from thread" << std::this_thread::get_id() << std::endl;
    });
}

void read_file(const std::string& filename)
{
    std::ifstream file(filename);
    std::string line;

    while(getline(file, line))
    {
        std::cout << line << std::endl;
    }
}




int main() 
{
    read_file("data.txt");
}


