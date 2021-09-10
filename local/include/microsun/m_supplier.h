#include <microsun.h>
#include <phpcpp.h>
#include <string>
#include <my_time.h>

#ifndef SUPPLIER_H
#define SUPPLIER_H

namespace Microsun{
class Supplier : public Php::Base
	{
		public:
			unsigned long int ID;
			std::string Company;
			std::string email;
			std::string IBAN;
			unsigned int Phone;
			std::string Address;
			std::string payment_method;
			float dept;
			Time* last_payment;
			unsigned long int TIN;

			Supplier()
				{
					this->last_payment=new Time();
				}
			~Supplier()
				{}
	};
};

#endif
