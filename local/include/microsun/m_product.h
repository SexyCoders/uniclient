#include <microsun.h>
#include <phpcpp.h>
#include <string>
#include <my_time.h>

#ifndef PRODUCT_H
#define PRODUCT_H

namespace Microsun{
class Product : public Php::Base
	{
		public:
			unsigned long int ID;
			std::string Name;
			std::string Make;
			std::string Model;
			Time* Added;
			int ModelYear;

			Product()
				{
					this->Added=new Time();
				}
			~Product()
				{}
	};
};

#endif
