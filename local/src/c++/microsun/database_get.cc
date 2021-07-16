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

static int callback_customer_all(void*,int,char**,char**);
//static int callback_plant(void*,int,char**,char**);
//static int callback_plant_id(void*,int,char**,char**);
//static int callback_plant_links(void*,int,char**,char**);
//static int callback_plant_dates(void*,int,char**,char**);
//static int callback_owner(void*,int,char**,char**);
//static int callback_county(void*,int,char**,char**);
//static int callback_panels(void*,int,char**,char**);
//static int callback_mounter(void*,int,char**,char**);
//static int callback_inverter(void*,int,char**,char**);
//static int callback_cboard(void*,int,char**,char**);
//static int callback_constructor(void*,int,char**,char**);
//static int callback_pending(void*,int,char**,char**);

Php::Value Microsun::Database::phpget(Php::Parameters &arg)
    {
        if(arg.size()==1)
            this->get(arg[0]);
        else 
            this->get(arg[0],arg[1]);
    return 0;
    }

int Microsun::Database::get(std::string command)
    {
        char* errmsg;
        std::string sql;
        sqlite3* db;
        sqlite3_open(this->Path.c_str(),&db);
        int check=-1;
            if(!command.compare("customer_all"))
                {
                    sql="SELECT * FROM CUSTOMERS;";
                    check=sqlite3_exec(db, sql.c_str(),callback_customer_all,(void*)this,&errmsg);
                    //sqlite3_close(db);
                    if(!check)
                        return 0;
                    else
                        return check;
                }
            //else if(!command.compare("plant-id"))
                //{
                    //sql="SELECT ID FROM PLANTS;";
                    //check=sqlite3_exec(db,sql.c_str(),callback_plant_id,(void*)this,&errmsg);
                    ////sqlite3_close(db);
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
        return 123;
    }

//int Microsun::Database::get(std::string command,std::string arg)
    //{
        //sqlite3* db;
        //sqlite3_open(this->Path.c_str(),&db);
        //char* errmsg;
        //std::string sql;
        //int check=-1;
            //if(!command.compare("plant"))
                //{
                    //int KeepPlant[7];
                    //std::string dates[2];
                    //sql="SELECT ID,POWER,BOROUGH,LOCATION,AREA,NPANELS,STRINGS,CONNUMBER,PRICE FROM PLANTS WHERE ID='"+arg+"';";
                    //check=sqlite3_exec(db,sql.c_str(),callback_plant,(void*) &this->plant,&errmsg);
                    //sql="SELECT OWNER,COUNTY,PANEL,MOUNTING,INVERTER,CBOARD,CONSTRUCTOR FROM PLANTS WHERE ID='"+arg+"';";
                    //check=sqlite3_exec(db,sql.c_str(),callback_plant_links,(void*) &KeepPlant,&errmsg);
                    //sql="SELECT * FROM CUSTOMERS WHERE ID="+std::to_string((KeepPlant[0]))+";";
                    //check=sqlite3_exec(db,sql.c_str(),callback_owner,(void*) &this->plant,&errmsg);
                    //sql="SELECT * FROM COUNTIES WHERE ID="+std::to_string((KeepPlant[1]))+";";
                    //check=sqlite3_exec(db,sql.c_str(),callback_county,(void*) &this->plant,&errmsg);
                    //sql="SELECT * FROM PANELS WHERE ID="+std::to_string((KeepPlant[2]))+";";
                    //check=sqlite3_exec(db,sql.c_str(),callback_panels,(void*) &this->plant,&errmsg);
                    //sql="SELECT * FROM MOUNTERS WHERE ID="+std::to_string((KeepPlant[3]))+";";
                    //check=sqlite3_exec(db,sql.c_str(),callback_mounter,(void*) &this->plant,&errmsg);
                    //sql="SELECT * FROM INVERTERS WHERE ID="+std::to_string((KeepPlant[4]))+";";
                    //check=sqlite3_exec(db,sql.c_str(),callback_inverter,(void*) &this->plant,&errmsg);
                    //sql="SELECT * FROM CBOARDS WHERE ID="+std::to_string((KeepPlant[5]))+";";
                    //check=sqlite3_exec(db,sql.c_str(),callback_cboard,(void*) &this->plant,&errmsg);
                    //sql="SELECT * FROM CONSTRUCTORS WHERE ID="+std::to_string((KeepPlant[6]))+";";
                    //check=sqlite3_exec(db,sql.c_str(),callback_constructor,(void*) &this->plant,&errmsg);
                    //sql="SELECT CONDATE,TRACKBEGIN FROM PLANTS WHERE ID='"+arg+"';";
                    //check=sqlite3_exec(db,sql.c_str(),callback_plant_dates,(void*) dates,&errmsg);
                    //this->plant.ConnectionDate.fromString(dates[0]);
                    //this->plant.TrackerBegin.fromString(dates[1]);
                ////sqlite3_close(db);
                //return check;
                //}
        ////sqlite3_close(db);
        //return 0;
    //}

//int Microsun::Database::get_user(std::string username,std::string grp,Microsun::User* result)
    //{
        //for(int j=0;j<this->g_size;j++)
            //{
                //if(groups[j].name!=grp && grp!="all")
                    //continue;
                //else
                    //{
                        //int usersize=groups[j].size;
                        //for(int i=0;i<usersize;i++)
                            //{
                                //if(groups[j].users[i].username==username)
                                    //*result=groups[j].users[i];
                            //}
                    //}
            //}
        //return 0;
    //}

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
        //std::vector<std::string> T;
        //split(argv[1],&T);

        //int size=T.size();
        
        //sqlite3* db;
        //sqlite3_open(THIS->Path.c_str(),&db);
        //char* errmsg;
        //for(int j=0;j<size;j++)
            //{
                //Microsun::User temp;
                //std::string sql="SELECT \
                //ID,FNAME,LNAME,DATEOFBIRTH,EMAIL,PHONE,ZIP,ADDRESS,NOTES,HIREDATE,USERNAME,USERGROUP \
                //FROM USERS WHERE USERNAME='"+T[j]+"';";
                //sqlite3_exec(db,sql.c_str(),user_callback,(void*)&temp,&errmsg);
                //t.add(temp);
            //}
        //sqlite3_close(db);
        //THIS->groups.push_back(t);
        //Microsun::Group* temp=THIS->groups;
        //THIS->groups=new Microsun::Group[++THIS->g_size];
        //std::copy(temp,&temp[THIS->g_size-1],THIS->groups);
        //THIS->groups[THIS->g_size-1]=t;
        //(THIS->g_size>1)?delete[] temp:(void)0;
    return this->g_size;
    }

static int callback_customer_all(void* passthrough,int argc,char** argv,char** col)
        {
                Microsun::Database* THIS=(Microsun::Database*) passthrough;
                Microsun::Customer tmp;
                tmp.ID=atol(argv[0]);
                tmp.Company=argv[1];
                tmp.FirstName=argv[2];
                tmp.LastName=argv[3];
                tmp.PhoneNumber=atol(argv[4]);
                tmp.email=argv[5];
                tmp.Address=argv[6];
                tmp.zip=atol(argv[7]);
                tmp.TIN=atol(argv[8]);
                tmp.Notes=argv[9];
                Microsun::Customer* temp=THIS->stored_customers.data;
                THIS->stored_customers.data=new Microsun::Customer[++THIS->stored_customers.size];
                std::copy(temp,&temp[THIS->stored_customers.size-1],THIS->stored_customers.data);
                THIS->stored_customers.data[THIS->stored_customers.size-1]=tmp;
                (THIS->stored_customers.size>1)?delete[] temp:(void)0;
        return 0;
        }

//static int callback_plant(void* passthrough,int argc,char** argv,char** col)
        //{
                //Microsun::Plant* PLANT=(Microsun::Plant*) passthrough;
                //PLANT->ID=argv[0];
                //PLANT->Power=atof(argv[1]);
                //PLANT->Borough=argv[2];
                //PLANT->Location=argv[3];
                //PLANT->Area=atof(argv[4]);
                //PLANT->NPanels=atoi(argv[5]);
                //PLANT->Strings=argv[6];
                //PLANT->ConnectionNumber=atoi(argv[7]);
                //PLANT->SellPrice=atof(argv[8]);
        //return 0;
        //}
//static int callback_plant_id(void* passthrough,int argc,char** argv,char** col)
        //{
                //Microsun::Database* THIS=(Microsun::Database*) passthrough;
                //THIS->ID.id=new std::string[argc];
                //THIS->ID.size=argc;
                //for(int j=0;j<argc;j++)
                    //THIS->ID.id[j]=argv[j]; 
        //return 0;
        //}

//static int callback_plant_links(void* passthrough,int argc,char** argv,char** col)
        //{
                //int* keep=(int*) passthrough;
                //for(int j=0;j<argc;j++)
                    //keep[j]=atoi(argv[j]);
        //return 0;
        //}

//static int callback_plant_dates(void* passthrough,int argc,char** argv,char** col)
        //{
                //std::string* keep=(std::string*) passthrough;
                //keep[0]=argv[0];
                //keep[1]=argv[1];
        //return 0;
        //}

//static int callback_owner(void* passthrough,int argc,char** argv,char** col)
        //{
                //Microsun::Plant* RETURN=(Microsun::Plant*) passthrough;
                //Microsun::Customer tmp(atol(argv[0]),argv[1],argv[2],argv[3],atol(argv[4]),
                                //argv[5],argv[6],atol(argv[7]),argv[9],atol(argv[8]));
                //RETURN[0].Owner=tmp;
        //return 0;
        //}
//static int callback_county(void* passthrough,int argc,char** argv,char** col)
        //{
                //Microsun::Plant* RETURN=(Microsun::Plant*) passthrough;
                //Microsun::County tmp;
                //tmp.ID=atoi(argv[0]);
                //tmp.Name=argv[1];
                //tmp.Capital=argv[2];
                //tmp.Area=(double) atof(argv[3]);
                //tmp.Population=(double) atof(argv[4]);
                //tmp.Density=(float) atof(argv[5]);
                //tmp.Region=argv[6];
                //RETURN[0].county=tmp;
        //return 0;
        //}
//static int callback_panels(void* passthrough,int argc,char** argv,char** col)
        //{
                //Microsun::Plant* RETURN=(Microsun::Plant*) passthrough;
                //Microsun::Panel tmp;
                //tmp.ID=atoi(argv[0]);
                //tmp.Make=argv[1];
                //tmp.Model=argv[2];
                //RETURN[0].panel=tmp;
        //return 0;
        //}
//static int callback_mounter(void* passthrough,int argc,char** argv,char** col)
        //{
                //Microsun::Plant* RETURN=(Microsun::Plant*) passthrough;
                //Microsun::Mounter tmp;
                //tmp.ID=atoi(argv[0]);
                //tmp.Name=argv[1];
                //RETURN[0].Mounting=tmp;
        //return 0;
        //}
//static int callback_inverter(void* passthrough,int argc,char** argv,char** col)
        //{
                //Microsun::Plant* RETURN=(Microsun::Plant*) passthrough;
                //Microsun::Inverter tmp;
                //tmp.ID=atoi(argv[0]);
                //tmp.Model=argv[1];
                //tmp.Type=argv[2];
                //RETURN[0].inverter=tmp;
        //return 0;
        //}
//static int callback_cboard(void* passthrough,int argc,char** argv,char** col)
        //{
                //Microsun::Plant* RETURN=(Microsun::Plant*) passthrough;
                //Microsun::CBoard tmp;
                //tmp.ID=atoi(argv[0]);
                //tmp.Model=argv[1];
                //RETURN[0].cboard=tmp;
        //return 0;
        //}
//static int callback_constructor(void* passthrough,int argc,char** argv,char** col)
        //{
                //Microsun::Plant* RETURN=(Microsun::Plant*) passthrough;
                //Microsun::Constructor tmp;
                //tmp.ID=atoi(argv[0]);
                //tmp.Company=argv[1];
                //RETURN[0].constructor=tmp;
        //return 0;
        //}
