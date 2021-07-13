#include <microsun.h>
#include <c++/9/any>
#include <phpcpp.h>
#include <m_customer.h>
#include <string>
#include <m_plant.h>
#include <vector>
#include <m_user.h>
#include <m_problem.h>
#include <any>
#include <m_group.h>

#ifndef DATABASE_H
#define DATABASE_H

namespace Microsun{
class Database : public Php::Base
{
private:
    std::string DataPath="/var/lib/uniclient";
    std::string Path=this->DataPath+"/MICROSUN_DATABASE";
    std::string buffer=this->DataPath+"/buffer";
    std::string BUFFER=this->DataPath+"/BUFFER";
    std::string ErrorPath=this->DataPath+"/ERROR_DATABASE";

public:
    std::vector<Microsun::Customer*> stored_customers;
    std::vector<Microsun::User*> stored_users;
    std::vector<Microsun::Problem*> stored_problems;
    std::string string_buffer;
    Microsun::Plant* plant;
    std::vector<std::string> id;

    std::vector<Microsun::Group> groups;

public:
    void get_groups();
    Database() 
        {
            this->plant=new Microsun::Plant();
            this->get_groups();
        }
    virtual ~Database() {}
    Php::Value CheckDb();
    std::string getDBPath()
        { 
        return Path; 
        }
    Php::Value phpgetID() 
        { 
        return this->id; 
        }
    Php::Value getBUFFERPath() const 
    { 
        return BUFFER; 
    }
    Php::Value getStringBuffer()
        {
            return this->string_buffer;
        }
    Php::Value getStoredCustomers()
        {
            std::vector<Php::Object> tmp;
            for(int j=0;j<this->stored_customers.size();j++)
                tmp.push_back(Php::Object("MicrosunCustomer",this->stored_customers[j]));
            return tmp;
        }
    Php::Value getStoredPlants()
        {
            return Php::Object("MicrosunPlant",this->plant);
        }
    std::any get(std::string);
    std::any get(std::string,std::string);
    Php::Value phpget(Php::Parameters &arg);
        };
};
#endif
