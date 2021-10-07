#include <customer.h>
#include <database.h>
#include <mariadb/mariadb_com.h>
#include <string>
#include <my_time.h>

//int UniClient::Database::get(std::string param,unsigned int id,UniClient::Customer *in)
	//{
		//std::vector<std::vector<std::string>> t;
		//std::string sql="SELECT * FROM CUSTOMERS WHERE ID="+std::to_string(id)+";";
		//printf("%s\n",sql.c_str());
		//this->exec(sql.c_str(),&t);
		//in->ID=atoi(t[0][0].c_str());
		//in->Company=t[0][1];
		//in->FirstName=t[0][2];
		//in->LastName=t[0][3];
		//in->PhoneNumber=atol(t[0][4].c_str());
		//in->email=t[0][5];
		//in->Address=t[0][6];
		//in->zip=atoi(t[0][7].c_str());
		//in->TIN=atoi(t[0][8].c_str());
		//in->Notes=t[0][9];
		//in->Joined->fromString(t[0][10]);
		//in->LastSeen->fromString(t[0][11]);
	//return 0;
	//}

int UniClient::Database::put(std::string param,UniClient::Customer* out)
	{
		int size=15;
		MYSQL_BIND bind[size];
		unsigned int t;
		std::string tmp;
		memset(&bind, 0, sizeof(MYSQL_BIND) * size);
		int j=0;
		//1 ID unsigned long
		bind[j].buffer_type= MYSQL_TYPE_LONG;
		t=out->ID;
		bind[j].buffer= &t;

		//2 Company string
		bind[++j].buffer_type= MYSQL_TYPE_STRING;
		tmp=out->Company;
		bind[j].buffer= (void*)tmp.c_str();
		bind[j].buffer_length=tmp.length();

		//3 Company string
		bind[++j].buffer_type= MYSQL_TYPE_STRING;
		tmp=out->FirstName;
		bind[j].buffer= (void*)tmp.c_str();
		bind[j].buffer_length=tmp.length();

		//4 First Name string
		bind[++j].buffer_type= MYSQL_TYPE_STRING;
		tmp=out->FirstName;
		bind[j].buffer= (void*)tmp.c_str();
		bind[j].buffer_length=tmp.length();

		//5 Last Name string
		bind[++j].buffer_type= MYSQL_TYPE_STRING;
		tmp=out->LastName;
		bind[j].buffer= (void*)tmp.c_str();
		bind[j].buffer_length=tmp.length();

		//6 Occupation string
		bind[++j].buffer_type= MYSQL_TYPE_STRING;
		tmp=out->Occupation;
		bind[j].buffer= (void*)tmp.c_str();
		bind[j].buffer_length=tmp.length();
		
		//7 Phone Number unsigned long int
		bind[++j].buffer_type= MYSQL_TYPE_LONG;
		t=out->PhoneNumber;
		bind[j].buffer=&t;
		
		//8 Alt Phone Number unsigned long int
		bind[++j].buffer_type= MYSQL_TYPE_LONG;
		t=out->AltPhoneNumber;
		bind[j].buffer=&t;

		//9 email string
		bind[++j].buffer_type= MYSQL_TYPE_STRING;
		tmp=out->email;
		bind[j].buffer= (void*)tmp.c_str();
		bind[j].buffer_length=tmp.length();

		//10 Address string
		bind[++j].buffer_type= MYSQL_TYPE_STRING;
		tmp=out->Address;
		bind[j].buffer= (void*)tmp.c_str();
		bind[j].buffer_length=tmp.length();

		//11 Region string
		bind[++j].buffer_type= MYSQL_TYPE_STRING;
		tmp=out->Region;
		bind[j].buffer= (void*)tmp.c_str();
		bind[j].buffer_length=tmp.length();

		//12 City string
		bind[++j].buffer_type= MYSQL_TYPE_STRING;
		tmp=out->City;
		bind[j].buffer= (void*)tmp.c_str();
		bind[j].buffer_length=tmp.length();
		
		//13 zip unsigned long int
		bind[++j].buffer_type= MYSQL_TYPE_LONG;
		t=out->zip;
		bind[j].buffer=&t;

		//14 Notes string
		bind[++j].buffer_type= MYSQL_TYPE_STRING;
		tmp=out->Notes;
		bind[j].buffer= (void*)tmp.c_str();
		bind[j].buffer_length=tmp.length();

		//15 TIN unsigned long int
		bind[++j].buffer_type= MYSQL_TYPE_LONG;
		t=out->TIN;
		bind[j].buffer=&t;

		this->insert(bind,size,"CUSTOMERS");
	return 0;
	}
