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
#include <iostream>

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
    //int g_size;

public:
    unsigned long int getLastInsertId();
    int get_user(std::string username,std::string grp,Microsun::User* result);
    void get_groups();
    Php::Value getCustomers();
    Microsun::Customer* getCustomerByCompanyName(std::string name);
    Microsun::Plant* getPlant(std::string ID);
    Php::Value getPlants();
    Php::Value getPendingCount();
    Php::Value getPending();
    Php::Value getStored();
    Php::Value storePlant(Php::Parameters &arg);
    Php::Value tempError(Php::Parameters &arg);
    Php::Value getMechNames();
    Php::Value newError(Php::Parameters &arg);
    unsigned long int store_new_error(Microsun::Problem* error);
    std::string store_error(Microsun::Problem* error,std::string table);
    int delete_error(int ID_TO_DELETE,std::string table);
    Microsun::County* getCountyByName(std::string name);
    Microsun::Panel* getPanelByName(std::string Name);
    Microsun::Mounter* getMounterByName(std::string Name);
    Microsun::Inverter* getInverterByModel(std::string Name);
    Microsun::Constructor* getConstructorByCompany(std::string Name);
    Database() 
        {
            this->get_groups();
        }
    virtual ~Database() 
        {
        }
        };
};
#endif
