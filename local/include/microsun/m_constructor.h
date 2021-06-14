#include <string>
#include <phpcpp.h>

#ifndef CONSTRUCTOR_H
#define CONSTRUCTOR_H

namespace Microsun{
class Constructor : public Php::Base
	{
		public:
			unsigned int ID;
			std::string Company;
		public:
			Constructor()
				{};
			Constructor(unsigned short int t,std::string tt)
				{
					this->ID=t;
					this->Company=tt;
				};
			Constructor operator=(Constructor src)
				{
					this->ID=src.ID;
					this->Company=src.Company;
				return *this;
				}
			unsigned int getID(void)
				{
				return this->ID;
				}
			std::string getCompany(void)
				{
				return this->Company;
				}
			Php::Value phpgetID(void)
				{
				return (double) this->ID;
				}
			Php::Value phpgetCompany(void)
				{
				return this->Company;
				}
	};
};
#endif
