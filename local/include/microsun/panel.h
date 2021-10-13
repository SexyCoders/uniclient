#include <string>
#include <phpcpp.h>

#ifndef PANEL_H
#define PANEL_H

namespace UniClient::Microsun{
class Panel : public Php::Base 
	{
		public:
			unsigned int ID;
			std::string Make;
			std::string Model;
		public:
			Panel(){};
			Panel operator=(Panel src)
				{
					this->ID=src.ID;
					this->Make=src.Make;
					this->Model=src.Model;
				return *this;
				}
			unsigned int getID(void)
				{
				return this->ID;
				}
			std::string getMake(void)
				{
				return this->Make;
				}
			std::string getModel(void)
				{
				return this->Model;
				}
			Php::Value phpgetID(void)
				{
				return (double) this->ID;
				}
			Php::Value phpgetMake(void)
				{
				return this->Make;
				}
			Php::Value phpgetModel(void)
				{
				return this->Model;
				}
	};
};
#endif
