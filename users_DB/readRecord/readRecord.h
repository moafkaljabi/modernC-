#pragma once


#ifndef READ_RECORDS_H
#define READ_RECORDS_H

#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <string>

std::string readRecords(sql::Connection *con);

#endif // READ_RECORDS_H
