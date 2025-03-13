#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

// Employee structure
struct Employee {
    int id;
    std::string name;
    std::string position;
    double salary;
};

// Function declarations
void addEmployee(std::vector<Employee>& employees);
void displayEmployees(const std::vector<Employee>& employees);
void updateEmployee(std::vector<Employee>& employees);
void deleteEmployee(std::vector<Employee>& employees);
void saveToFile(const std::vector<Employee>& employees, const std::string& filename);
void loadFromFile(std::vector<Employee>& employees, const std::string& filename);

int main() {
    std::vector<Employee> employees;
    loadFromFile(employees, "employees.txt");

    int choice;
    do {
        // Display the menu
        std::cout << "\nEmployee Management System\n";
        std::cout << "1. View Employees\n";
        std::cout << "2. Add Employee\n";
        std::cout << "3. Edit Employee\n";
        std::cout << "4. Delete Employee\n";
        std::cout << "5. Save and Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();  // Ignore leftover newline character

        switch (choice) {
            case 1:
                displayEmployees(employees);
                break;
            case 2:
                addEmployee(employees);
                break;
            case 3:
                updateEmployee(employees);
                break;
            case 4:
                deleteEmployee(employees);
                break;
            case 5:
                saveToFile(employees, "employees.txt");
                std::cout << "Changes saved. Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

// Function to add an employee
void addEmployee(std::vector<Employee>& employees) {
    Employee employee;
    std::cout << "Enter ID: ";
    std::cin >> employee.id;
    std::cin.ignore();  // Ignore leftover newline character
    std::cout << "Enter Name: ";
    std::getline(std::cin, employee.name);
    std::cout << "Enter Position: ";
    std::getline(std::cin, employee.position);
    std::cout << "Enter Salary: ";
    std::cin >> employee.salary;
    std::cin.ignore();  // Ignore leftover newline character
    employees.push_back(employee);
    std::cout << "Employee added.\n";
}

// Function to display all employees
void displayEmployees(const std::vector<Employee>& employees) {
    std::cout << "Current Employees:\n";
    for (const auto& employee : employees) {
        std::cout << "ID: " << employee.id 
                  << ", Name: " << employee.name 
                  << ", Position: " << employee.position 
                  << ", Salary: " << employee.salary << std::endl;
    }
}

// Function to update an employee
void updateEmployee(std::vector<Employee>& employees) {
    int id;
    std::cout << "Enter ID of the employee to update: ";
    std::cin >> id;
    std::cin.ignore();  // Ignore leftover newline character

    for (auto& employee : employees) {
        if (employee.id == id) {
            std::cout << "Enter new Name: ";
            std::getline(std::cin, employee.name);
            std::cout << "Enter new Position: ";
            std::getline(std::cin, employee.position);
            std::cout << "Enter new Salary: ";
            std::cin >> employee.salary;
            std::cin.ignore();  // Ignore leftover newline character
            std::cout << "Employee updated.\n";
            return;
        }
    }
    std::cout << "Employee not found.\n";
}

// Function to delete an employee
void deleteEmployee(std::vector<Employee>& employees) {
    int id;
    std::cout << "Enter ID of the employee to delete: ";
    std::cin >> id;
    std::cin.ignore();  // Ignore leftover newline character

    auto it = std::remove_if(employees.begin(), employees.end(), [id](const Employee& employee) {
        return employee.id == id;
    });
    if (it != employees.end()) {
        employees.erase(it, employees.end());
        std::cout << "Employee deleted.\n";
    } else {
        std::cout << "Employee not found.\n";
    }
}

// Function to save employees to a file
void saveToFile(const std::vector<Employee>& employees, const std::string& filename) {
    std::ofstream outFile(filename);
    for (const auto& employee : employees) {
        outFile << employee.id << "," << employee.name << "," << employee.position << "," << employee.salary << "\n";
    }
}

// Function to load employees from a file
void loadFromFile(std::vector<Employee>& employees, const std::string& filename) {
    std::ifstream inFile(filename);
    Employee employee;
    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        std::string token;
        std::getline(iss, token, ',');
        employee.id = std::stoi(token);
        std::getline(iss, employee.name, ',');
        std::getline(iss, employee.position, ',');
        std::getline(iss, token, ',');
        employee.salary = std::stod(token);
        employees.push_back(employee);
    }
}
