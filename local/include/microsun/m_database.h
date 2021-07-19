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
    Microsun::Group* groups;
    int g_size;

public:
    int get_user(std::string,std::string,Microsun::User*);
    int get_groups();
    Php::Value getCustomers();
    Php::Value getPlants();
    Database() 
        {
            this->get_groups();
        }
    virtual ~Database() 
        {
        }
    //Php::Value getStoredCustomers()
        //{
            //Php::Value tmp;
            //for(int j=0;j<this->stored_customers.size;j++)
                //tmp[j]=Php::Object("MicrosunCustomer",&this->stored_customers.data[j]);
            //tmp[0]="MEGALES";
            //tmp[1]="PAPARIES";
            //return tmp;
        //}
    //Php::Value phpgetID() 
        //{ 
            //Php::Value tmp;
            //for(int j=0;j<this->ID.size;j++)
                //tmp[j]=(this->ID.id[j]);
        //return tmp; 
        //}
    //Php::Value getStoredProblems()
        //{
            //std::vector<Php::Object> tmp;
            //int lim=this->stored_problems.size();
            //for(int j=0;j<lim;j++)
                //tmp.push_back(Php::Object("MicrosunProblem",&this->stored_problems[j]));
            //return tmp;
        //}
    //Php::Value getStoredPlants()
        //{
            //return Php::Object("MicrosunPlant",&this->plant);
        //}
        };
};
#endif
