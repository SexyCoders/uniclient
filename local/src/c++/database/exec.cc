#include <cstring>
#include <database.h>
#include <mariadb/mysql.h>
#include <vector>

//overload for statements with return 
int UniClient::Database::exec(const char* SQL,std::vector<std::vector<std::string>>* out)
	{
		MYSQL *conn;
		conn = mysql_init(NULL);
		char* buffer=(char*)malloc(2*strlen(SQL)*sizeof(char));
		mysql_real_connect(conn,this->host,this->user,this->passwd,this->database,0,NULL,0);
		mysql_real_escape_string(conn,buffer,SQL,strlen(SQL));
		mysql_real_query(conn,buffer,strlen(buffer));
		free(buffer);
		MYSQL_RES* result = mysql_store_result(conn);
		MYSQL_ROW t;
		int count=mysql_num_rows(result);
		int fields=mysql_num_fields(result);
		for(int j=0;j<count;j++)
			{
				std::vector<std::string> tmp;
				size_t size=0;
				t=mysql_fetch_row(result);
				for(int i=0;i<fields;i++)
					{
					//printf("%s\n",t[i]);
						std::string s(t[i]);
						tmp.push_back(s);
					}
				out->push_back(tmp);
			}
		mysql_close(conn);
	return 0;
	}

//overload for statements with NO return 
int UniClient::Database::exec(const char* SQL)
	{
		MYSQL *conn;
		conn = mysql_init(NULL);
		char* buffer=(char*)malloc(2*strlen(SQL)*sizeof(char));
		mysql_real_connect(conn,this->host,this->user,this->passwd,this->database,0,NULL,0);
		mysql_real_escape_string(conn,buffer,SQL,strlen(SQL));
		mysql_real_query(conn,buffer,strlen(buffer));
		free(buffer);
		mysql_close(conn);
	return 0;
	}

