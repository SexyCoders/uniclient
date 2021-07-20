#include <m_database.h>
#include <sqlite3.h>

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
        Microsun::Database* THIS=(Microsun::Database*) passthrough;
        Microsun::Group t;
        t.name=*argv;
        std::vector<std::string> T;
        split(argv[1],&T);

        int size=T.size();
        
        sqlite3* db;
        sqlite3_open(THIS->Path.c_str(),&db);
        char* errmsg;
        for(int j=0;j<size;j++)
            {
                Microsun::User temp;
                std::string sql="SELECT \
                ID,FNAME,LNAME,DATEOFBIRTH,EMAIL,PHONE,ZIP,ADDRESS,NOTES,HIREDATE,USERNAME,USERGROUP \
                FROM USERS WHERE USERNAME='"+T[j]+"';";
                sqlite3_exec(db,sql.c_str(),user_callback,(void*)&temp,&errmsg);
                t.users.push_back(temp);
            }
        sqlite3_close(db);
        THIS->groups.push_back(t);
    return 0;
    }

void Microsun::Database::get_groups()
    {
        sqlite3* db;
        sqlite3_open(this->Path.c_str(),&db);
        char* errmsg;
        sqlite3_exec(db,"SELECT * FROM GROUPS;",group_callback,(void*)this,&errmsg);
        sqlite3_close(db);
    }

int Microsun::Database::get_user(std::string username,std::string grp,Microsun::User* result)
    {
        for(int j=0;j<this->groups.size();j++)
            {
                if(groups[j].name!=grp && grp!="all")
                    continue;
                else
                    {
                        for(int i=0;i<groups[j].users.size();i++)
                            {
                                if(groups[j].users[i].username==username)
                                    *result=groups[j].users[i];
                            }
                    }
            }
        return 0;
    }

