#include <string>
#include <phpcpp.h>

#ifndef INVERTER_H
#define INVERTER_H

namespace UniClient::Microsun{
class Inverter : public Php::Base
	{
		public:
			unsigned int ID;
			std::string Model;
			std::string Type;
		public:
			Inverter(){};
			Inverter operator=(Inverter src)
				{
					this->ID=src.ID;
					this->Model=src.Model;
					this->Type=src.Type;
				return *this;
				}
			unsigned int getID(void)
				{
				return this->ID;
				}
			std::string getModel(void)
				{
				return this->Model;
				}
			std::string getType(void)
				{
				return this->Type;
				}
			Php::Value phpgetID(void)
				{
				return (double) this->ID;
				}
			Php::Value phpgetModel(void)
				{
				return this->Model;
				}
			Php::Value phpgetType(void)
				{
				return this->Type;
				}
	};
};
#endif
