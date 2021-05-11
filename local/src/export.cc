#include <phpcpp.h>
#include <uniclient.h>
#include <php_uniclient.h>


extern "C" 
    {
        PHPCPP_EXPORT void *get_module() 
            {
                static Php::Extension myExtensionNew("PhpUniClient", "1.0");
                Php::Class<UniClient::PhpUniClient> PhpUniClient("UniClientObject");
                //database.method<&Database::CheckDb>("CheckDb", {});
                PhpUniClient.method<&UniClient::PhpUniClient::GET>("GET",{Php::ByVal("parameter",Php::Type::String,true)});
                myExtensionNew.add(std::move(PhpUniClient));
            return myExtensionNew;
            }
    }
