#include <phpcpp.h>
#include <customer.h>
#include <database.h>

extern "C" {
    PHPCPP_EXPORT void *get_module() {
        static Php::Extension myExtension("microsun_uniclient", "0.1");
        Php::Class<Microsun::Database> database("MicrosunDatabase");
            database.method<&Microsun::Database::getDBPath>("getDBPath", {});
            database.method<&Microsun::Database::getBUFFERPath>("getBBUFFERPath", {});
            database.method<&Microsun::Database::getbufferPath>("getbufferPath", {});
            database.method<&Microsun::Database::getDataPath>("getDataPath", {});
            database.method<&Microsun::Database::getStringBuffer>("getStringBuffer", {});
            database.method<&Microsun::Database::getStoredCustomers>("getStoredCustomers", {});
            database.method<&Microsun::Database::getStoredProblems>("getStoredProblems", {});
            database.method<&Microsun::Database::getStoredPlants>("getStoredPlants", {});
            database.method<&Microsun::Database::phpgetStoredInt>("getStoredInt", {});
            database.method<&Microsun::Database::getID>("getID", {});
            database.method<&Microsun::Database::CheckDb>("CheckDb", {});
            database.method<&Microsun::Database::phpget>("get",{Php::ByVal("parameter",Php::Type::String,true)});
            database.method<&Microsun::Database::phpput>("put",{Php::ByVal("parameter",Php::Type::String,true)});
            database.method<&Microsun::Database::del>("del",{Php::ByVal("parameter",Php::Type::String,true)});
            database.method<&Microsun::Database::phpgetUserNames>("getUserNames", {});
            database.method<&Microsun::Database::phpResolveError>("ResolveError", {});
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
                myExtensionNewNewNew.add(std::move(panel));
            Php::Class<MicrosunMounter> mounter("MicrosunMounter");
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
            cboard.method<&Microsun::CBoard::phpgetName> ("getName",{});
            myExtension.add(std::move(cboard));
        Php::Class<Microsun::Constructor> constructor("MicrosunConstructor");
            constructor.method<&Microsun::Constructor::phpgetID> ("getID",{});
            constructor.method<&Microsun::Constructor::phpgetCompany> ("getCompany",{});
            myExtension.add(std::move(constructor));
        return myExtensionNew;
    }
}

