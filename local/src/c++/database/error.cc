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

int UniClient::Database::storeError(UniClient::Microsun::Problem* problem,std::string table)
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
    std::string sql="INSERT INTO "+table+" VALUES (?,?,?,?,?,?,?,?,?,?,?)";
    if (mysql_stmt_prepare(stmt, sql.c_str(), -1))
      show_stmt_error(stmt);

    memset(bind, '\0', sizeof(MYSQL_BIND) * 11);

    /* We autogenerate id's, so all indicators are STMT_INDICATOR_NULL */

    char NTS_INDICATOR=STMT_INDICATOR_NTS;
    char NONE_INDICATOR=STMT_INDICATOR_NONE;

    bind[0].u.indicator= &reg_id;
    bind[0].buffer_type= MYSQL_TYPE_LONGLONG;

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

    bind[9].buffer_type= MYSQL_TYPE_TINY_BLOB;
    bind[9].buffer= (void*)problem->ResolvedDate->toString().data();
    bind[9].u.indicator= &NTS_INDICATOR;

    bind[10].buffer_type= MYSQL_TYPE_TINY_BLOB;
    bind[10].buffer= (void*)problem->MechNotes.data();
    bind[10].u.indicator= &NTS_INDICATOR;
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

    mysql_stmt_close(stmt);
    mysql_close(mysql);
  return 0;
  }