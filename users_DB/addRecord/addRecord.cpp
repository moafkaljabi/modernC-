#include "addRecord.h"
#include <cppconn/prepared_statement.h> // Add this line
#include <mysql_driver.h>
#include <mysql_connection.h>


void addRecord(sql::Connection *con, int employeeId, const std::string &firstName, const std::string &lastName, int age, const std::string &birthDate, const std::string &gender) {
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
