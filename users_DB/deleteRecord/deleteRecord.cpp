#include "deleteRecord.h"

void deleteRecord(sql::Connection *con, int employeeId) {
    try {
        sql::PreparedStatement *pstmt = con->prepareStatement("DELETE FROM employee_demographics WHERE employee_id = ?");
        pstmt->setInt(1, employeeId);
        pstmt->execute();
        delete pstmt;
    } catch (sql::SQLException &e) {
        std::cerr << "SQLException: " << e.what() << std::endl;
    }
}
