#pragma once

#ifndef UPDATE_RECORD_H
#define UPDATE_RECORD_H

#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>
#include <string>

void updateRecord(sql::Connection *con, int employeeId, const std::string &firstName, const std::string &lastName, int age, const std::string &birthDate, const std::string &gender);

#endif // UPDATE_RECORD_H
