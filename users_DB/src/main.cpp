// #include "../include/main.h"

#include "../include/main.h"
#include "../MySQLHandler/MySQLHandler.h"

void displayMenu() {
    std::cout << "Choose an operation:\n"
              << "1. Read\n"
              << "2. Add\n"
              << "3. Delete\n"
              << "4. Update\n";
}

int main() {
    MySQLHandler dbHandler;

    std::string host = "tcp://127.0.0.1:3306";
    std::string user = "root";
    std::string password = "2222";
    std::string database = "Parks_and_Recreation";

    dbHandler.connectToDatabase(host, user, password, database);

    int choice;
    displayMenu();
    std::cin >> choice;

    if (choice == 1) {
        std::string records = dbHandler.readRecords();
        std::cout << records;
    } else if (choice == 2) {
        int employeeId;
        std::string firstName, lastName, birthDate, gender;
        int age;
        std::cout << "Enter employee ID, first name, last name, age, birth date (YYYY-MM-DD), gender: ";
        std::cin >> employeeId >> firstName >> lastName >> age >> birthDate >> gender;
        dbHandler.addRecord(employeeId, firstName, lastName, age, birthDate, gender);
    } else if (choice == 3) {
        int employeeId;
        std::cout << "Enter employee ID to delete: ";
        std::cin >> employeeId;
        dbHandler.deleteRecord(employeeId);
    } else if (choice == 4) {
        int employeeId;
        std::string firstName, lastName, birthDate, gender;
        int age;
        std::cout << "Enter employee ID to update, then new first name, last name, age, birth date (YYYY-MM-DD), gender: ";
        std::cin >> employeeId >> firstName >> lastName >> age >> birthDate >> gender;
        dbHandler.updateRecord(employeeId, firstName, lastName, age, birthDate, gender);
    } else {
        std::cout << "Invalid choice" << std::endl;
    }

    return 0;
}
