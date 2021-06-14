#include <microsun.h>
#include <string>
#include <phpcpp.h>
#include <sqlite3.h>
#include <vector>
#include <customer.h>

#ifndef USER_H
#define USER_H

namespace Microsun{
class User : public Php::Base
	{
		private:
			std::string username;
			std::string passwd;
			std::string email;
			std::string group="customers";
			std::vector<std::string> user_groups;
		public:
				std::string DatabasePath="/var/lib/uniclient/MICROSUN_DATABASE";
		public:
			User();
		public:
			User operator=(User src)
				{
					this->username=src.username;
					this->passwd=src.passwd;
					this->email=src.email;
					this->group=src.group;
				return *this;
				}

			Php::Value phpgetusername();
			Php::Value phpgetpasswd();
			Php::Value phpgetemail();
			Php::Value phpgetgroup();
			Php::Value phpgetAuthKey();

			std::string getusername();
			std::string getpasswd();
			std::string getemail();
			std::string getgroup();

			void phpsetusername(Php::Parameters);
			void phpsetpasswd(Php::Parameters);
			void phpsetemail(Php::Parameters);
			void phpsetgroup(Php::Parameters);

			void setusername(std::string);
			void setpasswd(std::string);
			void setemail(std::string);
			void setgroup(std::string);
	};
};
#endif
