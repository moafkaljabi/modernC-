#include <iostream>
#include <cstring>

class MyString {
private:
    char* data;
    size_t length;

public:
    // Default constructor
    MyString() : data(nullptr), length(0) {}

    // Parameterized constructor
    MyString(const char* str) {
        if (str) {
            length = std::strlen(str);
            data = new char[length + 1];
            std::strcpy(data, str);
        } else {
            data = nullptr;
            length = 0;
        }
    }

    // Copy constructor
    MyString(const MyString& other) {
        length = other.length;
        data = new char[length + 1];
        std::strcpy(data, other.data);
    }

    // Destructor
    ~MyString() {
        delete[] data;
    }

    // Copy assignment operator
    MyString& operator=(const MyString& other) {
        if (this == &other) {
            return *this;
        }
        delete[] data;
        length = other.length;
        data = new char[length + 1];
        std::strcpy(data, other.data);
        return *this;
    }

    // size() or length()
    size_t size() const {
        return length;
    }

    // c_str()
    const char* c_str() const {
        return data;
    }

    // Operator[]
    char& operator[](size_t index) {
        return data[index];
    }

    const char& operator[](size_t index) const {
        return data[index];
    }
};

int main() {
    MyString str1("Hello");
    MyString str2(str1); // Copy constructor
    MyString str3;
    str3 = str1; // Copy assignment operator
    std::cout << "String 1: " << str1.c_str() << " (size: " << str1.size() << ")\n";
    std::cout << "String 2: " << str2.c_str() << " (size: " << str2.size() << ")\n";
    std::cout << "String 3: " << str3.c_str() << " (size: " << str3.size() << ")\n";
    std::cout << "Character at index 1: " << str1[1] << '\n'; // Access operator
    return 0;
}



























