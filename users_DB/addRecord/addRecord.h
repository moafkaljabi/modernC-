#pragma once


#include "../MySQLHandler/connectToDatabase/connectToDatabase.h"

void connectToDatabase(sql::Connection *&con, const std::string &host, const std::string &user, const std::string &password, const std::string &database);
