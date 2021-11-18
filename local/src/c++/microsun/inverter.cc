#include <database.h>
#include <mariadb/mariadb_com.h>

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

UniClient::Microsun::Inverter* UniClient::Database::getInverterByModel(std::string model)
  {
    MYSQL *mysql;
    MYSQL_STMT *stmt;
    MYSQL_BIND bind[1];
    unsigned int array_size= 1;


    mysql= mysql_init(NULL);
    mysql_set_character_set(mysql,"utf8mb4");

    enum mysql_protocol_type prot_type= MYSQL_PROTOCOL_SOCKET;
    mysql_optionsv(mysql, MYSQL_OPT_PROTOCOL, (void *)&prot_type);

    /* connect to MariaDB server */
    if (!mysql_real_connect(mysql,this->host,this->user,this->passwd, 
                            this->microsun, 0,this->unix_socket, 0))
      show_mysql_error(mysql);


    stmt= mysql_stmt_init(mysql);
    std::string sql="SELECT * FROM inverters WHERE MODEL=?;";

    if (mysql_stmt_prepare(stmt, sql.c_str(), -1))
      show_stmt_error(stmt);

    memset(bind, '\0', sizeof(MYSQL_BIND) * 1);

    /* We autogenerate id's, so all indicators are STMT_INDICATOR_NULL */

    char NTS_INDICATOR=STMT_INDICATOR_NTS;

    bind[0].buffer_type= MYSQL_TYPE_TINY_BLOB;
    bind[0].buffer= (void*)model.data();
    bind[0].u.indicator= &NTS_INDICATOR;

    /* set array size */
    mysql_stmt_attr_set(stmt, STMT_ATTR_ARRAY_SIZE, &array_size);

    /* set row size */
    size_t row_size=2*model.length();

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
    UniClient::Microsun::Inverter* tmp=new UniClient::Microsun::Inverter();
    for(unsigned int j=0;j<n_rows;j++)
        {
            tmp->ID=atol(argv[0]);
            tmp->Model=argv[1];
            tmp->Type=argv[2];
        }

    mysql_stmt_close(stmt);
  return tmp;
  }

