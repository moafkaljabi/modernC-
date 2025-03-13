#include <cstring>
#include <iostream>

class MyString{
private:
    char* data;
    size_t length;

public:

// Default constructor
MyString(): data(nullptr), length(0){}

// Parameterized constructor 
MyString(const char* str) {
    // check if empty
    if (str) {
        length = std::strlen(str);
        data = new char [length + 1];
        std::strcpy(data,str);

    } else {
        str = nullptr;
        length = 0;
    }
}


// Copy constructor 
MyString(MyString& myCopy) {
    length = myCopy.length;
    data = new char [length +1];
    std::strcpy(data,myCopy.data);
}

// Destructor
    ~MyString(){
        delete [] data;
    }


// Copy assignment constructor
MyString& operator=(const MyString& other){
    if(this == &other) {
        return *this;
    } else {
        delete [] data;
        length = other.length;
        data = new char[length + 1];
        std::strcpy(data,other.data);
        return *this;};
}

// Size()
size_t size() {
    return length;
}

// c_str()

const char* c_str()const{
    return data;

}

// Operator []

char& operator[](size_t index){
    return data[index];
}

// Operator [] only read
const char& operator[] (size_t index) const {
    return data[index];
}
};


int main(){


    return 0;
}