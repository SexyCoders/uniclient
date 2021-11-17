#include <database.h>

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

void UniClient::Database::get_groups()
    {
        MYSQL *mysql= mysql_init(NULL);
        std::string sql="SELECT * FROM groups;";
        mysql_set_character_set(mysql,"utf8mb4");
        mysql_real_connect(mysql,this->host,this->user,this->passwd, 
                          this->system, 0,this->unix_socket, 0);
        mysql_real_query(mysql,sql.c_str(),sql.length());
        MYSQL_RES *res=mysql_store_result(mysql);
        mysql_close(mysql);
        my_ulonglong n_rows=mysql_num_rows(res);
        for(unsigned long long int j=0;j<n_rows;j++)
            {
                UniClient::etc::Group t;
                MYSQL_ROW row=mysql_fetch_row(res);
                t.name=row[0];
                std::vector<std::string> T;
                split(row[1],&T);
                int size=T.size();
                for(int i=0;i<size;i++)
                    {
                        MYSQL *mysql= mysql_init(NULL);
                        std::string sql1="SELECT \
                        ID,FNAME,LNAME,DATEOFBIRTH,EMAIL,PHONE,ZIP,ADDRESS,NOTES,HIREDATE,USERNAME,USERGROUP \
                        FROM users WHERE USERNAME='"+T[i]+"';";
                        mysql_set_character_set(mysql,"utf8mb4");
                        mysql_real_connect(mysql,this->host,this->user,this->passwd, 
                                        this->system, 0,this->unix_socket, 0);
                        mysql_real_query(mysql,sql1.c_str(),sql1.length());
                        MYSQL_RES *res_temp=mysql_store_result(mysql);
                        mysql_close(mysql);
                        my_ulonglong n_rows_temp=mysql_num_rows(res_temp);
                        if(n_rows_temp)
                            {
                                MYSQL_ROW argv=mysql_fetch_row(res_temp);
                                UniClient::etc::User temp;
                                temp.ID=atoi(argv[0]);
                                temp.FName=argv[1];
                                temp.LName=argv[2];
                                temp.DateOfBirth.fromString(argv[3]);
                                temp.email=argv[4];
                                temp.PhoneNumber=atoi(argv[5]);
                                temp.zip=atoi(argv[6]);
                                temp.Address=argv[7];
                                temp.Notes=argv[8];
                                temp.HireDate.fromString(argv[9]);
                                temp.username=argv[10];
                                temp.group=argv[11];
                                t.users.push_back(temp);
                                printf("loading user %s...\n",temp.username.c_str());
                            }
                    }
            this->groups.push_back(t);
            }
        mysql_free_result(res);
    }
 
int UniClient::Database::get_user(std::string username,std::string grp,UniClient::etc::User* result)
    {
        for(unsigned long int j=0;j<this->groups.size();j++)
            {
                if(groups[j].name!=grp && grp!="all")
                    continue;
                else
                    {
                        for(unsigned long int i=0;i<groups[j].users.size();i++)
                            {
                                if(groups[j].users[i].username==username)
                                    *result=groups[j].users[i];
                            }
                    }
            }
        return 0;
    }
 
