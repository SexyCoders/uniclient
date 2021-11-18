#include <database.h>

Php::Value UniClient::Database::getGroupMembers(Php::Parameters &group)
    {
        std::vector<std::string> to_return;
        for(unsigned long int j=0;j<this->groups.size();j++)
            {
                if(this->groups[j].name==group[0].stringValue())
                    {
                    for(unsigned long int i=0;i<this->groups[j].users.size();i++)
                        {
                            to_return.push_back(this->groups[j].users[i].username);
                        };
                    }
            };
        return to_return;
    }
 
