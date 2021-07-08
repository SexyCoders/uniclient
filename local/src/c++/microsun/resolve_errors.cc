#include <microsun.h>
#include <m_database.h>
#include <iostream>
#include <my_time.h>
#include <variant>
#include <any>

static int callback_keep(void*,int,char**,char**);

int Microsun::Database::ResolveError(int id,std::string notes)
    {
        //sqlite3* db;
        //char* errmsg=(char*) malloc(1000*sizeof(char));
        //sqlite3_open(this->Path.c_str(),&db);
        //std::vector<std::string> keep;
        //std::string sql("SELECT * FROM PENDING_ERRORS WHERE ID='"+std::to_string(id)+"';");
        //int check=sqlite3_exec(db,sql.c_str(),callback_keep,(void*) &keep,&errmsg);
        //if(check)
            //return check;
        //std::cout<<sql<<"\n";
        //sql="DELETE FROM PENDING_ERRORS WHERE ID='"+std::to_string(id)+"';";
        //check=sqlite3_exec(db,sql.c_str(),NULL,NULL,&errmsg);
        //if(check)
            //return check;
        //std::cout<<sql<<"\n";
        //Time time;
        //time.getTime();
        //std::string time_string=time.toString();
        //sql="INSERT INTO ERROR_LOG VALUES(NULL,'"+keep[1]+"',"+keep[2]+",'"+keep[3]+"','"+keep[4]+
            //"','"+keep[5]+"','"+keep[6]+"','"+keep[7]+"','"+keep[8]+"','"+time_string+"','"+notes+"');";
        //std::cout<<sql<<"\n";
        //check=sqlite3_exec(db,sql.c_str(),NULL,NULL,&errmsg);
        //if(check)
            //return check;
        //std::cout<<sql<<"\n";
    return 0;
    }

static int callback_keep(void* data,int argc,char** argv,char** col)
    {
        std::vector<std::string>* RETURN=(std::vector<std::string>*) data;
        for(int j=0;j<argc;j++)
            RETURN->push_back(argv[j]);
    return 0;
    }
