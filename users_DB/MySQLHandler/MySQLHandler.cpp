#include "MySQLHandler.h"

MySQLHandler::MySQLHandler() : con(nullptr) {}

MySQLHandler::~MySQLHandler() {
    if (con) {
        delete con;
    }
}

void MySQLHandler::connectToDatabase(const std::string &host, const std::string &user, const std::string &password, const std::string &database) {
    try {
        sql::mysql::MySQL_Driver *driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect(host, user, password);
        con->setSchema(database);
    } catch (sql::SQLException &e) {
        std::cerr << "SQLException: " << e.what() << std::endl;
    }
}

void MySQLHandler::addRecord(int employeeId, const std::string &firstName, const std::string &lastName, int age, const std::string &birthDate, const std::string &gender) {
    try {
        sql::PreparedStatement *pstmt = con->prepareStatement("INSERT INTO employee_demographics(employee_id, first_name, last_name, age, birth_date, gender) VALUES (?, ?, ?, ?, ?, ?)");
        pstmt->setInt(1, employeeId);
        pstmt->setString(2, firstName);
        pstmt->setString(3, lastName);
        pstmt->setInt(4, age);
        pstmt->setString(5, birthDate);
        pstmt->setString(6, gender);
        pstmt->execute();
        delete pstmt;
    } catch (sql::SQLException &e) {
        std::cerr << "SQLException: " << e.what() << std::endl;
    }
}

void MySQLHandler::deleteRecord(int employeeId) {
    try {
        sql::PreparedStatement *pstmt = con->prepareStatement("DELETE FROM employee_demographics WHERE employee_id = ?");
        pstmt->setInt(1, employeeId);
        pstmt->execute();
        delete pstmt;
    } catch (sql::SQLException &e) {
        std::cerr << "SQLException: " << e.what() << std::endl;
    }
}

void MySQLHandler::updateRecord(int employeeId, const std::string &firstName, const std::string &lastName, int age, const std::string &birthDate, const std::string &gender) {
    try {
        sql::PreparedStatement *pstmt = con->prepareStatement("UPDATE employee_demographics SET first_name = ?, last_name = ?, age = ?, birth_date = ?, gender = ? WHERE employee_id = ?");
        pstmt->setString(1, firstName);
        pstmt->setString(2, lastName);
        pstmt->setInt(3, age);
        pstmt->setString(4, birthDate);
        pstmt->setString(5, gender);
        pstmt->setInt(6, employeeId);
        pstmt->execute();
        delete pstmt;
    } catch (sql::SQLException &e) {
        std::cerr << "SQLException: " << e.what() << std::endl;
    }
}

std::string MySQLHandler::readRecords() {
    std::string result;
    try {
        sql::Statement *stmt = con->createStatement();
        sql::ResultSet *res = stmt->executeQuery("SELECT * FROM employee_demographics");
        while (res->next()) {
            result += "Age: " + std::to_string(res->getInt("age")) + ", "
                    + "Birth Date: " + res->getString("birth_date") + ", "
                    + "Employee ID: " + std::to_string(res->getInt("employee_id")) + ", "
                    + "First Name: " + res->getString("first_name") + ", "
                    + "Gender: " + res->getString("gender") + ", "
                    + "Last Name: " + res->getString("last_name") + "\n";
        }
        delete res;
        delete stmt;
    } catch (sql::SQLException &e) {
        std::cerr << "SQLException: " << e.what() << std::endl;
    }
    return result;
}
