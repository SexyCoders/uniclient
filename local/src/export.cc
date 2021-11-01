#include <phpcpp.h>
#include <uniclient.h>
#include <php_uniclient.h>

#include <database.h>
#include <data.h>
#include <etc.h>
#include <microsun.h>


extern "C" 
    {
PHPCPP_EXPORT void *get_module() 
    {
        static Php::Extension myExtension("PhpUniClient", "1.0");
        //Php::Class<UniClient::PhpUniClient> PhpUniClient("UniClientObject");
        //database.method<&Database::CheckDb>("CheckDb", {});
        //PhpUniClient.method<&UniClient::PhpUniClient::GET>("GET",{Php::ByVal("parameter",Php::Type::String,true)});
        //myExtension.add(std::move(PhpUniClient));
        //Php::Class<Microsun::Problem> problem("MicrosunProblem");
            //myExtension.add(std::move(problem));
        Php::Class<UniClient::Database> database("MicrosunDatabase");
//            //database.method<&Microsun::Database::phpgetID>("getID", {});
//            database.method<&Microsun::Database::getCustomers>("getCustomers", {});
//            database.method<&Microsun::Database::getPlants>("getPlants", {});
//            database.method<&Microsun::Database::getPending>("getPending", {});
//            database.method<&Microsun::Database::getStored>("getStored", {});
//            database.method<&Microsun::Database::getMechNames>("getMechNames", {});
            database.method<&UniClient::Database::getPendingCount>("getPendingCount", {});
//            database.method<&Microsun::Database::newError>("newError",{Php::ByVal("parameter",Php::Type::String,true)});
//            database.method<&Microsun::Database::tempError>("tempError",{Php::ByVal("parameter",Php::Type::String,true)});
//            database.method<&Microsun::Database::resolve_error>("ResolveError",{Php::ByVal("parameter",Php::Type::String,true)});
//            database.method<&Microsun::Database::getPlantLog>("getPlantLog",{Php::ByVal("parameter",Php::Type::String,true)});
//            //database.method<&Microsun::Database::getStoredCustomers>("getStoredCustomers", {});
//            //database.method<&Microsun::Database::getStoredPlants>("getStoredPlants", {});
//            //database.method<&Microsun::Database::getStoredProblems>("getStoredProblems", {});
//            //database.method<&Microsun::Database::phpget>("get",{Php::ByVal("parameter",Php::Type::String,true)});
            myExtension.add(std::move(database));
// 
        Php::Class<UniClient::data::Customer> customer("MicrosunCustomer");
            customer.method<&UniClient::data::Customer::phpgetID>("getID",{});
            customer.method<&UniClient::data::Customer::phpgetCompany>("getCompany",{});
            customer.method<&UniClient::data::Customer::phpgetFirstName>("getFirstName",{});
            customer.method<&UniClient::data::Customer::phpgetLastName>("getLastName",{});
            customer.method<&UniClient::data::Customer::phpgetPhoneNumber>("getPhoneNumber",{});
            customer.method<&UniClient::data::Customer::phpgetemail>("getemail",{});
            customer.method<&UniClient::data::Customer::phpgetAddress>("getAddress",{});
            customer.method<&UniClient::data::Customer::phpgetzip>("getzip",{});
            customer.method<&UniClient::data::Customer::phpgetTIN>("getTIN",{});
            customer.method<&UniClient::data::Customer::phpgetNotes>("getNotes",{});
            myExtension.add(std::move(customer));
// 
        Php::Class<UniClient::data::County> county("MicrosunCounty");
            county.method<&UniClient::data::County::phpgetID> ("getID",{});
            county.method<&UniClient::data::County::phpgetName> ("getName",{});
            county.method<&UniClient::data::County::phpgetCapital> ("getCapital",{});
            county.method<&UniClient::data::County::phpgetArea> ("getArea",{});
            county.method<&UniClient::data::County::phpgetPopulation> ("getPopulation",{});
            county.method<&UniClient::data::County::phpgetDensity> ("getDensity",{});
            county.method<&UniClient::data::County::phpgetRegion> ("getRegion",{});
            myExtension.add(std::move(county));
        Php::Class<UniClient::Microsun::Panel> panel("MicrosunPanel");
            panel.method<&UniClient::Microsun::Panel::phpgetID> ("getID",{});
            panel.method<&UniClient::Microsun::Panel::phpgetMake> ("getMake",{});
            panel.method<&UniClient::Microsun::Panel::phpgetModel> ("getModel",{});
            myExtension.add(std::move(panel));
        Php::Class<UniClient::Microsun::Mounter> mounter("MicrosunMounter");
            mounter.method<&UniClient::Microsun::Mounter::phpgetID> ("getID",{});
            mounter.method<&UniClient::Microsun::Mounter::phpgetName> ("getName",{});
            myExtension.add(std::move(mounter));
        Php::Class<UniClient::Microsun::Inverter> inverter("MicrosunInverter");
            inverter.method<&UniClient::Microsun::Inverter::phpgetID> ("getID",{});
            inverter.method<&UniClient::Microsun::Inverter::phpgetModel> ("getModel",{});
            inverter.method<&UniClient::Microsun::Inverter::phpgetType> ("getType",{});
            myExtension.add(std::move(inverter));
        Php::Class<UniClient::Microsun::CBoard> cboard("MicrosunCBoard");
            cboard.method<&UniClient::Microsun::CBoard::phpgetID> ("getID",{});
            cboard.method<&UniClient::Microsun::CBoard::phpgetModel> ("getName",{});
            myExtension.add(std::move(cboard));
        Php::Class<UniClient::Microsun::Constructor> constructor("MicrosunConstructor");
            constructor.method<&UniClient::Microsun::Constructor::phpgetID> ("getID",{});
            constructor.method<&UniClient::Microsun::Constructor::phpgetCompany> ("getCompany",{});
            myExtension.add(std::move(constructor));
        Php::Class<UniClient::Microsun::Plant> plant("MicrosunPlant");
            plant.method<&UniClient::Microsun::Plant::getID> ("getID",{});
            plant.method<&UniClient::Microsun::Plant::getPower> ("getPower",{});
            plant.method<&UniClient::Microsun::Plant::getOwner> ("getOwner",{});
            plant.method<&UniClient::Microsun::Plant::getCounty> ("getCounty",{});
            plant.method<&UniClient::Microsun::Plant::getBorough> ("getBorough",{});
            plant.method<&UniClient::Microsun::Plant::getLocation> ("getLocation",{});
            plant.method<&UniClient::Microsun::Plant::getArea> ("getArea",{});
            plant.method<&UniClient::Microsun::Plant::getNPanels> ("getNPanels",{});
            plant.method<&UniClient::Microsun::Plant::getPanel> ("getPanel",{});
            plant.method<&UniClient::Microsun::Plant::getStrings> ("getStrings",{});
            plant.method<&UniClient::Microsun::Plant::getMounting> ("getMounting",{});
            plant.method<&UniClient::Microsun::Plant::getInverter> ("getInverter",{});
            plant.method<&UniClient::Microsun::Plant::getCBoard> ("getCBoard",{});
            plant.method<&UniClient::Microsun::Plant::getConstructor> ("getConstructor",{});
            plant.method<&UniClient::Microsun::Plant::getConnectionNumber> ("getConnectionNumber",{});
            plant.method<&UniClient::Microsun::Plant::getConnectionDate> ("getConnectionDate",{});
            plant.method<&UniClient::Microsun::Plant::getTrackerBegin> ("getTrackerBegin",{});
            plant.method<&UniClient::Microsun::Plant::getSellPrice> ("getSellPrice",{});
            myExtension.add(std::move(plant));
        //Php::Class<Microsun::User>user("MicrosunUser");
            //myExtension.add(std::move(user));
        Php::Class<UniClient::Microsun::Problem>problem("MicrosunProblem");
            problem.method<&UniClient::Microsun::Problem::getRegId> ("reg_id",{});
            problem.method<&UniClient::Microsun::Problem::getPlantID> ("plant_id",{});
            problem.method<&UniClient::Microsun::Problem::getType> ("Type",{});
            problem.method<&UniClient::Microsun::Problem::getPos> ("Pos",{});
            problem.method<&UniClient::Microsun::Problem::getErrorCode> ("ErrorCode",{});
            problem.method<&UniClient::Microsun::Problem::getReportedDate> ("ReportedDate",{});
            problem.method<&UniClient::Microsun::Problem::getReportedUser> ("ReportedUser",{});
            problem.method<&UniClient::Microsun::Problem::getErrorNotes> ("ErrorNotes",{});
            problem.method<&UniClient::Microsun::Problem::getAssignedMech> ("AssignedMech",{});
            problem.method<&UniClient::Microsun::Problem::getResolvedDate> ("ResolvedDate",{});
            problem.method<&UniClient::Microsun::Problem::getMechNotes> ("MechNotes",{});
            myExtension.add(std::move(problem));
// 
            return myExtension;
            }
    }
 
