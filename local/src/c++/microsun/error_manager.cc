#include <microsun.h>
#include <m_database.h>
#include <sqlite3.h>

static int callback_pending(void* passthrough,int argc,char** argv,char** col)
    {
        std::vector<Microsun::Problem*>* tmp=(std::vector<Microsun::Problem*>*) passthrough;
        Microsun::Problem* T=new Microsun::Problem();
        T->reg_id=atoi(*argv);
        T->plant=(*tmp)[0]->database->getPlant(argv[1]);
        T->Type=argv[2];
        T->Pos=atoi(argv[3]);
        T->ErrorCode=argv[4];
        T->ReportedDate->fromString(argv[5]);
        (*tmp->begin())->database->get_user(argv[6],"all",T->ReportedUser);
        T->ErrorNotes=argv[7];
        (*tmp)[0]->database->get_user(argv[8],"all",T->AssignedMech);
        tmp->push_back(T);
    return 0;
    }

static int callback_pending_count(void* passthrough,int argc,char** argv,char** col)
    {
        int* count=(int*) passthrough;
        *count=atoi(*argv);
    return 0;
    } 

int Microsun::Database::getPendingCount()
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
