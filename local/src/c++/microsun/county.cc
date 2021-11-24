#include <database.h>

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

UniClient::data::County* UniClient::Database::getCountyByName(std::string name)
  {
    MYSQL *mysql;
    MYSQL_STMT *stmt;
    MYSQL_BIND bind[1];
    unsigned int array_size= 1;


    mysql= mysql_init(NULL);
    mysql_set_character_set(mysql,"utf8mb4");

    enum mysql_protocol_type prot_type= MYSQL_PROTOCOL_TCP;
    mysql_optionsv(mysql, MYSQL_OPT_PROTOCOL, (void *)&prot_type);
    mysql_optionsv(mysql, MYSQL_SET_CHARSET_NAME, (void *)"utf8mb4");

    /* connect to MariaDB server */
    if (!mysql_real_connect(mysql,this->host,this->user,this->passwd, 
                            this->system, 0,this->unix_socket, 0))
      show_mysql_error(mysql);


    stmt= mysql_stmt_init(mysql);
    std::string sql="SELECT * FROM counties WHERE NAME=?;";

    if (mysql_stmt_prepare(stmt, sql.c_str(), -1))
      show_stmt_error(stmt);

    memset(bind, '\0', sizeof(MYSQL_BIND) * 1);

    /* We autogenerate id's, so all indicators are STMT_INDICATOR_NULL */

    char NTS_INDICATOR=STMT_INDICATOR_NTS;

    bind[0].buffer_type= MYSQL_TYPE_TINY_BLOB;
    bind[0].buffer= (void*)name.data();
    bind[0].u.indicator= &NTS_INDICATOR;

    /* set array size */
    mysql_stmt_attr_set(stmt, STMT_ATTR_ARRAY_SIZE, &array_size);

    /* set row size */
    size_t row_size=2*name.length();

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
    UniClient::data::County* tmp=new UniClient::data::County();
    for(unsigned int j=0;j<n_rows;j++)
        {
          tmp->ID=atoi(*argv);
          tmp->Name=argv[1];
          tmp->Capital=argv[2];
          tmp->Area=atof(argv[3]);
          tmp->Population=atof(argv[4]);
          tmp->Density=atof(argv[5]);
          tmp->Region=argv[6];
        }

    mysql_stmt_close(stmt);
  return tmp;
  }

Php::Value UniClient::Database::getCounties()
    {
        std::string sql="SELECT NAME FROM counties;";
        MYSQL *mysql= mysql_init(NULL);
        mysql_set_character_set(mysql,"utf8mb4");
        enum mysql_protocol_type prot_type= MYSQL_PROTOCOL_TCP;
        mysql_optionsv(mysql, MYSQL_OPT_PROTOCOL, (void *)&prot_type);
        mysql_optionsv(mysql, MYSQL_SET_CHARSET_NAME, (void *)"utf8mb4");

        mysql_real_connect(mysql,this->host,this->user,this->passwd, 
                          this->system, 0, this->unix_socket, 0);
        mysql_real_query(mysql,sql.c_str(),sql.length());
        MYSQL_RES *res=mysql_store_result(mysql);
        mysql_close(mysql);
        MYSQL_ROW argv=mysql_fetch_row(res);
        my_ulonglong n_rows=mysql_num_rows(res);
        std::vector<UniClient::data::County*> tmp;
        tmp.reserve(n_rows);
        for(unsigned long int j=0;j<n_rows;j++)
            {
              tmp.push_back(this->getCountyByName(argv[j]));
            }
          std::vector<Php::Object> phptmp;
          for(unsigned long int j=0;j<tmp.size();j++)
              phptmp.push_back(Php::Object("MicrosunCounty",tmp[j]));
    return phptmp;
    }

Php::Value UniClient::Database::getCountyNames()
    {
        std::string sql="SELECT NAME FROM counties;";
        MYSQL *mysql= mysql_init(NULL);
        mysql_set_character_set(mysql,"utf8mb4");
        enum mysql_protocol_type prot_type= MYSQL_PROTOCOL_TCP;
        mysql_optionsv(mysql, MYSQL_OPT_PROTOCOL, (void *)&prot_type);
        mysql_optionsv(mysql, MYSQL_SET_CHARSET_NAME, (void *)"utf8mb4");

        mysql_real_connect(mysql,this->host,this->user,this->passwd, 
                          this->system, 0, this->unix_socket, 0);
        mysql_real_query(mysql,sql.c_str(),sql.length());
        MYSQL_RES *res=mysql_store_result(mysql);
        mysql_close(mysql);
        MYSQL_ROW argv=mysql_fetch_row(res);
        my_ulonglong n_rows=mysql_num_rows(res);
        //std::string* tmp[n_rows];
        //for(unsigned long int j=0;j<n_rows;j++)
            //tmp[j]=new std::string();
        ////std::vector<std::string*> tmp;
        ////tmp.reserve(n_rows);
        //for(unsigned long int j=0;j<n_rows;j++)
            //{
              ////std::string* t=new std::string();
              ////t->assign(argv[j]);
              ////tmp.push_back(t);
              //tmp[j]->assign(argv[j]);
            //}
          //std::vector<Php::Value> phptmp;
          //for(unsigned long int j=0;j<n_rows;j++)
              //phptmp.push_back(tmp[j]);
          //std::vector<Php::Value> phptmp;
          //for(unsigned long int j=0;j<n_rows;j++)
              //phptmp.push_back(argv[j]);
    //return phptmp;
    //return "test";
        //std::vector<std::string> t;
        //for(unsigned long int j=0;j<n_rows;j++)
            //t.push_back(argv[j]);
    //return t;
    return *argv;
    }
