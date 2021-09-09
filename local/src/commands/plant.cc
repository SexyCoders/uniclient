#include <m_plant.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <sqlite3.h>

int main(int argc,char** argv)
    {
        printf("ID: "); 
        std::string ID;
        std::cin>>ID;
        printf("POWER: "); 
        float power;
        std::cin>>power;
        printf("OWNER: "); 
        int owner_id;
        std::cin>>owner_id;
        printf("COUNTY: "); 
        int county_id;
        std::cin>>county_id;
        printf("BOROUGH: "); 
        std::string borough;
        std::cin>>borough;
        printf("LOCATION: "); 
        std::string location;
        std::cin>>location;
        printf("AREA: "); 
        float area;
        std::cin>>area;
        printf("NPANELS: "); 
        int npanels;
        std::cin>>npanels;
        printf("PANEL: "); 
        int panel;
        std::cin>>panel;
        printf("STRINGS: "); 
        std::string _string;
        std::cin>>_string;
        printf("MOUNTING: "); 
        int mounting;
        std::cin>>mounting;
        printf("INVERTER: "); 
        int inverter;
        std::cin>>inverter;
        printf("CBOARD: "); 
        int cboard;
        std::cin>>cboard;
        printf("CONSTRUCTOR: "); 
        int constr;
        std::cin>>constr;
        printf("CONNUMBER: "); 
        long int connumber;
        std::cin>>connumber;
        printf("CONDATE: "); 
        std::string conndate;
        std::cin>>conndate;
        printf("TRACKBEGIN: "); 
        std::string trackbegin;
        std::cin>>trackbegin;
        printf("PRICE: "); 
        float price;
        std::cin>>price;

        std::string sql="INSERT INTO PLANTS VALUES(\
'"+ID+"'\
,"+std::to_string(power)+"\
,"+std::to_string(owner_id)+"\
,"+std::to_string(county_id)+"\
,'"+borough+"'\
,'"+location+"'\
,"+std::to_string(area)+"\
,"+std::to_string(npanels)+"\
,"+std::to_string(panel)+"\
,'"+_string+"'\
,"+std::to_string(mounting)+"\
,"+std::to_string(inverter)+"\
,"+std::to_string(cboard)+"\
,"+std::to_string(constr)+"\
,"+std::to_string(connumber)+"\
,'"+conndate+"'\
,'"+trackbegin+"'\
,"+std::to_string(price)+");";

    std::cout<<sql<<"\n";

    char* errmsg;
    sqlite3* db;
    sqlite3_open("/var/lib/uniclient/MICROSUN_DATABASE",&db);
    int check=sqlite3_exec(db, sql.c_str(),NULL,NULL,&errmsg);
    sqlite3_close(db);

    if(check)
        std::cout<<errmsg<<"\n";

    std::string loggin_table_sql="CREATE TABLE ID NOT EXISTS "+ID+"(ID INTEGER PRIMARY KEY NOT NULL,PLANT TEXT NOT NULL,POS INTEGER,TYPE TEXT,ERROR_CODE TEXT,REPORTED_DATE TEXT NOT NULL,REPORTED_USER TEXT,ERROR_NOTES TEXT,ASSIGNED_MECH TEXT,RESOLVED_DATE TEXT,MECH_NOTES TEXT);";

    sqlite3_open("/var/lib/uniclient/LOGGING_DATABASE",&db);
    check=sqlite3_exec(db, sql.c_str(),NULL,NULL,&errmsg);
    sqlite3_close(db);

    if(check)
        std::cout<<errmsg<<"\n";

    std::cout<<"PLANT ADDED! DONE!\n";
    exit(0);
    }
