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

static int callback_customer_all(void*,int,char**,char**);
static int callback_user(void*,int,char**,char**);
static int callback_plant(void*,int,char**,char**);
static int callback_plant_id(void*,int,char**,char**);
static int callback_plant_links(void*,int,char**,char**);
static int callback_plant_dates(void*,int,char**,char**);
static int callback_owner(void*,int,char**,char**);
static int callback_county(void*,int,char**,char**);
static int callback_panels(void*,int,char**,char**);
static int callback_mounter(void*,int,char**,char**);
static int callback_inverter(void*,int,char**,char**);
static int callback_cboard(void*,int,char**,char**);
static int callback_constructor(void*,int,char**,char**);

Php::Value Microsun::Database::phpget(Php::Parameters &arg)
    {
        if(arg.size()==1)
            this->get(arg[0]);
        else 
            this->get(arg[0],arg[1]);
    return 0;
    }

std::any Microsun::Database::get(std::string command)
    {
        sqlite3* db;
        sqlite3_open(this->getDBPath().c_str(),&db);
        char* errmsg=(char*) malloc(1000*sizeof(char));
        std::string sql;
        int check=-1;
            if(!command.compare("customer_all"))
                {
                    sql="SELECT * FROM CUSTOMERS;";
                    check=sqlite3_exec(db, sql.c_str(),callback_customer_all,(void*) this,&errmsg);
                    if(!check)
                        {
                            return 0;
                        }
                    else
                        return check;
                }
            else if(!command.compare("plant-id"))
                {
                    sql="SELECT ID FROM PLANTS;";
                        check=sqlite3_exec(db,sql.c_str(),callback_plant_id,(void*) &this->id,&errmsg);
                return 0;
                }
            else if(!command.compare("pending"))
                {
                    sql="SELECT * FROM PENDING_ERRORS;";
                    check=sqlite3_exec(db, sql.c_str(),callback_pending,(void*) this,&errmsg);
                    if(!check)
                        {
                            return 0;
                        }
                    else
                        return check;
                }
            return 123;
    }

std::any Microsun::Database::get(std::string command,std::string arg)
    {
        sqlite3* db;
        sqlite3_open(this->getDBPath().c_str(),&db);
        char* errmsg=(char*) malloc(1000*sizeof(char));
        std::string sql;
        int check=-1;
            if(!command.compare("plant"))
                {
                    std::vector<int> KeepPlant;
                    std::vector<std::string> dates;
                    sql="SELECT ID,POWER,BOROUGH,LOCATION,AREA,NPANELS,STRINGS,CONNUMBER,PRICE FROM PLANTS WHERE ID='"+arg+"';";
                    check=sqlite3_exec(db,sql.c_str(),callback_plant,(void*) this->plant,&errmsg);
                    std::cout<<sql<<"\n";
                    std::cout<<check<<"\n";
                    sql="SELECT OWNER,COUNTY,PANEL,MOUNTING,INVERTER,CBOARD,CONSTRUCTOR FROM PLANTS WHERE ID='"+arg+"';";
                    check=sqlite3_exec(db,sql.c_str(),callback_plant_links,(void*) &KeepPlant,&errmsg);
                    std::cout<<sql<<"\n";
                    std::cout<<check<<"\n";
                    sql="SELECT * FROM CUSTOMERS WHERE ID="+std::to_string((KeepPlant[0]))+";";
                    check=sqlite3_exec(db,sql.c_str(),callback_owner,(void*) this->plant,&errmsg);
                    std::cout<<sql<<"\n";
                    std::cout<<check<<"\n";
                    sql="SELECT * FROM COUNTIES WHERE ID="+std::to_string((KeepPlant[1]))+";";
                    check=sqlite3_exec(db,sql.c_str(),callback_county,(void*) this->plant,&errmsg);
                    std::cout<<sql<<"\n";
                    std::cout<<check<<"\n";
                    sql="SELECT * FROM PANELS WHERE ID="+std::to_string((KeepPlant[2]))+";";
                    check=sqlite3_exec(db,sql.c_str(),callback_panels,(void*) this->plant,&errmsg);
                    std::cout<<sql<<"\n";
                    std::cout<<check<<"\n";
                    sql="SELECT * FROM MOUNTERS WHERE ID="+std::to_string((KeepPlant[3]))+";";
                    check=sqlite3_exec(db,sql.c_str(),callback_mounter,(void*) this->plant,&errmsg);
                    std::cout<<sql<<"\n";
                    std::cout<<check<<"\n";
                    sql="SELECT * FROM INVERTERS WHERE ID="+std::to_string((KeepPlant[4]))+";";
                    check=sqlite3_exec(db,sql.c_str(),callback_inverter,(void*) this->plant,&errmsg);
                    std::cout<<sql<<"\n";
                    std::cout<<check<<"\n";
                    sql="SELECT * FROM CBOARDS WHERE ID="+std::to_string((KeepPlant[5]))+";";
                    check=sqlite3_exec(db,sql.c_str(),callback_cboard,(void*) this->plant,&errmsg);
                    std::cout<<sql<<"\n";
                    std::cout<<check<<"\n";
                    sql="SELECT * FROM CONSTRUCTORS WHERE ID="+std::to_string((KeepPlant[6]))+";";
                    check=sqlite3_exec(db,sql.c_str(),callback_constructor,(void*) this->plant,&errmsg);
                    std::cout<<sql<<"\n";
                    std::cout<<check<<"\n";
                    sql="SELECT CONDATE,TRACKBEGIN FROM PLANTS WHERE ID='"+arg+"';";
                    check=sqlite3_exec(db,sql.c_str(),callback_plant_dates,(void*) &dates,&errmsg);
                    std::cout<<sql<<"\n";
                    std::cout<<check<<"\n";
                    Time tmp_conndate;
                    tmp_conndate.fromString(dates[0]);
                    this->plant->setConnectionDate(tmp_conndate);
                    std::cout<<sql<<"\n";
                    std::cout<<check<<"\n";
                    Time tmp_trackdate;
                    tmp_trackdate.fromString(dates[1]);
                    this->plant->setTrackerBeggin(tmp_trackdate);
                    std::cout<<sql<<"\n";
                    std::cout<<check<<"\n";
                return 0;
                }
        return 0;
    }

static int split(std::string str,std::vector<std::string>* vect)
    {
        std::stringstream ss(str);

        for (std::string i; ss >> i;) {
            vect->push_back(i);
            if (ss.peek() == ',')
                ss.ignore();
        }
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
        Microsun::Database* THIS=(Microsun::Database*) passthrough;
        Microsun::Group t;
        t.name=*argv;
        std::vector<std::string> T;
        split(argv[1],&T);
        
        sqlite3* db;
        sqlite3_open(THIS->getDBPath().c_str(),&db);
        char* errmsg;
        int size=T.size();
        for(int j=0;size;j++)
            {
                Microsun::User temp;
                std::string sql="SELECT \
                ID,FNAME,LNAME,DATEOFBIRTH,EMAIL,PHONE,ZIP,ADDRESS,NOTES,HIREDATE,USERNAME,USERGROUP\
                FROM USERS WHERE USERNAME'="+T[j]+"';";
                sqlite3_exec(db,sql.c_str(),user_callback,(void*)&temp,&errmsg);
                t.users.push_back(temp);
            }
        sqlite3_close(db);
        THIS->groups.push_back(t);
    }

void Microsun::Database::get_groups()
    {
        sqlite3* db;
        sqlite3_open(this->getDBPath().c_str(),&db);
        char* errmsg;
        sqlite3_exec(db,"SELECT * FROM GROUPS;",group_callback,(void*)this,&errmsg);
    }

static int callback_customer_all(void* passthrough,int argc,char** argv,char** col)
        {
                Microsun::Database* THIS=(Microsun::Database*) passthrough;
                THIS->stored_customers.push_back(new Microsun::Customer());
                THIS->stored_customers.back()->csetID(atol(argv[0]));
                THIS->stored_customers.back()->csetCompany(argv[1]);
                THIS->stored_customers.back()->csetFirstName(argv[2]);
                THIS->stored_customers.back()->csetLastName(argv[3]);
                THIS->stored_customers.back()->csetPhoneNumber(atol(argv[4]));
                THIS->stored_customers.back()->csetemail(argv[5]);
                THIS->stored_customers.back()->csetAddress(argv[6]);
                THIS->stored_customers.back()->csetzip(atol(argv[7]));
                THIS->stored_customers.back()->csetTIN(atol(argv[8]));
                THIS->stored_customers.back()->csetNotes(argv[9]);
        return 0;
        }

static int callback_user(void* passthrough,int argc,char** argv,char** col)
        {
                Microsun::Database* THIS=(Microsun::Database*) passthrough;
                THIS->stored_users.push_back(new Microsun::User());
                THIS->stored_users.back()->ID=atoi(argv[0]);
                THIS->stored_users.back()->FName=argv[1];
                THIS->stored_users.back()->LName=argv[2];
                THIS->stored_users.back()->DateOfBirth.fromString(argv[3]);
                THIS->stored_users.back()->email=argv[4];
                THIS->stored_users.back()->PhoneNumber=atoi(argv[5]);
                THIS->stored_users.back()->zip=atoi(argv[6]);
                THIS->stored_users.back()->Address=argv[7];
                THIS->stored_users.back()->Notes=argv[8];
                THIS->stored_users.back()->HireDate.fromString(argv[9]);
                THIS->stored_users.back()->group=argv[10];
        return 0;
        }

static int callback_plant(void* passthrough,int argc,char** argv,char** col)
        {
                Microsun::Plant* PLANT=(Microsun::Plant*) passthrough;
                PLANT->setID(argv[0]);
                PLANT->setPower(atof(argv[1]));
                PLANT->setBorough(argv[2]);
                PLANT->setLocation(argv[3]);
                PLANT->setArea(atof(argv[4]));
                PLANT->setNPanels(atoi(argv[5]));
                PLANT->setStrings(argv[6]);
                PLANT->setConnectionNumber(atoi(argv[7]));
                PLANT->setSellPrice(atof(argv[8]));
        return 0;
        }
static int callback_plant_id(void* passthrough,int argc,char** argv,char** col)
        {
                std::vector<std::string>* ID=(std::vector<std::string>*) passthrough;
                for(int j=0;j<argc;j++)
                    ID->push_back(argv[j]); 
        return 0;
        }

static int callback_plant_links(void* passthrough,int argc,char** argv,char** col)
        {
                std::vector<int>* keep=(std::vector<int>*) passthrough;
                for(int j=0;j<argc;j++)
                        {
                                keep->push_back(atoi(argv[j]));
                        }
        return 0;
        }

static int callback_plant_dates(void* passthrough,int argc,char** argv,char** col)
        {
                std::vector<std::string>* keep=(std::vector<std::string>*) passthrough;
                for(int j=0;j<argc;j++)
                        {
                                keep->push_back(argv[j]);
                        }
        return 0;
        }

static int callback_owner(void* passthrough,int argc,char** argv,char** col)
        {
                Microsun::Plant* RETURN=(Microsun::Plant*) passthrough;
                Microsun::Customer tmp(atol(argv[0]),argv[1],argv[2],argv[3],atol(argv[4]),
                                argv[5],argv[6],atol(argv[7]),argv[9],atol(argv[8]));
                RETURN[0].setOwner(tmp);
        return 0;
        }
static int callback_county(void* passthrough,int argc,char** argv,char** col)
        {
                Microsun::Plant* RETURN=(Microsun::Plant*) passthrough;
                Microsun::County tmp;
                tmp.ID=atoi(argv[0]);
                tmp.Name=argv[1];
                tmp.Capital=argv[2];
                tmp.Area=(double) atof(argv[3]);
                tmp.Population=(double) atof(argv[4]);
                tmp.Density=(float) atof(argv[5]);
                tmp.Region=argv[6];
                RETURN[0].setCounty(tmp);
        return 0;
        }
static int callback_panels(void* passthrough,int argc,char** argv,char** col)
        {
                Microsun::Plant* RETURN=(Microsun::Plant*) passthrough;
                Microsun::Panel tmp;
                tmp.ID=atoi(argv[0]);
                tmp.Make=argv[1];
                tmp.Model=argv[2];
                RETURN[0].setPanel(tmp);
        return 0;
        }
static int callback_mounter(void* passthrough,int argc,char** argv,char** col)
        {
                Microsun::Plant* RETURN=(Microsun::Plant*) passthrough;
                Microsun::Mounter tmp;
                tmp.ID=atoi(argv[0]);
                tmp.Name=argv[1];
                RETURN[0].setMounting(tmp);
        return 0;
        }
static int callback_inverter(void* passthrough,int argc,char** argv,char** col)
        {
                Microsun::Plant* RETURN=(Microsun::Plant*) passthrough;
                Microsun::Inverter tmp;
                tmp.ID=atoi(argv[0]);
                tmp.Model=argv[1];
                tmp.Type=argv[2];
                RETURN[0].setInverter(tmp);
        return 0;
        }
static int callback_cboard(void* passthrough,int argc,char** argv,char** col)
        {
                Microsun::Plant* RETURN=(Microsun::Plant*) passthrough;
                Microsun::CBoard tmp;
                tmp.ID=atoi(argv[0]);
                tmp.Model=argv[1];
                RETURN[0].setCBoard(tmp);
        return 0;
        }
static int callback_constructor(void* passthrough,int argc,char** argv,char** col)
        {
                Microsun::Plant* RETURN=(Microsun::Plant*) passthrough;
                Microsun::Constructor tmp;
                tmp.ID=atoi(argv[0]);
                tmp.Company=argv[1];
                RETURN[0].setConstructor(tmp);
        return 0;
        }
