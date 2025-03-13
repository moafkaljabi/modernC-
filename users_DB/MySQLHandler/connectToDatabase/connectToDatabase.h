#pragma once


#ifndef CONNECT_TO_DATABASE_H
#define CONNECT_TO_DATABASE_H

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/exception.h>
#include <string>

void connectToDatabase(sql::Connection *&con, const std::string &host, const std::string &user, const std::string &password, const std::string &database);

#endif // CONNECT_TO_DATABASE_H
