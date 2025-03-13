#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h> // Include this for sql::Statement
#include "../config.h"

int main() {
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;

    try {
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect(DB_HOST, DB_USER, DB_PASSWORD); // Update credentials if needed

        con->setSchema(DB_NAME); // Replace with your database name

        sql::Statement *stmt = con->createStatement();

        // Example: Insert a new device
        std::string insertQuery = "INSERT INTO Devices (PersonID, DeviceName, DeviceStatus) VALUES (1, 'My BLDC Motor', 'on')";
        stmt->execute(insertQuery);

        // Example: Update device status
        std::string updateQuery = "UPDATE Devices SET DeviceStatus = 'off' WHERE DeviceName = 'My BLDC Motor'";
        stmt->execute(updateQuery);

        delete stmt;
        delete con;
    } catch (sql::SQLException &e) {
        std::cerr << "SQLException: " << e.what() << std::endl;
    }

    return 0;
}
