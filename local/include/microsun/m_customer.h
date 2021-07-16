#include <phpcpp.h>
#include <string>

#ifndef CUSTOMER_H
#define CUSTOMER_H

namespace Microsun{
class Customer : public Php::Base
	{
		public:
			unsigned int ID;
			std::string Company;
			std::string FirstName;
			std::string LastName;
			unsigned long int PhoneNumber;
			std::string email;
			std::string Address;
			unsigned long int zip;
			std::string Notes;
			long unsigned int TIN;
		public:
			Customer operator=(Customer src)
				{
					this->ID=src.ID;
					this->Company=src.Company;
					this->FirstName=src.FirstName;
					this->LastName=src.LastName;
					this->PhoneNumber=src.PhoneNumber;
					this->email=src.email;
					this->Address=src.Address;
					this->zip=src.zip;
					this->TIN=src.TIN;
					this->Notes=src.Notes;
				return *this;
				}
            Customer()
                {
                }
            Customer(unsigned int ID,std::string Company,std::string FirstName,std::string LastName,
                    unsigned long int PhoneNumber,std::string email,std::string Address,
                    unsigned long int zip,std::string Notes,long unsigned int TIN)
                {
                    this->ID=ID;
                    this->Company=Company;
                    this->FirstName=FirstName;
                    this->LastName=LastName;
                    this->PhoneNumber=PhoneNumber;
                    this->email=email;
                    this->Address=Address;
                    this->zip=zip;
                    this->Notes=Notes;
                    this->TIN=TIN;
                }
            Php::Value phpgetID()
                {
                return (double) this->ID;
                }

            Php::Value phpgetCompany()
                {
                    return this->Company;
                }

            Php::Value phpgetFirstName()
                {
                    return this->FirstName;
                }

            Php::Value phpgetLastName()
                {
                    return this->LastName;
                }

            Php::Value phpgetPhoneNumber()
                {
                    return (double) this->PhoneNumber;
                }

            Php::Value phpgetemail()
                {
                    return this->email;
                }

            Php::Value phpgetAddress()
                {
                    return this->Address;
                }

            Php::Value phpgetzip()
                {
                    return (double) this->zip;
                }

            Php::Value phpgetTIN()
                {
                    return (double) this->TIN;
                }

            Php::Value phpgetNotes()
                {
                    return this->Notes;
                }

                };
};
#endif
