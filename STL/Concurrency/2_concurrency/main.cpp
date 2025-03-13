#include <iostream>
#include <thread>
#include <vector>
#include <fstream>
#include <memory>

// std::vector<std::shared_ptr<std::ofstream>> files;

std::jthread create_thread()
{
    return std::jthread([](std::stop_token stoken)
    {
        while(!stoken.stop_requested())
        {
            std::cout << "Thread is running" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
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


