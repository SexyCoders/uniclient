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

Php::Value UniClient::Database::getPlants()
    { 
        std::string sql="SELECT id FROM plants;";
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
        //std::vector<Microsun::Plant*> tmp;
        //tmp.reserve(n_rows);
        std::vector<std::string> debug;
        for(unsigned long int j=0;j<n_rows;j++)
            {
              MYSQL_ROW argv=mysql_fetch_row(res);
              debug.push_back(argv[j]);
              //tmp.push_back(this->getPlant(argv[j]));
              debug.push_back(this->getPlantDebug(argv[j]));
            }
          //std::vector<Php::Object> phptmp;
          //for(unsigned long int j=0;j<tmp.size();j++)
              //phptmp.push_back("test");
              //phptmp.push_back(Php::Object("MicrosunPlant",tmp[j]));
    //return phptmp;
    return debug;
    }


//UniClient::Microsun::Plant* UniClient::Database::getPlant(std::string ID)
std::string  UniClient::Database::getPlantDebug(std::string ID)
    {
      std::string debug;
      //UniClient::Microsun::Plant* PLANT=new UniClient::Microsun::Plant();
      MYSQL *mysql;
      MYSQL_STMT *stmt;
      MYSQL_BIND bind[1];
      MYSQL_BIND bind2[2];
      unsigned int array_size= 1;


      mysql= mysql_init(NULL);
      mysql_set_character_set(mysql,"utf8mb4");

      enum mysql_protocol_type prot_type= MYSQL_PROTOCOL_TCP;
      mysql_optionsv(mysql, MYSQL_OPT_PROTOCOL, (void *)&prot_type);
      mysql_optionsv(mysql, MYSQL_SET_CHARSET_NAME, (void *)"utf8mb4");

      ////[> connect to MariaDB server <]
      if (!mysql_real_connect(mysql,this->host,this->user,this->passwd, 
                              this->microsun, 0,this->unix_socket, 0))
        show_mysql_error(mysql);


      stmt= mysql_stmt_init(mysql);
      std::string sql="select plants.ID,\
                       POWER,\
                       BOROUGH,\
                       LOCATION, \
                       plants.AREA,\
                       NPANELS,\
                       panels.*,\
                       STRINGS,\
                       mounters.*,\
                       inverters.*, \
                       constructors.*,\
                       CONNUMBER,\
                       CONDATE,\
                       TRACKBEGIN,\
                       PRICE \
                       FROM \
                       plants,\
                       panels,\
                       mounters,\
                       inverters,\
                       constructors \
                       WHERE \
                       PANEL=panels.ID AND \
                       MOUNTING=mounters.ID AND \
                       INVERTER=inverters.ID AND \
                       CONSTRUCTOR=constructors.ID AND \
                       plants.ID='"+ID+"';";

      if (mysql_stmt_prepare(stmt, sql.c_str(), -1))
        show_stmt_error(stmt);

      memset(bind, '\0', sizeof(MYSQL_BIND) * 1);

      ////[> We autogenerate id's, so all indicators are STMT_INDICATOR_NULL <]

      char NONE_INDICATOR=STMT_INDICATOR_NONE;

      bind[0].buffer_type= MYSQL_TYPE_LONG;
      bind[0].buffer= &ID;
      bind[0].u.indicator= &NONE_INDICATOR;

      ////[> set array size <]
      mysql_stmt_attr_set(stmt, STMT_ATTR_ARRAY_SIZE, &array_size);

      ////[> set row size <]
      size_t row_size=2*sizeof(unsigned long long int);

      mysql_stmt_attr_set(stmt, STMT_ATTR_ROW_SIZE, &row_size);

      ////[> bind parameter <]
      mysql_stmt_bind_param(stmt, bind);

      ////[> execute <]
      if (mysql_stmt_execute(stmt))
        show_stmt_error(stmt);

      MYSQL_RES *res=mysql_store_result(mysql);

      my_ulonglong n_rows=mysql_num_rows(res);
      for(unsigned int j=0;j<n_rows;j++)
          {
                MYSQL_ROW argv=mysql_fetch_row(res);
                debug+=argv[j];
                //PLANT->ID=argv[j];
                debug+=argv[++j];
                //PLANT->Power=atof(argv[++j]);
                debug+=argv[++j];
                //PLANT->Borough=argv[++j];
                debug+=argv[++j];
                //PLANT->Location=argv[++j];
                debug+=argv[++j];
                //PLANT->Area=atof(argv[++j]);
                debug+=argv[++j];
                //PLANT->NPanels=atoi(argv[++j]);
                debug+=argv[++j];
                //PLANT->panel->ID=atoi(argv[++j]);
                debug+=argv[++j];
                //PLANT->panel->Make=argv[++j];
                debug+=argv[++j];
                //PLANT->panel->Model=argv[++j];
                debug+=argv[++j];
                //PLANT->Strings=argv[++j];
                debug+=argv[++j];
                //PLANT->Mounting->ID=atoi(argv[++j]);
                debug+=argv[++j];
                //PLANT->Mounting->Name=argv[++j];
                debug+=argv[++j];
                //PLANT->inverter->ID=atoi(argv[++j]);
                debug+=argv[++j];
                //PLANT->inverter->Model=argv[++j];
                debug+=argv[++j];
                //PLANT->inverter->Type=argv[++j];
                debug+=argv[++j];
                //PLANT->constructor->ID=atoi(argv[++j]);
                debug+=argv[++j];
                //PLANT->constructor->Company=argv[++j];
                debug+=argv[++j];
                //PLANT->ConnectionNumber=atoi(argv[++j]);
                debug+=argv[++j];
                //PLANT->ConnectionDate->fromString(argv[++j]);
                debug+=argv[++j];
                //PLANT->TrackerBegin->fromString(argv[++j]);
                debug+=argv[++j];
                //PLANT->SellPrice=atof(argv[++j]);
          }
      mysql_stmt_close(stmt);


      //mysql_optionsv(mysql, MYSQL_OPT_PROTOCOL, (void *)&prot_type);

      //if (!mysql_real_connect(mysql,this->host,this->user,this->passwd, 
                              //this->system, 0,this->unix_socket, 0))
        //show_mysql_error(mysql);


      //stmt= mysql_stmt_init(mysql);

        //sql="select plants.id,\
             //power,\
             //customers.ID,\
             //customers.COMPANY,\
             //customers.NAME,\
             //customers.LNAME,\
             //customers.PHONE,\
             //customers.EMAIL,\
             //customers.ADDRESS,\
             //customers.ZIP,\
             //customers.TIN,\
             //customers.NOTES,\
             //counties.*,\
             //FROM \
             //customers,\
             //counties,\
             //WHERE \
             //customers.ID=(SELECT owner FROM microsun.plants WHERE id='"+ID+"';) AND\
                 //counties.ID=(SELECT county FROM microsun.plants WHERE id='"+ID+"';);";

      //if (mysql_stmt_prepare(stmt, sql.c_str(), -1))
        //show_stmt_error(stmt);

      //memset(bind2, '\0', sizeof(MYSQL_BIND) * 2);

      ////[> We autogenerate id's, so all indicators are STMT_INDICATOR_NULL <]
      //bind2[0].buffer_type= MYSQL_TYPE_LONG;
      //bind2[0].buffer= &ID;
      //bind2[0].u.indicator= &NONE_INDICATOR;

      //bind2[1].buffer_type= MYSQL_TYPE_LONG;
      //bind2[1].buffer= &ID;
      //bind2[1].u.indicator= &NONE_INDICATOR;

      ////[> set array size <]
      //mysql_stmt_attr_set(stmt, STMT_ATTR_ARRAY_SIZE, &array_size);

      ////[> set row size <]
      //row_size=4*sizeof(unsigned long long int);

      //mysql_stmt_attr_set(stmt, STMT_ATTR_ROW_SIZE, &row_size);

      ////[> bind parameter <]
      //mysql_stmt_bind_param(stmt, bind2);

      ////[> execute <]
      //if (mysql_stmt_execute(stmt))
        //show_stmt_error(stmt);

      //res=mysql_store_result(mysql);

      //n_rows=mysql_num_rows(res);
      //for(unsigned int j=0;j<n_rows;j++)
          //{
                //MYSQL_ROW argv=mysql_fetch_row(res);
                //PLANT->Owner->ID=atoi(argv[++j]);
                //PLANT->Owner->Company=argv[++j];
                //PLANT->Owner->FirstName=argv[++j];
                //PLANT->Owner->LastName=argv[++j];
                //PLANT->Owner->PhoneNumber=atoi(argv[++j]);
                //PLANT->Owner->email=argv[++j];
                //PLANT->Owner->Address=argv[++j];
                //PLANT->Owner->zip=atoi(argv[++j]);
                //PLANT->Owner->TIN=atoi(argv[++j]);
                //PLANT->Owner->Notes=argv[++j];
                //PLANT->county->ID=atoi(argv[++j]);
                //PLANT->county->Name=argv[++j];
                //PLANT->county->Capital=argv[++j];
                //PLANT->county->Area=atof(argv[++j]);
                //PLANT->county->Population=atof(argv[++j]);
                //PLANT->county->Density=atof(argv[++j]);
                //PLANT->county->Region=argv[++j];
          //}
      //mysql_stmt_close(stmt);
    //return PLANT;
    return debug;

    }
