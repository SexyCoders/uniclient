#include <microsun.h>
#include <string>
#include <phpcpp.h>

#ifndef COUNTY_H
#define COUNTY_H

namespace Microsun{
class County : public Php::Base
	{
		public:
			unsigned int ID;
			std::string Name;
			std::string Capital;
			double Area;
			double Population;
			float Density;
			std::string Region;
		public:
			County(){};
			//County(unsigned int,std::string,std::string,double,double,float,std::string);
			County operator=(County src)
				{
					this->ID=src.ID;
					this->Name=src.Name;
					this->Capital=src.Capital;
					this->Area=src.Area;
					this->Population=src.Population;
					this->Density=src.Density;
					this->Region=src.Region;
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
			std::string getCapital(void)
				{
				return this->Capital;
				}
			double getArea(void)
				{
				return this->Area;
				}
			double getPopulation(void)
				{
				return this->Population;
				}
			float getDensity(void)
				{
				return this->Density;
				}
			std::string getRegion(void)
				{
				return this->Region;
				}
			Php::Value phpgetID(void)
				{
				return (double) this->ID;
				}
			Php::Value phpgetName(void)
				{
				return this->Name;
				}
			Php::Value phpgetCapital(void)
				{
				return this->Capital;
				}
			Php::Value phpgetArea(void)
				{
				return this->Area;
				}
			Php::Value phpgetPopulation(void)
				{
				return this->Population;
				}
			Php::Value phpgetDensity(void)
				{
				return this->Density;
				}
			Php::Value phpgetRegion(void)
				{
				return this->Region;
				}
	};
};
#endif
