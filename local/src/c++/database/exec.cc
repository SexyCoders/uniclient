#include <cstring>
#include <database.h>
#include <mariadb/mysql.h>
#include <vector>

static void err_exit(const char* s){
    perror(s);
    perror("\n");
    exit(1);
}

//overload for statements with return 
//int UniClient::Database::insert(MYSQL_BIND* params,int param_n,std::string table)
//	{
//		printf("Starting insert\n");
//		MYSQL *mysql=mysql_init(NULL);
//		if (mysql == NULL) err_exit("init db failed");
//		mysql_real_connect(mysql,this->host,this->user,this->passwd,this->database,this->port,NULL,0);
//		//printf("%s\n",mysql_error(mysql));
//		//printf("test\n");
//		//printf("test\n");
//		MYSQL_STMT *stmt= mysql_stmt_init(mysql);
//		if (stmt == NULL) err_exit("init stmt failed");
// 
//		std::string sql="INSERT INTO "+table+" VALUES(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
//		mysql_stmt_prepare(stmt,sql.c_str(),sql.length());
//		//mysql_stmt_attr_set(stmt, STMT_ATTR_PREBIND_PARAMS,&param_n);
//		//printf("test\n");
//		//printf("test\n");
//		//printf("%s\n",sql.c_str());
//		mysql_stmt_bind_param(stmt,params);
//		mysql_stmt_execute(stmt);
//		//printf("test\n");
//		mysql_stmt_close(stmt);
//		printf("insert end\n");
//		//mysql_close(mysql);
//	return 0;
//	}
// 
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

