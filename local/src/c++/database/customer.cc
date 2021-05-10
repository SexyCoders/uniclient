#include <customer.h>
#include <database.h>
#include <string>

int UniClient::Database::get(std::string param,unsigned int id,UniClient::Customer *out)
	{
		std::vector<std::vector<std::string>> t;
		std::string sql="SELECT * FROM CUSTOMERS WHERE ID="+std::to_string(id)+";";
		printf("%s\n",sql.c_str());
		this->exec(sql.c_str(),&t);
		out->setID(atoi(t[0][0].c_str()));
		out->setCompany(t[0][1]);
		out->setFirstName(t[0][2]);
		out->setLastName(t[0][3]);
		out->setPhoneNumber(atol(t[0][4].c_str()));
		out->setemail(t[0][5]);
		out->setAddress(t[0][6]);
		out->setzip(atoi(t[0][7].c_str()));
		out->setTIN(atoi(t[0][8].c_str()));
		out->setNotes(t[0][9]);
		Time t1;
		t1.fromString(t[0][10]);
		out->setAdded(t1);
		Time t2;
		t2.fromString(t[0][11]);
		out->setLastInteraction(t2);
	return 0;
	}

int UniClient::Database::put(std::string param,UniClient::Customer* in)
	{
		std::vector<std::vector<std::string>> t;
		std::string sql="INSERT INTO CUSTOMERS VALUES(";
		printf("%s\n",sql.c_str());
		sql+=std::to_string(in->getID())+",";
		sql+="'"+in->getCompany()+"'"+",";
		sql+="'"+in->getFirstName()+"'"+",";
		sql+="'"+in->getLastName()+"'"+",";
		sql+=std::to_string(in->getPhoneNumber())+",";
		sql+="'"+in->getemail()+"'"+",";
		sql+="'"+in->getAddress()+"'"+",";
		sql+=std::to_string(in->getzip())+",";
		sql+=std::to_string(in->getTIN())+",";
		sql+="'"+in->getNotes()+"'"+",";
		sql+="'"+in->getAdded().toString()+"'"+",";
		sql+="'"+in->getLastInteraction().toString()+"'"+");";
		printf("%s\n",sql.c_str());
		this->exec(sql.c_str());
	return 0;
	}
