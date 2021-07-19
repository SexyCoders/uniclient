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
                Microsun::Plant* temp=new Microsun::Plant();
                sql="select PLANTS.ID,POWER,CUSTOMERS.*,COUNTIES.*,BOROUGH,LOCATION, \
                PLANTS.AREA,NPANELS,PANELS.*,STRINGS,MOUNTERS.*,INVERTERS.*, \
                CONSTRUCTORS.*,CONNUMBER,CONDATE,TRACKBEGIN,PRICE \
                FROM PLANTS,CUSTOMERS,COUNTIES,PANELS,MOUNTERS,INVERTERS,CONSTRUCTORS \
                WHERE OWNER=CUSTOMERS.ID AND COUNTY=COUNTIES.ID AND PANEL=PANELS.ID \
                AND MOUNTING=MOUNTERS.ID AND INVERTER=INVERTERS.ID AND CONSTRUCTOR=CONSTRUCTORS.ID \
                AND PLANTS.ID='"+ID[j]+"';";
                std::cout<<sql<<"\n";
                sqlite3_open(this->Path.c_str(),&db);
                int check=sqlite3_exec(db,sql.c_str(),callback_plant,(void*)temp,&errmsg);
                sqlite3_close(db);
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
int Microsun::Database::get_user(std::string username,std::string grp,Microsun::User* result)
    {
        for(int j=0;j<this->g_size;j++)
            {
                if(groups[j].name!=grp && grp!="all")
                    continue;
                else
                    {
                        int usersize=groups[j].size;
                        for(int i=0;i<usersize;i++)
                            {
                                if(groups[j].users[i].username==username)
                                    *result=groups[j].users[i];
                            }
                    }
            }
        return 0;
    }

static int split(std::string str,std::vector<std::string>* vect)
    {
        int len=str.length();

        std::string tmp;
        for (int j=0;j<len;j++) 
            {
                if(str[j]==';')
                    {
                        vect->push_back(tmp);
                        tmp.clear();
                    }
                else
                    tmp.push_back(str[j]);
            }
    return 0;
    }

static int user_callback(void* passthrough,int argc,char** argv,char** col)
    {
        Microsun::User* U=(Microsun::User*) passthrough;
        U->ID=atoi(argv[0]);
        U->FName=argv[1];
        U->LName=argv[2];
        U->DateOfBirth.fromString(argv[3]);
        U->email=argv[4];
        U->PhoneNumber=atoi(argv[5]);
        U->zip=atoi(argv[6]);
        U->Address=argv[7];
        U->Notes=argv[8];
        U->HireDate.fromString(argv[9]);
        U->username=argv[10];
        U->group=argv[11];
    return 0;
    }


static int group_callback(void* passthrough,int argc,char** argv,char** col)
    {
        std::vector<std::array<std::string,2>>* result=(std::vector<std::array<std::string,2>>*) passthrough;
        result->push_back({argv[0],argv[1]});
    return 0;
        
    }
int Microsun::Database::get_groups()
    {
        sqlite3* db;
        sqlite3_open(this->Path.c_str(),&db);
        char* errmsg;
        std::vector<std::array<std::string,2>> tmp;
        sqlite3_exec(db,"SELECT * FROM GROUPS;",group_callback,(void*)&tmp,&errmsg);
        sqlite3_close(db);
        int s=tmp.size();
        for(int j=0;j<s;j++)
            {
                Microsun::Group t;
                t.name=tmp[j][0];
            }
    return this->g_size;
    }

//static int callback_pending(void* passthrough,int argc,char** argv,char** col)
    //{
        //Microsun::Database* THIS=(Microsun::Database*)passthrough;
        //Microsun::Problem T;
        //T.reg_id=atoi(*argv);
        //THIS->get("plant",argv[1]);
        //T.plant=THIS->plant;
        //T.Type=argv[2];
        //T.Pos=atoi(argv[3]);
        //T.ErrorCode=argv[4];
        //T.ReportedDate.fromString(argv[5]);
        //T.ReportedUser=THIS->get_user(argv[6],"all");
        //T.ErrorNotes=argv[7];
        //T.AssignedMech=THIS->get_user(argv[8],"all");
        //THIS->stored_problems.push_back(std::move(T));
    //return 0;
    //}

            //else if(!command.compare("pending"))
                //{
                    //sql="SELECT * FROM PENDING_ERRORS;";
                    //check=sqlite3_exec(db, sql.c_str(),callback_pending,(void*)this,&errmsg);
                    ////sqlite3_close(db);
                    //if(!check)
                        //return 0;
                    //else
                        //return check;
                //}
        //sqlite3_close(db);
        //return 123;
    //}


