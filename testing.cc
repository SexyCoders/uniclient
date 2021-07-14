#include <uniclient/microsun/m_database.h>
#include <iostream>

int main()
	{
		Microsun::Database test;
		test.get("customer_all");
		std::cout<<test.stored_customers[0].getCompany()<<"\n";
	}
