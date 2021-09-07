#include <microsun.h>
#include <m_database.h>
#include <sqlite3.h>

static int callback_log(void* passthrough,int argc,char** argv,char** col)
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


Php::Value Microsun::Database::getPlantLog(Php::Parameters &arg)
    {
        char* errmsg;
        std::string sql;
        sqlite3* db;
        std::vector<Microsun::Problem*> tmp;
        Microsun::Problem* dummy=new Microsun::Problem(this);
        tmp.push_back(dummy);
        sql="SELECT * FROM "+arg[0].stringValue()+" ORDER BY ID DESC LIMIT 30;";
        sqlite3_open(this->ErrorPath.c_str(),&db);
        int check=sqlite3_exec(db, sql.c_str(),callback_log,(void*)&tmp,&errmsg);
        sqlite3_close(db);
        tmp.erase(tmp.begin());
        std::vector<Php::Object> phptmp;
        for(int j=0;j<tmp.size();j++)
            phptmp.push_back(Php::Object("MicrosunProblem",tmp[j]));
    return phptmp;
    }
    
