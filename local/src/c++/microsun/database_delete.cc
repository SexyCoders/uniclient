#include <database.h>
#include <sqlite3.h>
#include <stdlib.h>
#include <iostream>
#include <string>

Php::Value Microsun::Database::del(Php::Parameters &arg)
    {
        int check=-1;
        if(arg[0]=="customer_del")
            {
                sqlite3* db;
                sqlite3_open(this->getDBPath(),&db);
                std::string sql("DELETE FROM CUSTOMERS WHERE ID="+std::to_string(arg[1].numericValue())+";");
                char* errmsg=(char*) malloc(1000*sizeof(char));
                check=sqlite3_exec(db, sql.c_str(),NULL,NULL,&errmsg);
            }
        if(check)
            return check;
        else
            return 0;
    }
