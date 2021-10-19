#include <mariadb/mysql.h>
#include <database.h>
#include <sqlite3.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <any>
#include <vector>
#include <stdlib.h>
#include <my_time.h>
#include <sstream>
#include <cstring>

//MYSQL* mysql;

//static int callback_customer(void* passthrough,int argc,char** argv,char** col)
//        {
//            UniClient::data::Customer* tmp=(UniClient::data::Customer*)passthrough;
//            tmp->ID=atol(argv[0]);
//            tmp->Company=argv[1];
//            tmp->FirstName=argv[2];
//            tmp->LastName=argv[3];
//            tmp->PhoneNumber=atol(argv[4]);
//            tmp->email=argv[5];
//            tmp->Address=argv[6];
//            tmp->zip=atol(argv[7]);
//            tmp->TIN=atol(argv[8]);
//            tmp->Notes=argv[9];
//        return 0;
//        }
// 
// 
//static int callback_customer_all(void* passthrough,int argc,char** argv,char** col)
//        {
//            std::vector<Php::Object>* STORE=(std::vector<Php::Object>*) passthrough;
//            Microsun::Customer* tmp=new Microsun::Customer();
//            tmp->ID=atol(argv[0]);
//            tmp->Company=argv[1];
//            tmp->FirstName=argv[2];
//            tmp->LastName=argv[3];
//            tmp->PhoneNumber=atol(argv[4]);
//            tmp->email=argv[5];
//            tmp->Address=argv[6];
//            tmp->zip=atol(argv[7]);
//            tmp->TIN=atol(argv[8]);
//            tmp->Notes=argv[9];
//            STORE->push_back(Php::Object("MicrosunCustomer",tmp));
//        return 0;
//        }
// 
//Php::Value Microsun::Database::getCustomers()
//    {
//        char* errmsg;
//        std::string sql;
//        sqlite3* db;
//        std::vector<Php::Object> tmp;
//        sql="SELECT ID,COMPANY,IFNULL(NAME,'NAN'),IFNULL(LNAME,'NAN'),IFNULL(PHONE,0),IFNULL(EMAIL,'NAN'),IFNULL(ADDRESS,'NAN'),IFNULL(ZIP,0),IFNULL(TIN,0),IFNULL(NOTES,'NAN') FROM CUSTOMERS;";
//        char* buffer=(char*) malloc(sql.length()*2+1);
//        mysql_real_escape_string(mysql, buffer, sql.c_str(), sql.length());
//        sqlite3_open(this->Path.c_str(),&db);
//        //int check=sqlite3_exec(db, sql.c_str(),callback_customer_all,(void*)&tmp,&errmsg);
//        int check=sqlite3_exec(db, buffer,callback_customer_all,(void*)&tmp,&errmsg);
//        sqlite3_close(db);
//        free(buffer);
//    return tmp; 
//    }
// 
//Microsun::Customer* Microsun::Database::getCustomerByCompanyName(std::string name)
//    {
//        char* errmsg;
//        std::string sql;
//        sqlite3* db;
//        Microsun::Customer* tmp=new Microsun::Customer();
//        sql="SELECT * FROM CUSTOMERS WHERE COMPANY='"+name+"';";
//        sqlite3_open(this->Path.c_str(),&db);
//        int check=sqlite3_exec(db, sql.c_str(),callback_customer,(void*)tmp,&errmsg);
//        sqlite3_close(db);
//    return tmp; 
//    }
// 
//static int callback_plant(void*,int,char**,char**);
//static int callback_plant_id(void*,int,char**,char**);
// 
//Microsun::Plant* Microsun::Database::getPlant(std::string ID)
//    {
//        char* errmsg;
//        std::string sql;
//        sqlite3* db;
//        sql="SELECT ID FROM PLANTS;";
//        Microsun::Plant* temp=new Microsun::Plant();
//        sql="select PLANTS.ID,POWER,CUSTOMERS.ID,CUSTOMERS.COMPANY,CUSTOMERS.NAME,CUSTOMERS.LNAME,CUSTOMERS.PHONE,CUSTOMERS.EMAIL,CUSTOMERS.ADDRESS,CUSTOMERS.ZIP,CUSTOMERS.TIN,CUSTOMERS.NOTES,COUNTIES.*,BOROUGH,LOCATION, PLANTS.AREA,NPANELS,PANELS.*,STRINGS,MOUNTERS.*,INVERTERS.*, CONSTRUCTORS.*,CONNUMBER,CONDATE,TRACKBEGIN,PRICE FROM PLANTS,CUSTOMERS,COUNTIES,PANELS,MOUNTERS,INVERTERS,CONSTRUCTORS WHERE OWNER=CUSTOMERS.ID AND COUNTY=COUNTIES.ID AND PANEL=PANELS.ID AND MOUNTING=MOUNTERS.ID AND INVERTER=INVERTERS.ID AND CONSTRUCTOR=CONSTRUCTORS.ID AND PLANTS.ID='"+ID+"';";
//        sqlite3_open(this->Path.c_str(),&db);
//        int check=sqlite3_exec(db,sql.c_str(),callback_plant,(void*)temp,&errmsg);
//        sqlite3_close(db);
//    return temp;
//    }
// 
//Php::Value Microsun::Database::getPlants()
//    {
//        char* errmsg;
//        std::string sql;
//        sqlite3* db;
//        sql="SELECT ID FROM PLANTS;";
//        std::vector<std::string> ID;
//        sqlite3_open(this->Path.c_str(),&db);
//        int check=sqlite3_exec(db,sql.c_str(),callback_plant_id,(void*)&ID,&errmsg);
//        sqlite3_close(db);
//        std::vector<Php::Object> tmp;
//        for(std::vector<std::string>::size_type j=0;j<ID.size();j++)
//            {
//                Microsun::Plant* temp=this->getPlant(ID[j]);
//                tmp.push_back(Php::Object("MicrosunPlant",temp));
//            };
//    return tmp;
//    }
// 
//static int callback_plant_id(void* passthrough,int argc,char** argv,char** col)
//        {
//            std::vector<std::string>* ID=(std::vector<std::string>*) passthrough;
//                for(int j=0;j<argc;j++)
//                    ID->push_back(argv[j]);
//        return 0;
//        }
// 
//static int callback_plant(void* passthrough,int argc,char** argv,char** col)
//        {
//                Microsun::Plant* PLANT=(Microsun::Plant*) passthrough;
//                int j=0;
//                PLANT->ID=argv[j];
//                PLANT->Power=atof(argv[++j]);
//                PLANT->Owner->ID=atoi(argv[++j]);
//                PLANT->Owner->Company=argv[++j];
//                PLANT->Owner->FirstName=argv[++j];
//                PLANT->Owner->LastName=argv[++j];
//                PLANT->Owner->PhoneNumber=atoi(argv[++j]);
//                PLANT->Owner->email=argv[++j];
//                PLANT->Owner->Address=argv[++j];
//                PLANT->Owner->zip=atoi(argv[++j]);
//                PLANT->Owner->TIN=atoi(argv[++j]);
//                PLANT->Owner->Notes=argv[++j];
//                PLANT->county->ID=atoi(argv[++j]);
//                PLANT->county->Name=argv[++j];
//                PLANT->county->Capital=argv[++j];
//                PLANT->county->Area=atof(argv[++j]);
//                PLANT->county->Population=atof(argv[++j]);
//                PLANT->county->Density=atof(argv[++j]);
//                PLANT->county->Region=argv[++j];
//                PLANT->Borough=argv[++j];
//                PLANT->Location=argv[++j];
//                PLANT->Area=atof(argv[++j]);
//                PLANT->NPanels=atoi(argv[++j]);
//                PLANT->panel->ID=atoi(argv[++j]);
//                PLANT->panel->Make=argv[++j];
//                PLANT->panel->Model=argv[++j];
//                PLANT->Strings=argv[++j];
//                PLANT->Mounting->ID=atoi(argv[++j]);
//                PLANT->Mounting->Name=argv[++j];
//                PLANT->inverter->ID=atoi(argv[++j]);
//                PLANT->inverter->Model=argv[++j];
//                PLANT->inverter->Type=argv[++j];
//                PLANT->constructor->ID=atoi(argv[++j]);
//                PLANT->constructor->Company=argv[++j];
//                PLANT->ConnectionNumber=atoi(argv[++j]);
//                PLANT->ConnectionDate->fromString(argv[++j]);
//                PLANT->TrackerBegin->fromString(argv[++j]);
//                PLANT->SellPrice=atof(argv[++j]);
//        return 0;
//        }
// 
// 
