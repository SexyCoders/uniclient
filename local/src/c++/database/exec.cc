#include <cstring>
#include <database.h>
#include <mariadb/mysql.h>
#include <vector>

//overload for statements with return 
int UniClient::Database::insert(MYSQL_BIND* params,int param_n,std::string table)
	{
		MYSQL *conn;
		conn = mysql_init(NULL);
		MYSQL_STMT *stmt= mysql_stmt_init(conn);
		mysql_stmt_attr_set(stmt, STMT_ATTR_PREBIND_PARAMS,&param_n);
		mysql_stmt_bind_param(stmt,params);
		std::string sql="INSERT INTO"+table+"VALUES(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?);";
		mariadb_stmt_execute_direct(stmt,sql.c_str(),-1);
		mysql_stmt_close(stmt);
		mysql_close(conn);
	return 0;
	}

////overload for statements with NO return 
//int UniClient::Database::exec(const char* SQL)
	//{
		//MYSQL *conn;
		//conn = mysql_init(NULL);
		//char* buffer=(char*)malloc(2*strlen(SQL)*sizeof(char));
		//mysql_real_connect(conn,this->host,this->user,this->passwd,this->database,0,NULL,0);
		//mysql_real_escape_string(conn,buffer,SQL,strlen(SQL));
		//mysql_real_query(conn,buffer,strlen(buffer));
		//free(buffer);
		//mysql_close(conn);
	//return 0;
	//}

