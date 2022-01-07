#include <microsun.h>
#include <uniclient.h>
#include <etc.h>
#include <data.h>
#include <mariadb/mysql.h>
#include <phpcpp.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>

#ifndef UNICLIENT_DATABASE_H
#define UNICLIENT_DATABASE_H

namespace UniClient {
class Database : public Php::Base
    {
        private:
            //config file
            char* configd;
            char* passwd_file;
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

                    this->configd=(char*) malloc((strlen("/etc/uniclient/")+1)*sizeof(char));
                    strcpy(this->configd,"/etc/uniclient/");
                    printf("condig dir=%s\n",this->configd);

                    this->passwd_file=(char*) malloc((strlen("passwd")+1)*sizeof(char));
                    strcpy(this->passwd_file,"passwd");
                    printf("passwd file=CONFDIR/%s\n",this->passwd_file);

                    printf("\n");

                    printf("credentials:\n");

                    this->user=(char*) malloc((strlen("uniclient")+1)*sizeof(char));
                    strcpy(this->user,"uniclient");
                    printf("user=%s\n",this->user);

                    std::string temp_string=this->configd;
                    temp_string+=this->passwd_file;
                    FILE* pwdfile=fopen(temp_string.c_str(),"r");
                    //password is sha256 hashed
                    char* buffer=(char*)malloc(65*sizeof(char));
                    if(fscanf(pwdfile,"%s",buffer)==-1)
                        exit(1);

                    this->passwd=(char*) malloc((strlen(buffer)+1)*sizeof(char));
                    strcpy(this->passwd,buffer);
                    printf("passwd=%s\n",this->passwd);

                    printf("\n");

                    printf("TCP:\n");

                    this->host=(char*) malloc((strlen("10.0.0.33")+1)*sizeof(char));
                    strcpy(this->host,"10.0.0.33");
                    printf("host=%s\n",this->host);

                    this->port=3306;
                    printf("port=%u\n",this->port);

                    printf("\n");

                    //printf("Unix Domain:\n");

                    //this->unix_socket=(char*) malloc((strlen("/var/run/mysqld/mysqld.sock")+1)*sizeof(char));
                    //strcpy(this->unix_socket,"/var/run/mysqld/mysqld.sock");
                    //printf("unix socket=%s\n",this->unix_socket);
                    this->unix_socket=NULL;

                    printf("\n");

                    printf("Database Names:\n");

                    this->system=(char*) malloc((strlen("main")+1)*sizeof(char));
                    strcpy(this->system,"main");
                    printf("system=%s\n",this->system);

                    this->microsun=(char*) malloc((strlen("microsun")+1)*sizeof(char));
                    strcpy(this->microsun,"microsun");
                    printf("microsun=%s\n",this->microsun);

                    //this->testing=(char*) malloc((strlen("TESTING")+1)*sizeof(char));
                    //strcpy(this->testing,"TESTING");
                    //printf("testing=%s\n",this->testing);

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
                    //free(this->unix_socket);
                    //free(this->testing);
                }
            //int get(std::string param,unsigned int id,UniClient::Customer* out);
//            int put(std::string param,UniClient::data::Customer* in);
// 
//            unsigned long int getLastInsertId(std::string table);
//
            //system functions
            
            //users -  groups
            int get_user(std::string username,std::string grp,UniClient::etc::User* result);
            void get_groups();
            Php::Value getGroupMembers(Php::Parameters &group);
            
            //system data
            Php::Value getCustomers();//bulk
            Php::Value getPlants();//bulk
            Php::Value getCounties();//bulk
            Php::Value getCountyNames();//bulk
            UniClient::Microsun::Plant* getPlant(std::string ID);
            std::string getPlantDebug(std::string ID);//debug
            UniClient::data::County* getCountyByName(std::string name);
//            UniClient::data::Customer* getCustomerByCompanyName(std::string name);

            //microsun dataclasses
//            UniClient::Microsun::Plant* getPlant(std::string ID);
            UniClient::Microsun::Panel* getPanelById(unsigned long int id);
            Php::Value getPanels();
            Php::Value getPanelModels();
            UniClient::Microsun::Mounter* getMounterByName(std::string Name);
            Php::Value getMounters();
            Php::Value getMounterNames();
            UniClient::Microsun::Inverter* getInverterByModel(std::string model);
            Php::Value getInverters();
            Php::Value getInverterModels();
            UniClient::Microsun::CBoard* getCboardByID(unsigned long int id);
            Php::Value getCboards();
            Php::Value getCboardModels();
            UniClient::Microsun::Constructor* getConstructorByCompany(std::string company);
            Php::Value getConstructors();
            Php::Value getConstructorCompanies();

            //microsun error functions
            Php::Value getPending();//bulk
            Php::Value getPendingCount();
            Php::Value getStored();//bulk
            Php::Value newError(Php::Parameters &arg);//stores in pending_errors
            Php::Value tempError(Php::Parameters &arg);//moves pending_errors->temp_stored_errors
            Php::Value resolve_error(Php::Parameters &arg);//moves temp_stored_errors->error_log
            unsigned long long int getSingle(UniClient::Microsun::Problem* problem,unsigned long long int id,std::string table);
            unsigned long long int deleteError(std::string table,unsigned long long int id);
//            unsigned long int store_new_error(UniClient::Microsun::Problem* error);
//            std::string store_error(UniClient::Microsun::Problem* error,std::string table);
//            int delete_error(int ID_TO_DELETE,std::string table);
//            Php::Value getPlantLog(Php::Parameters &arg);
//            //!!!!!!!!!!!!!!!!!!!!!!
//            //LOG ERROR NEEDS TO BE REPLACED BY SWITCH INSIDE STORE ERROR TO USE BOTH DATABASES
//            //!!!!!!!!!!!!!!!!!!!!!!
//            std::string log_error(UniClient::Microsun::Problem* error,std::string table);
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
            unsigned long long int storeError(UniClient::Microsun::Problem* error,std::string table);
// 
    };

};
#endif
