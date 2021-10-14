#include <microsun.h>
#include <uniclient.h>
#include <etc.h>
#include <data.h>
#include <mariadb/mysql.h>
#include <phpcpp.h>
#include <string>
#include <stdlib.h>

#ifndef UNICLIENT_DATABASE_H
#define UNICLIENT_DATABASE_H

class test{
    public:
    int id;
    std::string surname;
    std::string forename;
};

namespace UniClient {
class Database : public Php::Base
    {
        private:
            //credentials
            char* user;
            char* passwd;
            //tcp
            char* host;
            unsigned int port;
            //unix domain
            char* unix_socket;
            //database names
            char* system;
            char* microsun;
            char* testing;
        public:
            //runtime data
            std::vector<UniClient::etc::Group> groups;
        public:
            Database()
                {
                    printf("configuring...\n");
                    printf("\n");

                    printf("credentials:\n");

                    this->user=(char*) malloc((strlen("uniclient")+1)*sizeof(char));
                    strcpy(this->user,"uniclient");
                    printf("user=%s\n",this->user);

                    this->passwd=(char*) malloc((strlen("uniclient")+1)*sizeof(char));
                    strcpy(this->passwd,"uniclient");
                    printf("passwd=%s\n",this->passwd);

                    printf("\n");

                    printf("TCP:\n");

                    this->host=(char*) malloc((strlen("localhost")+1)*sizeof(char));
                    strcpy(this->host,"localhost");
                    printf("host=%s\n",this->host);

                    this->port=3306;
                    printf("port=%u\n",this->port);

                    printf("\n");

                    printf("Unix Domain:\n");

                    this->unix_socket=(char*) malloc((strlen("/var/run/mysqld/mysqld.sock")+1)*sizeof(char));
                    strcpy(this->unix_socket,"/var/run/mysqld/mysqld.sock");
                    printf("unix socket=%s\n",this->unix_socket);

                    printf("\n");

                    printf("Database Names:\n");

                    this->system=(char*) malloc((strlen("MAIN")+1)*sizeof(char));
                    strcpy(this->system,"MAIN");
                    printf("system=%s\n",this->system);

                    this->microsun=(char*) malloc((strlen("MICROSUN")+1)*sizeof(char));
                    strcpy(this->microsun,"MICROSUN");
                    printf("microsun=%s\n",this->microsun);

                    this->testing=(char*) malloc((strlen("TESTING")+1)*sizeof(char));
                    strcpy(this->testing,"TESTING");
                    printf("testing=%s\n",this->testing);

                    printf("\n");

                    this->get_groups();
                }
            ~Database()
                {
                    free(this->host);
                    free(this->user);
                    free(this->passwd);
                    free(this->system);
                    free(this->microsun);
                    free(this->unix_socket);
                    free(this->testing);
                }
            //int get(std::string param,unsigned int id,UniClient::Customer* out);
//            int put(std::string param,UniClient::data::Customer* in);
// 
//            unsigned long int getLastInsertId(std::string table);
            int get_user(std::string username,std::string grp,UniClient::etc::User* result);
            void get_groups();
//            Php::Value getCustomers();
//            UniClient::data::Customer* getCustomerByCompanyName(std::string name);
//            UniClient::Microsun::Plant* getPlant(std::string ID);
//            Php::Value getPlants();
            Php::Value getPendingCount();
//            Php::Value getPending();
//            Php::Value getStored();
//            Php::Value tempError(Php::Parameters &arg);
//            Php::Value getMechNames();
//            Php::Value newError(Php::Parameters &arg);
//            unsigned long int store_new_error(UniClient::Microsun::Problem* error);
//            std::string store_error(UniClient::Microsun::Problem* error,std::string table);
//            int delete_error(int ID_TO_DELETE,std::string table);
//            Php::Value resolve_error(Php::Parameters &arg);
//            Php::Value getPlantLog(Php::Parameters &arg);
//            //!!!!!!!!!!!!!!!!!!!!!!
//            //LOG ERROR NEEDS TO BE REPLACED BY SWITCH INSIDE STORE ERROR TO USE BOTH DATABASES
//            //!!!!!!!!!!!!!!!!!!!!!!
//            std::string log_error(UniClient::Microsun::Problem* error,std::string table);
//            UniClient::data::County* getCountyByName(std::string name);
//            UniClient::Microsun::Panel* getPanelByName(std::string Name);
//            UniClient::Microsun::Mounter* getMounterByName(std::string Name);
//            UniClient::Microsun::Inverter* getInverterByModel(std::string Name);
//            UniClient::Microsun::Constructor* getConstructorByCompany(std::string Name);
//        private:
//            int insert(MYSQL_BIND* params,int param_n,std::string table);
//            //int exec(const char* SQL);
//            //int exec(const char* SQL,std::vector<std::vector<std::string>>* in); 
//            //int exec(std::string SQL)
//                //{
//                    //return this->exec(SQL.c_str());
//                //};

            //sql field binding overloads for all classes
            //int bind();
            //int bind(UniClient::Microsun::Problem* problem);
            int storeError(UniClient::Microsun::Problem* error,std::string table);
// 
    };

};
#endif
