#include <microsun.h>
#include <m_database.h>
#include <sqlite3.h>
#include <string>

Php::Value Microsun::Database::getMechNames()
    {
        std::vector<std::string> to_return;
        for(int j=0;j<this->groups.size();j++)
            {
                if(this->groups[j].name=="mech")
                    {
                    for(int i=0;i<this->groups[j].users.size();i++)
                        {
                            to_return.push_back(this->groups[j].users[i].username);
                        };
                    }
            };
        return to_return;
    }
