#include <boost/asio/detail/chrono.hpp>
#include <boost/beast/websocket/rfc6455.hpp>
#include <iostream>



class Entity{

public:
std::string name; 
int grade;
    // Default constructor 
    Entity(std::string m_name, int m_grade): name(m_name), grade(m_grade){};

    // void display(std::string name, int grade){
       
    //     std::cout << name << ","<< grade << std::endl;
    // }
    // Copy constructor 
};


int main(){

    Entity e("mark",100);
    std::cout << e.grade << std::endl << e.name << std::endl;
    Entity e2(e);
    std::cout << e2.grade << std::endl << e2.name << std::endl;
    return 0;
}