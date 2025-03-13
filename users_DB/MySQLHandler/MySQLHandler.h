#pragma once


#ifndef MYSQLHANDLER_H
#define MYSQLHANDLER_H

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include <string>

class MySQLHandler {
public:
    sql::Connection *con;
    MySQLHandler();
    ~MySQLHandler();
    void connectToDatabase(const std::string &host, const std::string &user, const std::string &password, const std::string &database);
    void addRecord(int employeeId, const std::string &firstName, const std::string &lastName, int age, const std::string &birthDate, const std::string &gender);
    void deleteRecord(int employeeId);
    void updateRecord(int employeeId, const std::string &firstName, const std::string &lastName, int age, const std::string &birthDate, const std::string &gender);
    std::string readRecords();
};

#endif // MYSQLHANDLER_H
