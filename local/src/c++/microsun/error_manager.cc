#include <microsun.h>
#include <database.h>
#include <sqlite3.h>
#include <string>

//static int callback_pending(void* passthrough,int argc,char** argv,char** col)
//    {
//        std::vector<Microsun::Problem*>* tmp=(std::vector<Microsun::Problem*>*) passthrough;
//        Microsun::Problem* T=new Microsun::Problem();
//        T->reg_id=atoi(*argv);
//        T->plant=(*tmp->begin())->database->getPlant(argv[1]);
//        T->Pos=atoi(argv[2]);
//        T->Type=argv[3];
//        T->ErrorCode=argv[4];
//        T->ReportedDate->fromString(argv[5]);
//        (*tmp->begin())->database->get_user(argv[6],"all",T->ReportedUser);
//        T->ErrorNotes=argv[7];
//        (*tmp)[0]->database->get_user(argv[8],"all",T->AssignedMech);
//        tmp->push_back(T);
//    return 0;
//    }
// 
//static int callback_stored(void* passthrough,int argc,char** argv,char** col)
//    {
//        std::vector<Microsun::Problem*>* tmp=(std::vector<Microsun::Problem*>*) passthrough;
//        Microsun::Problem* T=new Microsun::Problem();
//        T->reg_id=atoi(*argv);
//        T->plant=(*tmp->begin())->database->getPlant(argv[1]);
//        T->Pos=atoi(argv[2]);
//        T->Type=argv[3];
//        T->ErrorCode=argv[4];
//        T->ReportedDate->fromString(argv[5]);
//        (*tmp->begin())->database->get_user(argv[6],"all",T->ReportedUser);
//        T->ErrorNotes=argv[7];
//        (*tmp)[0]->database->get_user(argv[8],"all",T->AssignedMech);
//        T->ResolvedDate->fromString(argv[9]);
//        T->MechNotes=argv[10];
//        tmp->push_back(T);
//    return 0;
//    }
// 
//static int callback_pending_count(void* passthrough,int argc,char** argv,char** col)
//    {
//        int* count=(int*) passthrough;
//        *count=atoi(*argv);
//    return 0;
//    } 
// 
//Php::Value Microsun::Database::getPendingCount()
//    {
//        char* errmsg;
//        std::string sql;
//        sqlite3* db;
//        sql="SELECT COUNT(*) FROM PENDING_ERRORS;";
//        int tmp;
//        sqlite3_open(this->Path.c_str(),&db);
//        int check=sqlite3_exec(db, sql.c_str(),callback_pending_count,(void*)&tmp,&errmsg);
//        sqlite3_close(db);
//    return tmp;
//    }
// 
//Php::Value Microsun::Database::getPending()
//    {
//        char* errmsg;
//        std::string sql;
//        sqlite3* db;
//        std::vector<Microsun::Problem*> tmp;
//        Microsun::Problem* dummy=new Microsun::Problem(this);
//        tmp.push_back(dummy);
//        sql="SELECT * FROM PENDING_ERRORS;";
//        sqlite3_open(this->Path.c_str(),&db);
//        int check=sqlite3_exec(db, sql.c_str(),callback_pending,(void*)&tmp,&errmsg);
//        sqlite3_close(db);
//        tmp.erase(tmp.begin());
//        std::vector<Php::Object> phptmp;
//        for(int j=0;j<tmp.size();j++)
//            phptmp.push_back(Php::Object("MicrosunProblem",tmp[j]));
//    return phptmp;
//    }
// 
//Php::Value Microsun::Database::getStored()
//    {
//        char* errmsg;
//        std::string sql;
//        sqlite3* db;
//        std::vector<Microsun::Problem*> tmp;
//        Microsun::Problem* dummy=new Microsun::Problem(this);
//        tmp.push_back(dummy);
//        sql="SELECT * FROM TEMP_STORED_ERRORS;";
//        sqlite3_open(this->Path.c_str(),&db);
//        int check=sqlite3_exec(db, sql.c_str(),callback_stored,(void*)&tmp,&errmsg);
//        sqlite3_close(db);
//        tmp.erase(tmp.begin());
//        std::vector<Php::Object> phptmp;
//        for(int j=0;j<tmp.size();j++)
//            phptmp.push_back(Php::Object("MicrosunProblem",tmp[j]));
//    return phptmp;
//    }
//    
//static int callback_pending_single(void* passthrough,int argc,char** argv,char** col)
//    {
//        Microsun::Problem* T=(Microsun::Problem*) passthrough;
//        T->reg_id=atoi(*argv);
//        T->plant=T->database->getPlant(argv[1]);
//        T->Pos=atoi(argv[2]);
//        T->Type=argv[3];
//        T->ErrorCode=argv[4];
//        T->ReportedDate->fromString(argv[5]);
//        T->database->get_user(argv[6],"all",T->ReportedUser);
//        T->ErrorNotes=argv[7];
//        T->database->get_user(argv[8],"all",T->AssignedMech);
//    return 0;
//    }
// 
//static int get_last_id_callback(void* passthrough,int argc,char** argv,char** col)
//    {
//        int* value=(int*) passthrough;
//        *value=atoi(*argv);
//    return 0;
//    }
// 
//unsigned long int Microsun::Database::getLastInsertId(std::string table)
//    {
//        char* errmsg;
//        sqlite3* db;
//        int temp;
//        sqlite3_open(this->Path.c_str(),&db);
//        std::string sql="select seq from sqlite_sequence where name='"+table+"';";
//        int check=sqlite3_exec(db,sql.c_str(),get_last_id_callback,(void*)&temp,&errmsg);
//        sqlite3_close(db);
//    return temp;
//    }
// 
//unsigned long int Microsun::Database::store_new_error(Microsun::Problem* error)
//    {
//        char* errmsg;
//        sqlite3* db;
//        std::string sql="INSERT INTO PENDING_ERRORS VALUES(NULL,'"+error->plant->ID+"',"+std::to_string(error->Pos)+",'"+error->Type+"','"+error->ErrorCode+"','"+error->ReportedDate->toString()+"','"+error->ReportedUser->username+"','"+error->ErrorNotes+"','"+error->AssignedMech->username+"');";
//        sqlite3_open(this->Path.c_str(),&db);
//        int check=sqlite3_exec(db, sql.c_str(),NULL,NULL,&errmsg);
//        sqlite3_close(db);
//    return this->getLastInsertId("PENDING_ERRORS");
//    }
// 
//Php::Value Microsun::Database::newError(Php::Parameters &arg)
//    {
//        Microsun::Problem* tmp=new Microsun::Problem(this);
//        tmp->plant=this->getPlant(arg[0]);
//        tmp->Pos=atoi(arg[1]);
//        std::string l=arg[2];
//        tmp->Type=l;
//        std::string t=arg[3];
//        tmp->ErrorCode=t;
//        std::string t1=arg[4];
//        tmp->ErrorNotes=t1;
//        std::string tt=arg[5];
//        this->get_user(tt,"all",tmp->AssignedMech);
// 
//        //automatic data
//        tmp->ReportedDate->getTime();
//        this->get_user("root","all",tmp->ReportedUser);
//        int id=this->store_new_error(tmp);
//    return id;
//    }
// 
//std::string Microsun::Database::store_error(Microsun::Problem* error,std::string table)
//    {
//        char* errmsg;
//        sqlite3* db;
//        std::string sql="INSERT INTO "+table+" VALUES("+std::to_string(error->reg_id)+",'"+error->plant->ID+"',"+std::to_string(error->Pos)+",'"+error->Type+"','"+error->ErrorCode+"','"+error->ReportedDate->toString()+"','"+error->ReportedUser->username+"','"+error->ErrorNotes+"','"+error->AssignedMech->username+"','"+error->ResolvedDate->toString()+"','"+error->MechNotes+"');";
//        sqlite3_open(this->Path.c_str(),&db);
//        int check=sqlite3_exec(db, sql.c_str(),NULL,NULL,&errmsg);
//        sqlite3_close(db);
//        return sql;
//    }
// 
//int Microsun::Database::delete_error(int ID_TO_DELETE,std::string table)
//    {
//        if(table=="PENDING_ERRORS" || table=="TEMP_STORED_ERRORS")
//            {
//                char* errmsg;
//                sqlite3* db;
//                std::string sql="DELETE FROM "+table+" WHERE ID="+std::to_string(ID_TO_DELETE)+";";
//                sqlite3_open(this->Path.c_str(),&db);
//                int check=sqlite3_exec(db, sql.c_str(),NULL,NULL,&errmsg);
//                sqlite3_close(db);
//            }
//        return ID_TO_DELETE;
//    };
// 
//Php::Value Microsun::Database::tempError(Php::Parameters &arg)
//    {
//        char* errmsg;
//        sqlite3* db;
//        Microsun::Problem* tmp=new Microsun::Problem(this);
//        std::string sql="SELECT * FROM PENDING_ERRORS WHERE ID="+arg[0].stringValue()+";";
//        sqlite3_open(this->Path.c_str(),&db);
//        int check=sqlite3_exec(db, sql.c_str(),callback_pending_single,(void*)tmp,&errmsg);
//        sqlite3_close(db);
//        Time* t=new Time();
//        t->getTime();
//        tmp->ResolvedDate=t;
//        std::string temp=arg[1].stringValue();
//        tmp->MechNotes=temp;
//        std::string test=this->store_error(tmp,"TEMP_STORED_ERRORS");
//        this->delete_error(atoi(arg[0]),"PENDING_ERRORS");
//    return arg[0];
//    }
// 
//static int callback_stored_single(void* passthrough,int argc,char** argv,char** col)
//    {
//        Microsun::Problem* T=(Microsun::Problem*) passthrough;
//        T->reg_id=atoi(*argv);
//        T->plant=T->database->getPlant(argv[1]);
//        T->Pos=atoi(argv[2]);
//        T->Type=argv[3];
//        T->ErrorCode=argv[4];
//        T->ReportedDate->fromString(argv[5]);
//        T->database->get_user(argv[6],"all",T->ReportedUser);
//        T->ErrorNotes=argv[7];
//        T->database->get_user(argv[8],"all",T->AssignedMech);
//        T->ResolvedDate->fromString(argv[9]);
//    return 0;
//    }
// 
//std::string Microsun::Database::log_error(Microsun::Problem* error,std::string table)
//    {
//        char* errmsg;
//        sqlite3* db;
//        std::string sql="INSERT INTO "+table+" VALUES("+std::to_string(error->reg_id)+",'"+error->plant->ID+"',"+std::to_string(error->Pos)+",'"+error->Type+"','"+error->ErrorCode+"','"+error->ReportedDate->toString()+"','"+error->ReportedUser->username+"','"+error->ErrorNotes+"','"+error->AssignedMech->username+"','"+error->ResolvedDate->toString()+"','"+error->MechNotes+"');";
//        sqlite3_open(this->ErrorPath.c_str(),&db);
//        int check=sqlite3_exec(db, sql.c_str(),NULL,NULL,&errmsg);
//        sqlite3_close(db);
//        return sql;
//    }
// 
// 
//Php::Value Microsun::Database::resolve_error(Php::Parameters &arg) 
//    {
//        unsigned long int id=atoi(arg[0]);
//        std::string notes=arg[1]; 
//        char* errmsg;
//        sqlite3* db;
//        Microsun::Problem* tmp=new Microsun::Problem(this);
//        std::string sql="SELECT * FROM TEMP_STORED_ERRORS WHERE ID="+std::to_string(id)+";";
//        sqlite3_open(this->Path.c_str(),&db);
//        int check=sqlite3_exec(db, sql.c_str(),callback_stored_single,(void*)tmp,&errmsg);
//        sqlite3_close(db);
//        tmp->MechNotes=notes;
//        std::string test=this->log_error(tmp,tmp->plant->ID);
//        this->delete_error(id,"TEMP_STORED_ERRORS");
//    return test;
//    }
// 