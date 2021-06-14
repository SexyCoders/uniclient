#include <any>
#include <m_database.h>
#include <sqlite3.h>
#include <stdlib.h>
#include <iostream>

Php::Value Microsun::Database::phpput(Php::Parameters &arg)
    {
        return std::any_cast<int>(this->put(arg[0].stringValue(),arg[1].stringValue(),arg[2].stringValue(),arg[3],arg[4].stringValue(),
                arg[5].stringValue(),arg[6].stringValue(),arg[7].stringValue()));
    }

std::any Microsun::Database::put(std::string arg,std::string user,std::string plant,int pos,
        std::string type,std::string code,std::string notes,std::string mech)
    {
        sqlite3* db;
        char* errmsg=(char*) malloc(1000*sizeof(char));;
        sqlite3_open(this->Path.c_str(),&db);
        std::string sql;
        int check=0;
        if(!arg.compare("error-report"))
            {
                Time time;
                time.getTime();
                std::string time_string=time.toString();
                std::string values("'"+plant+"',"+std::to_string(pos)+",'"+type+"','E"+code+"','"+time_string+"','"
                        +user+"','"+notes+"','"+mech+"'");
                sql="INSERT INTO PENDING_ERRORS VALUES(NULL,"+values+");";
                std::cout<<sql;
                check=sqlite3_exec(db,sql.c_str(),NULL,NULL,&errmsg);
                if(check)
                    return check;
                sql="INSERT INTO REPORT_LOGGER VALUES(NULL,"+values+");";
                std::cout<<sql;
                check=sqlite3_exec(db,sql.c_str(),NULL,NULL,&errmsg);
                if(check)
                    return check;
            }
        //if(arg[0]=="customer")
            //{
                //sqlite3* db;
                //sqlite3_open(this->getDBPath(),&db);
                    //std::string sql("INSERT INTO CUSTOMERS VALUES(");
                    //sql+=arg[1].stringValue()+", '";//ID
                    //sql+=arg[2].stringValue()+"', '";//Company
                    //sql+=arg[3].stringValue()+"', '";//FirstName
                    //sql+=arg[4].stringValue()+"', ";//LastName
                    //sql+=arg[5].stringValue()+", '";//PhoneNumber
                    //sql+=arg[6].stringValue()+"', '";//email
                    //sql+=arg[7].stringValue()+"', ";//Address
                    //sql+=arg[8].stringValue()+", ";//ZIP
                    //sql+=arg[9].stringValue()+", '";//TIN
                    //sql+=arg[10].stringValue()+"');";//Notes
                //char* errmsg=(char*) malloc(1000*sizeof(char));
                //int check=sqlite3_exec(db, sql.c_str(),NULL,NULL,&errmsg);
                //if(!check)
                        //{
                        //return check;
                        //}

        return 0;
    }
