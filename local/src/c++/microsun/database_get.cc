#include <database.h>
#include <sqlite3.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <plant.h>
#include <any>
#include <vector>
#include <stdlib.h>
#include <my_time.h>
#include <user.h>

static int callback_customer_all(void*,int,char**,char**);
static int callback_user(void*,int,char**,char**);
static int callback_key(void*,int,char**,char**);
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
static int callback_pending_errors_data(void*,int,char**,char**);
static int callback_pending_errors_links(void*,int,char**,char**);
static int callback_pending_errors_rows(void*,int,char**,char**);
static int callback_pending_errors_date(void*,int,char**,char**);
static int callback_get_group_users_from_users(void*,int,char**,char**);
static int callback_get_group_users_from_groups(void*,int,char**,char**);

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
        sqlite3_open(this->getDBPath(),&db);
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
            else if(!command.compare("pending-problems"))
                {
                    int rows;
                    sql="SELECT COUNT(*) FROM PENDING_ERRORS;";
                    check=sqlite3_exec(db,sql.c_str(),callback_pending_errors_rows,(void*) &rows,&errmsg);
                    std::cout<<sql<<"\n";
                    std::cout<<check<<"\n";
                    std::cout<<"rows:"<<rows<<"\n";
                    if(check)
                        return check;
                    sql="SELECT ID,POS,TYPE,ERROR_CODE,ERROR_NOTES FROM PENDING_ERRORS;";
                    check=sqlite3_exec(db,sql.c_str(),callback_pending_errors_data,(void*) &this->stored_problems,&errmsg);
                    std::cout<<sql<<"\n";
                    std::cout<<check<<"\n";
                    if(check)
                        return check;
                    std::vector<std::string> links;
                    sql="SELECT PLANT,REPORTED_USER,ASSIGNED_MECH FROM PENDING_ERRORS ;";
                    check=sqlite3_exec(db,sql.c_str(),callback_pending_errors_links,(void*) &links,&errmsg);
                    std::cout<<sql<<"\n";
                    std::cout<<check<<"\n";
                    if(check)
                        return check;
                    for(int j=0;j<rows;j++)
                        {
                            std::cout<<j<<"\n";
                            this->get("plant",links[j*3+0]);
                            std::cout<<j<<"\n";
                            this->stored_problems[j]->setPlant(*this->plant);
                            std::cout<<"plants-ok\n";
                            this->get("user",links[j*3+1]);
                            this->stored_problems[j]->setReportedUser(*this->stored_users[j*2+0]);
                            std::cout<<"user-ok\n";
                            this->get("user",links[j*3+2]);
                            this->stored_problems[j]->setAssignedMech(*this->stored_users[j*2+1]);
                            std::cout<<"mech-ok\n";
                            std::string buffer;
                            sql="SELECT REPORTED_DATE FROM PENDING_ERRORS ;";
                            check=sqlite3_exec(db,sql.c_str(),callback_pending_errors_date,(void*) &buffer,&errmsg);
                            if(check)
                                return check;
                            Time tmp_time;
                            tmp_time.fromString(buffer);
                            this->stored_problems[j]->setReportedDate(tmp_time);
                            std::cout<<"date-ok\n";
                        }
                    return 0;
                    }
            else if(!command.compare("pending-count"))
                {
                    sql="SELECT COUNT(*) FROM PENDING_ERRORS";
                    check=sqlite3_exec(db,sql.c_str(),callback_pending_errors_rows,(void*) &this->stored_int,&errmsg);
                }
            return 123;
    }
std::any Microsun::Database::get(std::string command,std::string arg)
    {
        sqlite3* db;
        sqlite3_open(this->getDBPath(),&db);
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
            else if(!command.compare("user"))
                {
                    sql="SELECT * FROM USERS WHERE USERNAME='"+arg+"';";
                    std::cout<<sql<<"\n";
                    check=sqlite3_exec(db, sql.c_str(),callback_user,(void*) this,&errmsg);
                    std::cout<<sql<<"\n";
                    //return this->stored_users;
                    return 0;
                }
            else if(!command.compare("key"))
                {
                    sql="SELECT KEY FROM AUTH WHERE USER='"+arg+"';";
                    check=sqlite3_exec(db, sql.c_str(),callback_key,(void*) this,&errmsg);
                }
            else if(!command.compare("group-users"))
                {
                    sql="SELECT USERNAME FROM USERS WHERE USERGROUP='"+arg+"'";
                    check=sqlite3_exec(db,sql.c_str(),callback_get_group_users_from_users,(void*) &this->user_names,&errmsg);
                    sql="SELECT USERNAME FROM GROUPS WHERE USERGROUP='"+arg+"'";
                    check=sqlite3_exec(db,sql.c_str(),callback_get_group_users_from_groups,(void*) &this->user_names,&errmsg);
                return 0;
                }
            else if(!command.compare("customer_single"))
                {
                    sql="SELECT * FROM CUSTOMERS WHERE ID="+arg+";";
                    check=sqlite3_exec(db, sql.c_str(),callback_customer_all,(void*) this,&errmsg);
                    if(!check)
                        {
                            return 0;
                        }
                    else
                        return check;
                }
        return 0;
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
                THIS->stored_users.back()->setusername(argv[0]);
                THIS->stored_users.back()->setpasswd(argv[1]);
                THIS->stored_users.back()->setemail(argv[2]);
                THIS->stored_users.back()->setgroup(argv[3]);
        return 0;
        }

static int callback_key(void* passthrough,int argc,char** argv,char** col)
    {
                Microsun::Database* THIS=(Microsun::Database*) passthrough;
                THIS->string_buffer=*argv;
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
static int callback_pending_errors_data(void* passthrough,int argc,char** argv,char** col)
        {
                std::vector<Microsun::Problem*>* RETURN=(std::vector<Microsun::Problem*>*) passthrough;
                Microsun::Problem* tmp=new Microsun::Problem();
                tmp->setID(atol(argv[0]));
                tmp->setPos(atoi(argv[1]));
                tmp->setType(argv[2]);
                tmp->setErrorCode(argv[3]);
                tmp->setErrorNotes(argv[4]);
                RETURN->push_back(tmp); 
        return 0;
        }

static int callback_pending_errors_links(void* passthrough,int argc,char** argv,char** col)
        {
                std::vector<std::string>* RETURN=(std::vector<std::string>*) passthrough;
                std::cout<<"argv is: "<<argv;
                for(int j=0;j<argc;j++)
                        {
                        RETURN->push_back(argv[j]);
                        std::cout<<(*RETURN)[j];
                        }
        return 0;
        }

static int callback_pending_errors_rows(void* passthrough,int argc,char** argv,char** col)
        {
                int* RETURN=(int*) passthrough;
                *RETURN=atoi(*argv);
                std::cout<<argv<<"|"<<*RETURN;
        return 0;
        }

static int callback_pending_errors_date(void* passthrough,int argc,char** argv,char** col)
        {
                std::string* RETURN=(std::string*) passthrough;
                *RETURN=*argv;
        return 0;
        }

static int callback_get_group_users_from_users(void* passthrough,int argc,char** argv,char** col)
        {
            std::vector<std::string>* RETURN=(std::vector<std::string>*) passthrough;
            RETURN->push_back(*argv);
        return 0;
        }

static int callback_get_group_users_from_groups(void* passthrough,int argc,char** argv,char** col)
        {
            std::vector<std::string>* RETURN=(std::vector<std::string>*) passthrough;
            for(int j=0;j<argc;j++)
                {
                    for(int i=0;i<j;i++)
                        if((*RETURN)[i].compare(argv[j]))
                            RETURN->push_back(argv[j]);
                }
        return 0;
        }
