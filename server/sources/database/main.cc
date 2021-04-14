#include <database.h>
#include <mariadb/mysql.h>
#include <stdlib.h>

int main()
	{

		UniClient::Database* database=new UniClient::Database();
		database->exec("SELECT * FROM TEST;");
	}
