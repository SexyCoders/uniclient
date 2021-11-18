#include <database.h>

Php::Value UniClient::Database::getCustomers()
    {
		std::string sql="SELECT ID,COMPANY,IFNULL(NAME,'NAN'),IFNULL(LNAME,'NAN'),IFNULL(PHONE,0),IFNULL(EMAIL,'NAN'),IFNULL(ADDRESS,'NAN'),IFNULL(ZIP,0),IFNULL(TIN,0),IFNULL(NOTES,'NAN') FROM customers;";
        MYSQL *mysql= mysql_init(NULL);
        mysql_set_character_set(mysql,"utf8mb4");
        enum mysql_protocol_type prot_type= MYSQL_PROTOCOL_SOCKET;
        mysql_optionsv(mysql, MYSQL_OPT_PROTOCOL, (void *)&prot_type);

        mysql_real_connect(mysql,this->host,this->user,this->passwd, 
                          this->system, 0,this->unix_socket, 0);
        mysql_real_query(mysql,sql.c_str(),sql.length());
        MYSQL_RES *res=mysql_store_result(mysql);
        mysql_close(mysql);
        MYSQL_ROW t=mysql_fetch_row(res);
        my_ulonglong n_rows=mysql_num_rows(res);
		std::vector<Php::Object> temp;
        temp.reserve(n_rows);
        for(unsigned int j=0;j<n_rows;j++)
            {
              UniClient::data::Customer* tmp=new UniClient::data::Customer();
              tmp->ID=atoi(t[0]);
              tmp->Company=t[1];
              tmp->FirstName=t[2];
              tmp->LastName=t[3];
              tmp->PhoneNumber=atol(t[4]);
              tmp->email=t[5];
              tmp->Address=t[6];
              tmp->zip=atoi(t[7]);
              tmp->TIN=atoi(t[8]);
              tmp->Notes=t[9];
              tmp->Joined->fromString(t[10]);
              tmp->LastSeen->fromString(t[11]);
              temp.push_back(Php::Object("MicrosunCustomer",tmp));
            }
    return temp;
    }

//int UniClient::Database::putCustomer(std::string param,UniClient::data::Customer* out)
//	{
//		int size=15;
//		MYSQL_BIND bind[size];
//		unsigned int t;
//		std::string tmp;
//		memset(&bind, 0, sizeof(MYSQL_BIND) * size);
//		int j=0;
//		//1 ID unsigned long
//		bind[j].buffer_type= MYSQL_TYPE_LONG;
//		t=out->ID;
//		bind[j].buffer= &t;
// 
//		//2 Company string
//		bind[++j].buffer_type= MYSQL_TYPE_STRING;
//		tmp=out->Company;
//		bind[j].buffer= (void*)tmp.c_str();
//		bind[j].buffer_length=tmp.length();
// 
//		//3 Company string
//		bind[++j].buffer_type= MYSQL_TYPE_STRING;
//		tmp=out->FirstName;
//		bind[j].buffer= (void*)tmp.c_str();
//		bind[j].buffer_length=tmp.length();
// 
//		//4 First Name string
//		bind[++j].buffer_type= MYSQL_TYPE_STRING;
//		tmp=out->FirstName;
//		bind[j].buffer= (void*)tmp.c_str();
//		bind[j].buffer_length=tmp.length();
// 
//		//5 Last Name string
//		bind[++j].buffer_type= MYSQL_TYPE_STRING;
//		tmp=out->LastName;
//		bind[j].buffer= (void*)tmp.c_str();
//		bind[j].buffer_length=tmp.length();
// 
//		//6 Occupation string
//		bind[++j].buffer_type= MYSQL_TYPE_STRING;
//		tmp=out->Occupation;
//		bind[j].buffer= (void*)tmp.c_str();
//		bind[j].buffer_length=tmp.length();
//		
//		//7 Phone Number unsigned long int
//		bind[++j].buffer_type= MYSQL_TYPE_LONG;
//		t=out->PhoneNumber;
//		bind[j].buffer=&t;
//		
//		//8 Alt Phone Number unsigned long int
//		bind[++j].buffer_type= MYSQL_TYPE_LONG;
//		t=out->AltPhoneNumber;
//		bind[j].buffer=&t;
// 
//		//9 email string
//		bind[++j].buffer_type= MYSQL_TYPE_STRING;
//		tmp=out->email;
//		bind[j].buffer= (void*)tmp.c_str();
//		bind[j].buffer_length=tmp.length();
// 
//		//10 Address string
//		bind[++j].buffer_type= MYSQL_TYPE_STRING;
//		tmp=out->Address;
//		bind[j].buffer= (void*)tmp.c_str();
//		bind[j].buffer_length=tmp.length();
// 
//		//11 Region string
//		bind[++j].buffer_type= MYSQL_TYPE_STRING;
//		tmp=out->Region;
//		bind[j].buffer= (void*)tmp.c_str();
//		bind[j].buffer_length=tmp.length();
// 
//		//12 City string
//		bind[++j].buffer_type= MYSQL_TYPE_STRING;
//		tmp=out->City;
//		bind[j].buffer= (void*)tmp.c_str();
//		bind[j].buffer_length=tmp.length();
//		
//		//13 zip unsigned long int
//		bind[++j].buffer_type= MYSQL_TYPE_LONG;
//		t=out->zip;
//		bind[j].buffer=&t;
// 
//		//14 Notes string
//		bind[++j].buffer_type= MYSQL_TYPE_STRING;
//		tmp=out->Notes;
//		bind[j].buffer= (void*)tmp.c_str();
//		bind[j].buffer_length=tmp.length();
// 
//		//15 TIN unsigned long int
//		bind[++j].buffer_type= MYSQL_TYPE_LONG;
//		t=out->TIN;
//		bind[j].buffer=&t;
// 
//		this->insert(bind,size,"CUSTOMERS");
//	return 0;
//	}
// 
