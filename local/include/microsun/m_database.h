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
public:
    std::vector<Customer*> stored_customers;
    std::vector<User*> stored_users;
    std::vector<Problem*> stored_problems;
    //std::vector<Plant*> stored_plants;
    std::string string_buffer;
    Plant* plant;
    std::vector<std::string> id;
    std::vector<std::string> user_names;
    int stored_int;
public:
    Database() 
        {
            this->plant=new Plant();
        }
    virtual ~Database() {}
    Php::Value phpResolveError(Php::Parameters &arg)
        {
        return this->ResolveError(arg[0],arg[1].stringValue());
        }
    int ResolveError(int,std::string);
    Php::Value CheckDb();
    Php::Value phpgetStoredInt()
        {
        return this->stored_int;
        }
    Php::Value getDataPath() const 
    { 
        return DataPath; 
    }
    Php::Value getDBPath() const 
    { 
        return Path; 
    }
    Php::Value getbufferPath() const 
    { 
        return buffer; 
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
            return Php::Object("Plant",this->plant);
        }
    Php::Value getID()
        {
            return this->id;
        }
    Php::Value getStoredProblems()
        {
            std::vector<Php::Object> tmp;
            for(int j=0;j<this->stored_problems.size();j++)
                tmp.push_back(Php::Object("Problem",this->stored_problems[j]));
            return tmp;
        }
    std::any get(std::string);
    std::any get(std::string,std::string);
    std::any put(std::string);
    std::any put(std::string,std::string,std::string,int,std::string,std::string,std::string,std::string);
    Php::Value phpput(Php::Parameters &arg);
    Php::Value del(Php::Parameters &arg);
    Php::Value phpget(Php::Parameters &arg);
    Php::Value phpgetUserNames()
        {
            return this->user_names;
        }
        };
};
#endif
