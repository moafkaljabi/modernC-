#include "updateRecord.h"

void updateRecord(sql::Connection *con, int employeeId, const std::string &firstName, const std::string &lastName, int age, const std::string &birthDate, const std::string &gender) {
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
