#include <m_database.h>
#include <sqlite3.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <m_plant.h>
#include <any>
#include <vector>
#include <stdlib.h>
#include <my_time.h>
#include <m_user.h>
#include <sstream>
#include <cstring>

static int callback_customer_all(void* passthrough,int argc,char** argv,char** col)
        {
            std::vector<Php::Object>* STORE=(std::vector<Php::Object>*) passthrough;
            Microsun::Customer* tmp=new Microsun::Customer();
            tmp->ID=atol(argv[0]);
            tmp->Company=argv[1];
            tmp->FirstName=argv[2];
            tmp->LastName=argv[3];
            tmp->PhoneNumber=atol(argv[4]);
            tmp->email=argv[5];
            tmp->Address=argv[6];
            tmp->zip=atol(argv[7]);
            tmp->TIN=atol(argv[8]);
            tmp->Notes=argv[9];
            STORE->push_back(Php::Object("MicrosunCustomer",tmp));
        return 0;
        }

Php::Value Microsun::Database::getCustomers()
    {
        char* errmsg;
        std::string sql;
        sqlite3* db;
        std::vector<Php::Object> tmp;
        sql="SELECT * FROM CUSTOMERS;";
        sqlite3_open(this->Path.c_str(),&db);
        int check=sqlite3_exec(db, sql.c_str(),callback_customer_all,(void*)&tmp,&errmsg);
        sqlite3_close(db);
    return tmp; 
    }

static int callback_plant(void*,int,char**,char**);
static int callback_plant_id(void*,int,char**,char**);

Microsun::Plant* Microsun::Database::getPlant(std::string ID)
    {
        char* errmsg;
        std::string sql;
        sqlite3* db;
        sql="SELECT ID FROM PLANTS;";
        Microsun::Plant* temp=new Microsun::Plant();
        sql="select PLANTS.ID,POWER,CUSTOMERS.*,COUNTIES.*,BOROUGH,LOCATION, \
        PLANTS.AREA,NPANELS,PANELS.*,STRINGS,MOUNTERS.*,INVERTERS.*, \
        CONSTRUCTORS.*,CONNUMBER,CONDATE,TRACKBEGIN,PRICE \
        FROM PLANTS,CUSTOMERS,COUNTIES,PANELS,MOUNTERS,INVERTERS,CONSTRUCTORS \
        WHERE OWNER=CUSTOMERS.ID AND COUNTY=COUNTIES.ID AND PANEL=PANELS.ID \
        AND MOUNTING=MOUNTERS.ID AND INVERTER=INVERTERS.ID AND CONSTRUCTOR=CONSTRUCTORS.ID \
        AND PLANTS.ID='"+ID+"';";
        std::cout<<sql<<"\n";
        sqlite3_open(this->Path.c_str(),&db);
        int check=sqlite3_exec(db,sql.c_str(),callback_plant,(void*)temp,&errmsg);
        sqlite3_close(db);
    return temp;
    }

Php::Value Microsun::Database::getPlants()
    {
        char* errmsg;
        std::string sql;
        sqlite3* db;
        sql="SELECT ID FROM PLANTS;";
        std::vector<std::string> ID;
        sqlite3_open(this->Path.c_str(),&db);
        int check=sqlite3_exec(db,sql.c_str(),callback_plant_id,(void*)&ID,&errmsg);
        sqlite3_close(db);
        std::vector<Php::Object> tmp;
        for(std::vector<std::string>::size_type j=0;j<ID.size();j++)
            {
                std::cout<<ID[j]<<"\n";
                Microsun::Plant* temp=this->getPlant(ID[j]);
                tmp.push_back(Php::Object("MicrosunPlant",temp));
            };
    return tmp;
    }

static int callback_plant_id(void* passthrough,int argc,char** argv,char** col)
        {
            std::vector<std::string>* ID=(std::vector<std::string>*) passthrough;
                for(int j=0;j<argc;j++)
                    ID->push_back(argv[j]);
        return 0;
        }

static int callback_plant(void* passthrough,int argc,char** argv,char** col)
        {
                Microsun::Plant* PLANT=(Microsun::Plant*) passthrough;
                int j=0;
                //ID
                PLANT->ID=argv[j];
                std::cout<<argv[j]<<"\n";
                //Power
                PLANT->Power=atof(argv[++j]);
                std::cout<<argv[j]<<"\n";
                //Customer
                PLANT->Owner->ID=atoi(argv[++j]);
                std::cout<<argv[j]<<"\n";
                PLANT->Owner->Company=argv[++j];
                std::cout<<argv[j]<<"\n";
                PLANT->Owner->FirstName=argv[++j];
                std::cout<<argv[j]<<"\n";
                PLANT->Owner->LastName=argv[++j];
                std::cout<<argv[j]<<"\n";
                PLANT->Owner->PhoneNumber=atoi(argv[++j]);
                std::cout<<argv[j]<<"\n";
                PLANT->Owner->email=argv[++j];
                std::cout<<argv[j]<<"\n";
                PLANT->Owner->Address=argv[++j];
                std::cout<<argv[j]<<"\n";
                PLANT->Owner->zip=atoi(argv[++j]);
                std::cout<<argv[j]<<"\n";
                PLANT->Owner->TIN=atoi(argv[++j]);
                std::cout<<argv[j]<<"\n";
                PLANT->Owner->Notes=argv[++j];
                std::cout<<argv[j]<<"\n";
                //County
                PLANT->county->ID=atoi(argv[++j]);
                PLANT->county->Name=argv[++j];
                PLANT->county->Capital=argv[++j];
                PLANT->county->Area=atof(argv[++j]);
                PLANT->county->Population=atof(argv[++j]);
                PLANT->county->Density=atof(argv[++j]);
                PLANT->county->Region=argv[++j];
                //Borough
                PLANT->Borough=argv[++j];
                std::cout<<argv[j]<<"\n";
                //Location
                PLANT->Location=argv[++j];
                std::cout<<argv[j]<<"\n";
                //Area
                PLANT->Area=atof(argv[++j]);
                std::cout<<argv[j]<<"\n";
                //Number of Panels
                PLANT->NPanels=atoi(argv[++j]);
                std::cout<<argv[j]<<"\n";
                //Panel
                PLANT->panel->ID=atoi(argv[++j]);
                std::cout<<argv[j]<<"\n";
                PLANT->panel->Make=argv[++j];
                std::cout<<argv[j]<<"\n";
                PLANT->panel->Model=argv[++j];
                std::cout<<argv[j]<<"\n";
                //Strings
                PLANT->Strings=argv[++j];
                //Mounting
                PLANT->Mounting->ID=atoi(argv[++j]);
                PLANT->Mounting->Name=argv[++j];
                //Inverter
                PLANT->inverter->ID=atoi(argv[++j]);
                PLANT->inverter->Model=argv[++j];
                PLANT->inverter->Type=argv[++j];
                //Constructor
                PLANT->constructor->ID=atoi(argv[++j]);
                PLANT->constructor->Company=argv[++j];
                //Connection Number
                PLANT->ConnectionNumber=atoi(argv[++j]);
                //Connection Date
                PLANT->ConnectionDate->fromString(argv[++j]);
                //Tracker begin date
                PLANT->TrackerBegin->fromString(argv[++j]);
                //Sell price
                PLANT->SellPrice=atof(argv[++j]);
                std::cout<<argv[j]<<"\n";
        return 0;
        }
