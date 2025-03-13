#pragma once


#ifndef DELETE_RECORD_H
#define DELETE_RECORD_H

#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>

void deleteRecord(sql::Connection *con, int employeeId);

#endif // DELETE_RECORD_H
