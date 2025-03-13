#include "readRecord.h"

std::string readRecords(sql::Connection *con) {
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
