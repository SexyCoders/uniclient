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

UniClient::Microsun::Panel* UniClient::Database::getPanelById(unsigned long int id)
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
                            this->microsun, 0,this->unix_socket, 0))
      show_mysql_error(mysql);


    stmt= mysql_stmt_init(mysql);
    std::string sql="SELECT * FROM panels WHERE ID=?;";

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
    size_t row_size=2*sizeof(id);

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
    UniClient::Microsun::Panel* tmp=new UniClient::Microsun::Panel();
    for(unsigned int j=0;j<n_rows;j++)
        {
            tmp->ID=atol(argv[0]);
            tmp->Make=argv[1];
            tmp->Model=argv[2];
        }

    mysql_stmt_close(stmt);
  return tmp;
  }

Php::Value UniClient::Database::getPanels()
    {
        std::string sql="SELECT ID FROM panels;";
        MYSQL *mysql= mysql_init(NULL);
        mysql_set_character_set(mysql,"utf8mb4");
        enum mysql_protocol_type prot_type= MYSQL_PROTOCOL_TCP;
        mysql_optionsv(mysql, MYSQL_OPT_PROTOCOL, (void *)&prot_type);
        mysql_optionsv(mysql, MYSQL_SET_CHARSET_NAME, (void *)"utf8mb4");

        mysql_real_connect(mysql,this->host,this->user,this->passwd, 
                          this->microsun, 0, this->unix_socket, 0);
        mysql_real_query(mysql,sql.c_str(),sql.length());
        MYSQL_RES *res=mysql_store_result(mysql);
        mysql_close(mysql);
        MYSQL_ROW argv=mysql_fetch_row(res);
        my_ulonglong n_rows=mysql_num_rows(res);
        std::vector<UniClient::Microsun::Panel*> tmp;
        tmp.reserve(n_rows);
        for(unsigned long int j=0;j<n_rows;j++)
            {
              tmp.push_back(this->getPanelById(atol(argv[j])));
            }
          std::vector<Php::Object> phptmp;
          for(unsigned long int j=0;j<tmp.size();j++)
              phptmp.push_back(Php::Object("MicrosunPanel",tmp[j]));
    return phptmp;
    }

Php::Value UniClient::Database::getPanelModels()
    {
        std::string sql="SELECT MODEL FROM panels;";
        MYSQL *mysql= mysql_init(NULL);
        mysql_set_character_set(mysql,"utf8mb4");
        enum mysql_protocol_type prot_type= MYSQL_PROTOCOL_TCP;
        mysql_optionsv(mysql, MYSQL_OPT_PROTOCOL, (void *)&prot_type);
        mysql_optionsv(mysql, MYSQL_SET_CHARSET_NAME, (void *)"utf8mb4");

        mysql_real_connect(mysql,this->host,this->user,this->passwd, 
                          this->microsun, 0, this->unix_socket, 0);
        mysql_real_query(mysql,sql.c_str(),sql.length());
        MYSQL_RES *res=mysql_store_result(mysql);
        mysql_close(mysql);
        my_ulonglong n_rows=mysql_num_rows(res);
        std::vector<std::string> phptmp;
        phptmp.reserve(n_rows);
        for(unsigned long int j=0;j<n_rows;j++)
            {
                MYSQL_ROW argv=mysql_fetch_row(res);
                phptmp.push_back(*argv);
            }
    return phptmp;
    }
