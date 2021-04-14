#include <database.h>
#include <mariadb/mysql.h>

int UniClient::Database::exec(const char* SQL)
	{
		MYSQL *conn;
		conn = mysql_init(NULL);
		mysql_real_connect(conn,this->host,this->user,this->passwd,this->database,0,NULL,0);
		mysql_real_query(conn,SQL,strlen(SQL));
		MYSQL_RES* result = mysql_store_result(conn);
		MYSQL_ROW t;
		t=mysql_fetch_row(result);
		printf("%s\n",*t);
		mysql_close(conn);
	return 0;
	}

