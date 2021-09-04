#include <microsun.h>
#include <m_database.h>
#include <sqlite3.h>
#include <string>

static int callback_pending(void* passthrough,int argc,char** argv,char** col)
    {
        std::vector<Microsun::Problem*>* tmp=(std::vector<Microsun::Problem*>*) passthrough;
        Microsun::Problem* T=new Microsun::Problem();
        T->reg_id=atoi(*argv);
        T->plant=(*tmp->begin())->database->getPlant(argv[1]);
        T->Pos=atoi(argv[2]);
        T->Type=argv[3];
        T->ErrorCode=argv[4];
        T->ReportedDate->fromString(argv[5]);
        (*tmp->begin())->database->get_user(argv[6],"all",T->ReportedUser);
        T->ErrorNotes=argv[7];
        (*tmp)[0]->database->get_user(argv[8],"all",T->AssignedMech);
        tmp->push_back(T);
    return 0;
    }

static int callback_stored(void* passthrough,int argc,char** argv,char** col)
    {
        std::vector<Microsun::Problem*>* tmp=(std::vector<Microsun::Problem*>*) passthrough;
        Microsun::Problem* T=new Microsun::Problem();
        T->reg_id=atoi(*argv);
        T->plant=(*tmp->begin())->database->getPlant(argv[1]);
        T->Pos=atoi(argv[2]);
        T->Type=argv[3];
        T->ErrorCode=argv[4];
        T->ReportedDate->fromString(argv[5]);
        (*tmp->begin())->database->get_user(argv[6],"all",T->ReportedUser);
        T->ErrorNotes=argv[7];
        (*tmp)[0]->database->get_user(argv[8],"all",T->AssignedMech);
        T->ResolvedDate->fromString(argv[9]);
        T->MechNotes=argv[10];
        tmp->push_back(T);
    return 0;
    }

static int callback_pending_count(void* passthrough,int argc,char** argv,char** col)
    {
        int* count=(int*) passthrough;
        *count=atoi(*argv);
    return 0;
    } 

Php::Value Microsun::Database::getPendingCount()
    {
        char* errmsg;
        std::string sql;
        sqlite3* db;
        sql="SELECT COUNT(*) FROM PENDING_ERRORS;";
        int tmp;
        sqlite3_open(this->Path.c_str(),&db);
        int check=sqlite3_exec(db, sql.c_str(),callback_pending_count,(void*)&tmp,&errmsg);
        sqlite3_close(db);
    return tmp;
    }

Php::Value Microsun::Database::getPending()
    {
        char* errmsg;
        std::string sql;
        sqlite3* db;
        std::vector<Microsun::Problem*> tmp;
        Microsun::Problem* dummy=new Microsun::Problem(this);
        tmp.push_back(dummy);
        sql="SELECT * FROM PENDING_ERRORS;";
        sqlite3_open(this->Path.c_str(),&db);
        int check=sqlite3_exec(db, sql.c_str(),callback_pending,(void*)&tmp,&errmsg);
        sqlite3_close(db);
        tmp.erase(tmp.begin());
        std::vector<Php::Object> phptmp;
        for(int j=0;j<tmp.size();j++)
            phptmp.push_back(Php::Object("MicrosunProblem",tmp[j]));
    return phptmp;
    }

Php::Value Microsun::Database::getStored()
    {
        char* errmsg;
        std::string sql;
        sqlite3* db;
        std::vector<Microsun::Problem*> tmp;
        Microsun::Problem* dummy=new Microsun::Problem(this);
        tmp.push_back(dummy);
        sql="SELECT * FROM TEMP_STORED_ERRORS;";
        sqlite3_open(this->Path.c_str(),&db);
        int check=sqlite3_exec(db, sql.c_str(),callback_stored,(void*)&tmp,&errmsg);
        sqlite3_close(db);
        tmp.erase(tmp.begin());
        std::vector<Php::Object> phptmp;
        for(int j=0;j<tmp.size();j++)
            phptmp.push_back(Php::Object("MicrosunProblem",tmp[j]));
    return phptmp;
    }
    
static int callback_pending_single(void* passthrough,int argc,char** argv,char** col)
    {
        Microsun::Problem* T=(Microsun::Problem*) passthrough;
        T->reg_id=atoi(*argv);
        T->plant=T->database->getPlant(argv[1]);
        T->Pos=atoi(argv[2]);
        T->Type=argv[3];
        T->ErrorCode=argv[4];
        T->ReportedDate->fromString(argv[5]);
        T->database->get_user(argv[6],"all",T->ReportedUser);
        T->ErrorNotes=argv[7];
        T->database->get_user(argv[8],"all",T->AssignedMech);
    return 0;
    }

std::string Microsun::Database::store_error(Microsun::Problem* error,std::string table)
    {
        char* errmsg;
        sqlite3* db;
        std::string sql="INSERT INTO "+table+" VALUES("+std::to_string(error->reg_id)+",'"+error->plant->ID+"',"+std::to_string(error->Pos)+",'"+error->Type+"','"+error->ErrorCode+"','"+error->ReportedDate->toString()+"','"+error->ReportedUser->username+"','"+error->ErrorNotes+"','"+error->AssignedMech->username+"','"+error->ResolvedDate->toString()+"','"+error->MechNotes+"');";
        sqlite3_open(this->Path.c_str(),&db);
        int check=sqlite3_exec(db, sql.c_str(),NULL,NULL,&errmsg);
        sqlite3_close(db);
        return sql;
    }

Php::Value Microsun::Database::tempError(Php::Parameters &arg)
    {
        char* errmsg;
        sqlite3* db;
        Microsun::Problem* tmp=new Microsun::Problem(this);
        std::string sql="SELECT * FROM PENDING_ERRORS WHERE ID="+arg[0].stringValue()+";";
        sqlite3_open(this->Path.c_str(),&db);
        int check=sqlite3_exec(db, sql.c_str(),callback_pending_single,(void*)tmp,&errmsg);
        sqlite3_close(db);
        Time* t=new Time();
        t->getTime();
        tmp->ResolvedDate=t;
        std::string temp=arg[1].stringValue();
        tmp->MechNotes=temp;
        std::string test=this->store_error(tmp,"TEMP_STORED_ERRORS");
    return sql;
    }
