#include <mariadb/mysql.h>
#include <uniclient.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <customer.h>

#ifndef DATABASE_H
#define DATABASE_H

namespace UniClient
{

class Database
    {
        private:
            char* host;
            char* user;
            char* passwd;
            char* database;
        public:
            Database()
                {
                    this->host=(char*) malloc((strlen("localhost")+1)*sizeof(char));
                    strcpy(this->host,"localhost");
                    this->user=(char*) malloc((strlen("uniclient")+1)*sizeof(char));
                    strcpy(this->user,"uniclient");
                    this->passwd=(char*) malloc((strlen("testkey")+1)*sizeof(char));
                    strcpy(this->passwd,"testkey");
                    this->database=(char*) malloc((strlen("uniclient")+1)*sizeof(char));
                    strcpy(this->database,"uniclient");
                }
            ~Database()
                {
                    free(this->host);
                    free(this->user);
                    free(this->passwd);
                    free(this->database);
                }
            int get(std::string param,unsigned int id,UniClient::Customer* out);
            int put(std::string param,UniClient::Customer* in);
        //private:
            int exec(const char* SQL);
            int exec(const char* SQL,std::vector<std::vector<std::string>>* out); 
            int exec(std::string SQL)
                {
                    this->exec(SQL.c_str());
                };
    };

}
#endif
