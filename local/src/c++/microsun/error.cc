#include <database.h>
#include <mariadb/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void show_mysql_error(MYSQL *mysql)
{
  printf("Error(%d) [%s] \"%s\"", mysql_errno(mysql),
                                  mysql_sqlstate(mysql),
                                  mysql_error(mysql));
  exit(-1);
}

static void show_stmt_error(MYSQL_STMT *stmt)
{
  printf("Error(%d) [%s] \"%s\"", mysql_stmt_errno(stmt),
                                  mysql_stmt_sqlstate(stmt),
                                  mysql_stmt_error(stmt));
  exit(-1);
}

unsigned long long int UniClient::Database::storeError(UniClient::Microsun::Problem* problem,std::string table)
  {
    MYSQL *mysql;
    MYSQL_STMT *stmt;
    MYSQL_BIND bind[11];
    char reg_id=STMT_INDICATOR_NULL;
    unsigned int array_size= 1;


    mysql= mysql_init(NULL);
    mysql_set_character_set(mysql,"utf8mb4");

    /* connect to MariaDB server */
    if (!mysql_real_connect(mysql,this->host,this->user,this->passwd, 
                            this->microsun, 0,this->unix_socket, 0))
      show_mysql_error(mysql);


    stmt= mysql_stmt_init(mysql);
    std::string sql;
    if(table=="pending_errors")
      sql="INSERT INTO "+table+" VALUES (?,?,?,?,?,?,?,?,?)";
    else
      sql="INSERT INTO "+table+" VALUES (?,?,?,?,?,?,?,?,?,?,?)";

    if (mysql_stmt_prepare(stmt, sql.c_str(), -1))
      show_stmt_error(stmt);

    memset(bind, '\0', sizeof(MYSQL_BIND) * 11);

    /* We autogenerate id's, so all indicators are STMT_INDICATOR_NULL */

    char NTS_INDICATOR=STMT_INDICATOR_NTS;
    char NONE_INDICATOR=STMT_INDICATOR_NONE;

    if(table=="pending_errors")
      {
        bind[0].u.indicator= &reg_id;
        bind[0].buffer_type= MYSQL_TYPE_LONGLONG;
      }

    else
      {
        bind[0].buffer_type= MYSQL_TYPE_LONG;
        bind[0].buffer= &problem->reg_id;
        bind[0].u.indicator= &NONE_INDICATOR;
      }

    bind[1].buffer_type= MYSQL_TYPE_TINY_BLOB;
    bind[1].buffer= (void*)problem->plant->ID.data();
    bind[1].u.indicator= &NTS_INDICATOR;

    bind[2].buffer_type= MYSQL_TYPE_LONG;
    bind[2].buffer= &problem->Pos;
    bind[2].u.indicator= &NONE_INDICATOR;

    bind[3].buffer_type= MYSQL_TYPE_TINY_BLOB;
    bind[3].buffer= (void*)problem->Type.data();
    bind[3].u.indicator= &NTS_INDICATOR;

    bind[4].buffer_type= MYSQL_TYPE_TINY_BLOB;
    bind[4].buffer= (void*)problem->ErrorCode.data();
    bind[4].u.indicator= &NTS_INDICATOR;

    bind[5].buffer_type= MYSQL_TYPE_TINY_BLOB;
    bind[5].buffer= (void*)problem->ReportedDate->toString().data();;
    bind[5].u.indicator= &NTS_INDICATOR;

    bind[6].buffer_type= MYSQL_TYPE_TINY_BLOB;
    bind[6].buffer= (void*)problem->ReportedUser->username.data();
    bind[6].u.indicator= &NTS_INDICATOR;

    bind[7].buffer_type= MYSQL_TYPE_TINY_BLOB;
    bind[7].buffer= (void*)problem->ErrorNotes.data();
    bind[7].u.indicator= &NTS_INDICATOR;

    bind[8].buffer_type= MYSQL_TYPE_TINY_BLOB;
    bind[8].buffer= (void*)problem->AssignedMech->username.data();
    bind[8].u.indicator= &NTS_INDICATOR;

    if(table!="pending_errors")
      {
        bind[9].buffer_type= MYSQL_TYPE_TINY_BLOB;
        bind[9].buffer= (void*)problem->ResolvedDate->toString().data();
        bind[9].u.indicator= &NTS_INDICATOR;

        bind[10].buffer_type= MYSQL_TYPE_TINY_BLOB;
        bind[10].buffer= (void*)problem->MechNotes.data();
        bind[10].u.indicator= &NTS_INDICATOR;
      }
    /* set array size */
    mysql_stmt_attr_set(stmt, STMT_ATTR_ARRAY_SIZE, &array_size);

    /* set row size */
    size_t row_size=2*(
      sizeof(reg_id)
      +problem->plant->ID.size()
      +problem->Type.size()
      +sizeof(problem->Pos)
      +problem->ErrorCode.size()
      +problem->ReportedDate->toString().size()
      +problem->ReportedUser->username.size()
      +problem->ErrorNotes.size()
      +problem->AssignedMech->username.size()
      +problem->ResolvedDate->toString().size()
      +problem->MechNotes.size()
    );
    mysql_stmt_attr_set(stmt, STMT_ATTR_ROW_SIZE, &row_size);

    /* bind parameter */
    mysql_stmt_bind_param(stmt, bind);

    /* execute */
    if (mysql_stmt_execute(stmt))
      show_stmt_error(stmt);

    my_ulonglong id=mysql_stmt_insert_id(stmt);
    mysql_stmt_close(stmt);
    mysql_close(mysql);
  return id;
  }

Php::Value UniClient::Database::getPendingCount()
    {
        MYSQL *mysql= mysql_init(NULL);
        std::string sql="SELECT COUNT(*) FROM pending_errors;";
        mysql_set_character_set(mysql,"utf8mb4");
        mysql_real_connect(mysql,this->host,this->user,this->passwd, 
                          this->microsun, 0, "/var/run/mysqld/mysqld.sock", 0);
        mysql_real_query(mysql,sql.c_str(),sql.length());
        MYSQL_RES *res=mysql_store_result(mysql);
        mysql_close(mysql);
        MYSQL_ROW row=mysql_fetch_row(res);
        printf("pending errors are %i\n",atoi(row[0]));
    return atoi(row[0]);
    }

Php::Value UniClient::Database::getPending()
    {
        std::string sql="SELECT * FROM pending_errors;";
        MYSQL *mysql= mysql_init(NULL);
        mysql_set_character_set(mysql,"utf8mb4");
        mysql_real_connect(mysql,this->host,this->user,this->passwd, 
                          this->microsun, 0, "/var/run/mysqld/mysqld.sock", 0);
        mysql_real_query(mysql,sql.c_str(),sql.length());
        MYSQL_RES *res=mysql_store_result(mysql);
        mysql_close(mysql);
        MYSQL_ROW argv=mysql_fetch_row(res);
        my_ulonglong n_rows=mysql_num_rows(res);
        std::vector<Microsun::Problem*> tmp;
        tmp.reserve(n_rows);
        for(unsigned long int j=0;j<n_rows;j++)
            {
              UniClient::Microsun::Problem* T=new UniClient::Microsun::Problem();
              T->reg_id=atoi(*argv);
              //T->plant=this->getPlant(argv[1]);
              T->Pos=atoi(argv[2]);
              T->Type=argv[3];
              T->ErrorCode=argv[4];
              T->ReportedDate->fromString(argv[5]);
              this->get_user(argv[6],"all",T->ReportedUser);
              T->ErrorNotes=argv[7];
              this->get_user(argv[8],"all",T->AssignedMech);
              tmp.push_back(T);
            }
          std::vector<Php::Object> phptmp;
          for(unsigned long int j=0;j<tmp.size();j++)
              phptmp.push_back(Php::Object("MicrosunProblem",tmp[j]));
    return phptmp;
    }

Php::Value UniClient::Database::getStored()
    {
        std::string sql="SELECT * FROM temp_stored_errors;";
        MYSQL *mysql= mysql_init(NULL);
        mysql_set_character_set(mysql,"utf8mb4");
        mysql_real_connect(mysql,this->host,this->user,this->passwd, 
                          this->microsun, 0, "/var/run/mysqld/mysqld.sock", 0);
        mysql_real_query(mysql,sql.c_str(),sql.length());
        MYSQL_RES *res=mysql_store_result(mysql);
        mysql_close(mysql);
        MYSQL_ROW argv=mysql_fetch_row(res);
        my_ulonglong n_rows=mysql_num_rows(res);
        std::vector<Microsun::Problem*> tmp;
        tmp.reserve(n_rows);
        for(unsigned long int j=0;j<n_rows;j++)
            {
              UniClient::Microsun::Problem* T=new UniClient::Microsun::Problem();
              T->reg_id=atoi(*argv);
              //T->plant=this->getPlant(argv[1]);
              T->Pos=atoi(argv[2]);
              T->Type=argv[3];
              T->ErrorCode=argv[4];
              T->ReportedDate->fromString(argv[5]);
              this->get_user(argv[6],"all",T->ReportedUser);
              T->ErrorNotes=argv[7];
              this->get_user(argv[8],"all",T->AssignedMech);
              T->ResolvedDate->fromString(argv[9]);
              T->MechNotes=argv[10];
              tmp.push_back(T);
            }
          std::vector<Php::Object> phptmp;
          for(unsigned long int j=0;j<tmp.size();j++)
              phptmp.push_back(Php::Object("MicrosunProblem",tmp[j]));
    return phptmp;
    }

Php::Value UniClient::Database::newError(Php::Parameters &arg)
    {
        Microsun::Problem* tmp=new Microsun::Problem(this);
        //tmp->plant=this->getPlant(arg[0]);
        tmp->Pos=atoi(arg[1]);
        std::string l=arg[2];
        tmp->Type=l;
        std::string t=arg[3];
        tmp->ErrorCode=t;
        std::string t1=arg[4];
        tmp->ErrorNotes=t1;
        std::string tt=arg[5];
        this->get_user(tt,"all",tmp->AssignedMech);
 
        //automatic data
        tmp->ReportedDate->getTime();
        this->get_user("root","all",tmp->ReportedUser);
        unsigned long long id=this->storeError(tmp,"pending_errors");
    return (int)id;
    }

unsigned long long int UniClient::Database::getSingle(UniClient::Microsun::Problem* problem,unsigned long long int id,std::string table)
  {
    MYSQL *mysql;
    MYSQL_STMT *stmt;
    MYSQL_BIND bind[1];
    unsigned int array_size= 1;


    mysql= mysql_init(NULL);
    mysql_set_character_set(mysql,"utf8mb4");

    /* connect to MariaDB server */
    if (!mysql_real_connect(mysql,this->host,this->user,this->passwd, 
                            this->microsun, 0,this->unix_socket, 0))
      show_mysql_error(mysql);


    stmt= mysql_stmt_init(mysql);
    std::string sql="SELECT * FROM "+table+" WHERE ID=?;";

    if (mysql_stmt_prepare(stmt, sql.c_str(), -1))
      show_stmt_error(stmt);

    memset(bind, '\0', sizeof(MYSQL_BIND) * 1);

    /* We autogenerate id's, so all indicators are STMT_INDICATOR_NULL */

    char NONE_INDICATOR=STMT_INDICATOR_NONE;

    bind[0].buffer_type= MYSQL_TYPE_LONG;
    bind[0].buffer= &id;
    bind[0].u.indicator= &NONE_INDICATOR;

    /* set array size */
    mysql_stmt_attr_set(stmt, STMT_ATTR_ARRAY_SIZE, &array_size);

    /* set row size */
    size_t row_size=2*sizeof(unsigned long long int);

    mysql_stmt_attr_set(stmt, STMT_ATTR_ROW_SIZE, &row_size);

    /* bind parameter */
    mysql_stmt_bind_param(stmt, bind);

    /* execute */
    if (mysql_stmt_execute(stmt))
      show_stmt_error(stmt);

    MYSQL_RES *res=mysql_store_result(mysql);
    mysql_close(mysql);

    MYSQL_ROW argv=mysql_fetch_row(res);
    my_ulonglong n_rows=mysql_num_rows(res);
    for(unsigned int j=0;j<n_rows;j++)
        {
          problem->reg_id=atoi(*argv);
          //problem->plant=this->getPlant(argv[1]);
          problem->Pos=atoi(argv[2]);
          problem->Type=argv[3];
          problem->ErrorCode=argv[4];
          problem->ReportedDate->fromString(argv[5]);
          this->get_user(argv[6],"all",problem->ReportedUser);
          problem->ErrorNotes=argv[7];
          this->get_user(argv[8],"all",problem->AssignedMech);
          if(table!="pending_errors")
            {
              problem->ResolvedDate->fromString(argv[9]);
              problem->MechNotes=argv[10];
            }
        }

    mysql_stmt_close(stmt);
  return id;
  }

unsigned long long int UniClient::Database::deleteError(std::string table,unsigned long long int id)
  {
    MYSQL *mysql;
    MYSQL_STMT *stmt;
    MYSQL_BIND bind[1];
    unsigned int array_size= 1;


    mysql= mysql_init(NULL);
    mysql_set_character_set(mysql,"utf8mb4");

    /* connect to MariaDB server */
    if (!mysql_real_connect(mysql,this->host,this->user,this->passwd, 
                            this->microsun, 0,this->unix_socket, 0))
      show_mysql_error(mysql);


    stmt= mysql_stmt_init(mysql);
    std::string sql="DELETE FROM "+table+" WHERE ID=?;";

    if (mysql_stmt_prepare(stmt, sql.c_str(), -1))
      show_stmt_error(stmt);

    memset(bind, '\0', sizeof(MYSQL_BIND) * 1);

    /* We autogenerate id's, so all indicators are STMT_INDICATOR_NULL */

    char NONE_INDICATOR=STMT_INDICATOR_NONE;

    bind[0].buffer_type= MYSQL_TYPE_LONG;
    bind[0].buffer= &id;
    bind[0].u.indicator= &NONE_INDICATOR;

    /* set array size */
    mysql_stmt_attr_set(stmt, STMT_ATTR_ARRAY_SIZE, &array_size);

    /* set row size */
    size_t row_size=2*sizeof(unsigned long long int);

    mysql_stmt_attr_set(stmt, STMT_ATTR_ROW_SIZE, &row_size);

    /* bind parameter */
    mysql_stmt_bind_param(stmt, bind);

    /* execute */
    if (mysql_stmt_execute(stmt))
      show_stmt_error(stmt);


    mysql_close(mysql);
    mysql_stmt_close(stmt);
  return id;
  }

Php::Value UniClient::Database::tempError(Php::Parameters &arg) 
    {
        unsigned long int id=atoi(arg[0]);
        std::string notes=arg[1]; 
        Microsun::Problem* tmp=new Microsun::Problem(this);
        this->getSingle(tmp,id,"pending_errors");
        tmp->MechNotes=notes;
        this->storeError(tmp,"temp_stored_errors");
        this->deleteError("pending_errors",id);
    return (int)id;
    }
 

Php::Value UniClient::Database::resolve_error(Php::Parameters &arg) 
    {
        unsigned long int id=atoi(arg[0]);
        std::string notes=arg[1]; 
        Microsun::Problem* tmp=new Microsun::Problem(this);
        this->getSingle(tmp,id,"temp_stored_errors");
        tmp->MechNotes=notes;
        this->storeError(tmp,"error_log");
        this->deleteError("temp_stored_errors",id);
    return (int)id;
    }
 
