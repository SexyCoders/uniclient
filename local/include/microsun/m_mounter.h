#include <string>
#include <phpcpp.h>

#ifndef MOUNTER_H
#define MOUNTER_H

namespace Microsun{
class Mounter : public Php::Base
	{
		public:
			unsigned int ID;
			std::string Name;
		public:
			Mounter(){};
			Mounter operator=(Mounter src)
				{
					this->ID=src.ID;
					this->Name=src.Name;
				return *this;
				}
			unsigned int getID(void)
				{
				return this->ID;
				}
			std::string getName(void)
				{
				return this->Name;
				}
			Php::Value phpgetID(void)
				{
				return (double) this->ID;
				}
			Php::Value phpgetName(void)
				{
				return this->Name;
				}
	};
};
#endif
