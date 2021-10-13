#include <etc.h>
#include <string>
#include <phpcpp.h>
#include <vector>
#include <my_time.h>

#ifndef USER_H
#define USER_H

namespace UniClient::etc{
class User : public Php::Base
	{
		public:
			unsigned int ID;
			std::string FName;
			std::string LName;
			Time DateOfBirth;
			std::string email;
			unsigned long int PhoneNumber;
			unsigned long int zip;
			std::string Address;
			std::string Notes;
			Time HireDate;
			std::string group;
			std::string username;
		public:
			User(){};
		public:
			User operator=(User src)
				{
					this->ID=src.ID;
					this->FName=src.FName;
					this->LName=src.LName;
					this->DateOfBirth=src.DateOfBirth;
					this->email=src.email;
					this->PhoneNumber=src.PhoneNumber;
					this->zip=src.zip;
					this->Address=src.Address;
					this->Notes=src.Notes;
					this->HireDate=src.HireDate;
					this->group=src.group;
					this->username=src.username;
				return *this;
				}
	};
};
#endif
