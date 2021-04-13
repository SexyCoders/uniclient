#include <mariadb/mysql.h>
#include <uniclient.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef DATABASE_H
#define DATABASE_H

namespace UniClient
{

class Database
    {
        //private:
        public:
            Database()
                {
                }
            ~Database()
                {
                }
            int exec()
                {
                    MYSQL *conn;
                    conn = mysql_init(NULL);
                    mysql_real_connect(conn, "localhost", "uniclient", "testkey", "uniclient", 0, NULL, 0);
                    mysql_query(conn,"CREATE TABLE TEST (TEST TEXT);");
                    mysql_close(conn);
                }
    };

}
#endif
