#include "connectToDatabase.h"

void connectToDatabase(sql::Connection *&con, const std::string &host, const std::string &user, const std::string &password, const std::string &database) {
    try {
        sql::mysql::MySQL_Driver *driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect(host, user, password);
        con->setSchema(database);
    } catch (sql::SQLException &e) {
        std::cerr << "SQLException: " << e.what() << std::endl;
    }
}
