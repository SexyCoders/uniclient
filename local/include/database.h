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
            unsigned int port;
        public:
            Database()
                {
                    printf("config info:\n");
                    this->host=(char*) malloc((strlen("127.0.0.1")+1)*sizeof(char));
                    strcpy(this->host,"127.0.0.1");
                    printf("host=%s\n",this->host);
                    this->user=(char*) malloc((strlen("uniclient")+1)*sizeof(char));
                    strcpy(this->user,"uniclient");
                    printf("user=%s\n",this->user);
                    this->passwd=(char*) malloc((strlen("uniclient")+1)*sizeof(char));
                    strcpy(this->passwd,"uniclient");
                    printf("passwd=%s\n",this->passwd);
                    this->database=(char*) malloc((strlen("MAIN")+1)*sizeof(char));
                    strcpy(this->database,"MAIN");
                    printf("database=%s\n",this->database);
                    this->port=3306;
                    printf("port=%u\n",this->port);
                }
            ~Database()
                {
                    free(this->host);
                    free(this->user);
                    free(this->passwd);
                    free(this->database);
                }
            //int get(std::string param,unsigned int id,UniClient::Customer* out);
            int put(std::string param,UniClient::Customer* in);
        private:
            int insert(MYSQL_BIND* params,int param_n,std::string table);
            //int exec(const char* SQL);
            //int exec(const char* SQL,std::vector<std::vector<std::string>>* in); 
            //int exec(std::string SQL)
                //{
                    //return this->exec(SQL.c_str());
                //};

    };

}
#endif
