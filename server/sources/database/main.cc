//#include <database.h>
#include <mariadb/mysql.h>
#include <stdlib.h>

int main()
	{
                    MYSQL *conn;
                    conn = mysql_init(NULL);
                    mysql_real_connect(conn, "localhost", "uniclient", "testkey", "uniclient", 0, NULL, 0);
                    //mysql_query(conn,"CREATE TABLE TEST (TEST TEXT);");
                    mysql_query(conn,"INSERT INTO TEST VALUES('Hello World!');");
                    mysql_close(conn);
	}
