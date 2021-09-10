#include <microsun.h>
#include <phpcpp.h>
#include <string>
#include <my_time.h>
#include <m_user.h>
#include <m_supplier.h>

#ifndef PAYMENT_H
#define PAYMENT_H

namespace Microsun{
class Payment : public Php::Base
	{
		public:
			unsigned long int ID;
			float price;
			Microsun::Supplier* supplier;
			Time* date;
			Micorsun::User* authorized_by;

			Payment()
				{
					this->supplier=new Supplier();
					this->date=new Time();
					this->authorized_by=new User();
				}
	};
};

#endif
