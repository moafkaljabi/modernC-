#include <iostream>
#include <vector>
#include <thread>
#include <memory>
#include <chrono>
#include <fstream>


std::unique_ptr<std::thread> threads;



int main()
{
    std::this_thread::get_id();
    std::cout << "Main thread id: " << std::this_thread::get_id() << std::endl;
}