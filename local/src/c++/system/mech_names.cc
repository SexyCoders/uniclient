#include <database.h>

Php::Value UniClient::Database::getGroupMembers(std::string group)
    {
        std::vector<std::string> to_return;
        for(int j=0;j<this->groups.size();j++)
            {
                if(this->groups[j].name==group)
                    {
                    for(int i=0;i<this->groups[j].users.size();i++)
                        {
                            to_return.push_back(this->groups[j].users[i].username);
                        };
                    }
            };
        return to_return;
    }
 
