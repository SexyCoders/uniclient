#include <microsun.h>
#include <m_database.h>
#include <sqlite3.h>

Php::Value Microsun::Database::storePlant(Php::Parameters &arg)
    {
        Microsun::Plant* plant= new Microsun::Plant();
        plant->ID=arg[0].stringValue();
        plant->Power=atof(arg[1]);
        //plant->Owner=this->getCustomerByCompanyName(arg[2]);
        //plant->county=this->getCountyByName(arg[3].stringValue());
        plant->Borough=arg[4].stringValue();
        plant->Location=arg[5].stringValue();
        plant->Area=arg[6];
        plant->NPanels=arg[7];
        //plant->panel=this->getPanelByName(arg[8]);
        plant->Strings=arg[9].stringValue();
        //plant->Mounting=this->getMounterByName(arg[10]);
        //plant->inverter=this->getInverterByModel(arg[11]);
        //plant->constructor=this->getConstructorByCompany(arg[12]);
        plant->ConnectionNumber=atol(arg[13]);
        plant->ConnectionDate->fromString(arg[14].stringValue());
        plant->TrackerBegin->fromString(arg[15].stringValue());
        plant->SellPrice=atof(arg[16]);
    return 123;
    }
