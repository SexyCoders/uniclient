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
public:
    std::string DataPath="/var/lib/uniclient";
    std::string Path=this->DataPath+"/MICROSUN_DATABASE";
    std::string ErrorPath=this->DataPath+"/ERROR_DATABASE";

public:
    //runtime data
    std::vector<Microsun::Group> groups;

    //store
    //std::vector<Microsun::Customer> stored_customers;
    //std::vector<Microsun::Problem> stored_problems;
    Microsun::Plant plant;
    std::vector<std::string> id;

public:
    Microsun::User get_user(std::string,std::string);
    void get_groups();
    int get(std::string);
    int get(std::string,std::string);
    Php::Value phpget(Php::Parameters &arg);
    Php::Value CheckDb();
    Database() 
        {
            this->get_groups();
        }
    virtual ~Database() {}
    Php::Value phpgetID() 
        { 
        return this->id; 
        }
    Php::Value getStoredCustomers()
        {
            std::vector<Php::Object> tmp;
            int lim=this->stored_customers.size();
            for(int j=0;j<lim;j++)
                tmp.push_back(Php::Object("MicrosunCustomer",&this->stored_customers[j]));
            return tmp;
        }
    Php::Value getStoredProblems()
        {
            std::vector<Php::Object> tmp;
            int lim=this->stored_problems.size();
            for(int j=0;j<lim;j++)
                tmp.push_back(Php::Object("MicrosunProblem",&this->stored_problems[j]));
            return tmp;
        }
    Php::Value getStoredPlants()
        {
            return Php::Object("MicrosunPlant",&this->plant);
        }
        };
};
#endif
