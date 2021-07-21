#include <microsun.h>
#include <m_database.h>
#include <sqlite3.h>

Php::Value Microsun::Database::storePlant(Php::Parameters &arg)
    {
        Microsun::Plant* plant= new Microsun::Plant();

    return arg[0][1];
    }
