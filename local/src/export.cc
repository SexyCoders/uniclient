#include <phpcpp.h>
#include <uniclient.h>
#include <php_uniclient.h>

#include <m_customer.h>
#include <m_database.h>
#include <m_user.h>


extern "C" 
    {
PHPCPP_EXPORT void *get_module() 
    {
        static Php::Extension myExtension("PhpUniClient", "1.0");
        Php::Class<UniClient::PhpUniClient> PhpUniClient("UniClientObject");
        //database.method<&Database::CheckDb>("CheckDb", {});
        PhpUniClient.method<&UniClient::PhpUniClient::GET>("GET",{Php::ByVal("parameter",Php::Type::String,true)});
        myExtension.add(std::move(PhpUniClient));
        Php::Class<Microsun::Database> database("MicrosunDatabase");
            database.method<&Microsun::Database::phpgetID>("getID", {});
            database.method<&Microsun::Database::getStoredCustomers>("getStoredCustomers", {});
            database.method<&Microsun::Database::getStoredPlants>("getStoredPlants", {});
            database.method<&Microsun::Database::phpget>("get",{Php::ByVal("parameter",Php::Type::String,true)});
            myExtension.add(std::move(database));

        Php::Class<Microsun::Customer> customer("MicrosunCustomer");
            customer.method<&Microsun::Customer::setID>("setID",{Php::ByVal("ID",Php::Type::Numeric,true)});
            customer.method<&Microsun::Customer::setCompany>("setCompany",{Php::ByVal("Company",Php::Type::String,true)});
            customer.method<&Microsun::Customer::setFirstName>("setFirstName",{Php::ByVal("FirstName",Php::Type::String,true)});
            customer.method<&Microsun::Customer::setLastName>("setLastName",{Php::ByVal("LastName",Php::Type::String,true)});
            customer.method<&Microsun::Customer::setPhoneNumber>("setPhoneNumber",{Php::ByVal("PhoneNumber",Php::Type::Numeric,true)});
            customer.method<&Microsun::Customer::setemail>("setemail",{Php::ByVal("email",Php::Type::String,true)});
            customer.method<&Microsun::Customer::setAddress>("setAddress",{Php::ByVal("Address",Php::Type::String,true)});
            customer.method<&Microsun::Customer::setzip>("setzip",{Php::ByVal("zip",Php::Type::Numeric,true)});
            customer.method<&Microsun::Customer::setTIN>("setTIN",{Php::ByVal("TIN ",Php::Type::Numeric,true)});
            customer.method<&Microsun::Customer::setNotes>("setNotes",{Php::ByVal("Notes",Php::Type::String,true)});
            customer.method<&Microsun::Customer::phpgetID>("getID",{});
            customer.method<&Microsun::Customer::phpgetCompany>("getCompany",{});
            customer.method<&Microsun::Customer::phpgetFirstName>("getFirstName",{});
            customer.method<&Microsun::Customer::phpgetLastName>("getLastName",{});
            customer.method<&Microsun::Customer::phpgetPhoneNumber>("getPhoneNumber",{});
            customer.method<&Microsun::Customer::phpgetemail>("getemail",{});
            customer.method<&Microsun::Customer::phpgetAddress>("getAddress",{});
            customer.method<&Microsun::Customer::phpgetzip>("getzip",{});
            customer.method<&Microsun::Customer::phpgetTIN>("getTIN",{});
            customer.method<&Microsun::Customer::phpgetNotes>("getNotes",{});
            myExtension.add(std::move(customer));

            Php::Class<Microsun::County> county("MicrosunCounty");
                county.method<&Microsun::County::phpgetID> ("getID",{});
                county.method<&Microsun::County::phpgetName> ("getName",{});
                county.method<&Microsun::County::phpgetCapital> ("getCapital",{});
                county.method<&Microsun::County::phpgetArea> ("getArea",{});
                county.method<&Microsun::County::phpgetPopulation> ("getPopulation",{});
                county.method<&Microsun::County::phpgetDensity> ("getDensity",{});
                county.method<&Microsun::County::phpgetRegion> ("getRegion",{});
                myExtension.add(std::move(county));
            Php::Class<Microsun::Panel> panel("MicrosunPanel");
                panel.method<&Microsun::Panel::phpgetID> ("getID",{});
                panel.method<&Microsun::Panel::phpgetMake> ("getMake",{});
                panel.method<&Microsun::Panel::phpgetModel> ("getModel",{});
                myExtension.add(std::move(panel));
            Php::Class<Microsun::Mounter> mounter("MicrosunMounter");
                mounter.method<&Microsun::Mounter::phpgetID> ("getID",{});
                mounter.method<&Microsun::Mounter::phpgetName> ("getName",{});
                myExtension.add(std::move(mounter));
            Php::Class<Microsun::Inverter> inverter("MicrosunInverter");
                inverter.method<&Microsun::Inverter::phpgetID> ("getID",{});
                inverter.method<&Microsun::Inverter::phpgetModel> ("getModel",{});
                inverter.method<&Microsun::Inverter::phpgetType> ("getType",{});
                myExtension.add(std::move(inverter));
        Php::Class<Microsun::CBoard> cboard("MicrosunCBoard");
            cboard.method<&Microsun::CBoard::phpgetID> ("getID",{});
            cboard.method<&Microsun::CBoard::phpgetModel> ("getName",{});
            myExtension.add(std::move(cboard));
        Php::Class<Microsun::Constructor> constructor("MicrosunConstructor");
            constructor.method<&Microsun::Constructor::phpgetID> ("getID",{});
            constructor.method<&Microsun::Constructor::phpgetCompany> ("getCompany",{});
            myExtension.add(std::move(constructor));
        Php::Class<Microsun::Plant> plant("MicrosunPlant");
            plant.method<&Microsun::Plant::getID> ("getID",{});
            plant.method<&Microsun::Plant::getPower> ("getPower",{});
            plant.method<&Microsun::Plant::getOwner> ("getOwner",{});
            plant.method<&Microsun::Plant::getCounty> ("getCounty",{});
            plant.method<&Microsun::Plant::getBorough> ("getBorough",{});
            plant.method<&Microsun::Plant::getLocation> ("getLocation",{});
            plant.method<&Microsun::Plant::getArea> ("getArea",{});
            plant.method<&Microsun::Plant::getNPanels> ("getNPanels",{});
            plant.method<&Microsun::Plant::getPanel> ("getPanel",{});
            plant.method<&Microsun::Plant::getStrings> ("getStrings",{});
            plant.method<&Microsun::Plant::getMounting> ("getMounting",{});
            plant.method<&Microsun::Plant::getInverter> ("getInverter",{});
            plant.method<&Microsun::Plant::getCBoard> ("getCBoard",{});
            plant.method<&Microsun::Plant::getConstructor> ("getConstructor",{});
            plant.method<&Microsun::Plant::getConnectionNumber> ("getConnectionNumber",{});
            plant.method<&Microsun::Plant::getConnectionDate> ("getConnectionDate",{});
            plant.method<&Microsun::Plant::getTrackerBegin> ("getTrackerBegin",{});
            plant.method<&Microsun::Plant::getSellPrice> ("getSellPrice",{});
            myExtension.add(std::move(plant));
        Php::Class<Microsun::User>user("MicrosunUser");
            //user.method<&Microsun::User::authenticate>("authenticate",{});
            //user.method<&Microsun::User::init>("init",{Php::ByVal("parameter",Php::Type::String,true)});
            //user.method<&Microsun::User::phpgetAuthKey>("getAuthKey",{});
            //user.method<&Microsun::User::phpgetusername>("getUsername",{});
            myExtension.add(std::move(user));

            return myExtension;
            }
    }
