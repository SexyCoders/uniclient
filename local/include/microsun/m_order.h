#include <microsun.h>
#include <phpcpp.h>
#include <string>
#include <my_time.h>
#include <m_supplier.h>
#include <m_product.h>

#ifndef ORDER_H
#define ORDER_H

namespace Microsun{
class Order : public Php::Base
	{
		public:
			Microsun::Supplier* supplier;
			Microsun::Product* product;
			int amount;
			Time* order_date;
		Order()
			{
				this->supplier=new Supplier();
				this->product=new Product();
				this->order_date=new Time();
			}
		~Order()
			{}
	};
};

#endif
