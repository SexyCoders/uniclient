#include <microsun.h>
#include <m_database.h>
#include <phpcpp.h>
#include <sqlite3.h>

Php::Value Microsun::Database::CheckDb()
    {
        sqlite3* db;
        sqlite3_open(this->getDBPath().c_str(),&db);
        char* ErrorMsg=(char*) malloc(1000*sizeof(char));
        int flag=sqlite3_exec(db,"SELECT name FROM sqlite_master WHERE type='table' AND name='CUSTOMERS' OR name='CBOARDS';",NULL,NULL,&ErrorMsg);
    if(flag!=0)
        {
            printf("%s",ErrorMsg);
            free(ErrorMsg);
        return (Php::Value) 1;
        }
    else
        {
            free(ErrorMsg);
        return (Php::Value) 0;
        }
    }
