#include <phpcpp.h>
#include <string>

#ifndef CUSTOMER_H
#define CUSTOMER_H

namespace Microsun{
class Customer : public Php::Base
	{
		private:
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

            Php::Value setID(Php::Parameters &ID)
                {
                    this->ID=(int) ID[0];
                return 0;
                }

            Php::Value setCompany(Php::Parameters &Company)
                {
                    this->Company=Company[0].stringValue();
                return 0;
                }

            Php::Value setFirstName(Php::Parameters &FName)
                {
                    this->FirstName=FName[0].stringValue();
                return 0;
                }

            Php::Value setLastName(Php::Parameters &LastName)
                {
                    this->LastName=LastName[0].stringValue();
                return 0;
                }

            Php::Value setPhoneNumber(Php::Parameters &Phone)
                {
                    this->PhoneNumber=(int) Phone[0];
                return 0;
                }

            Php::Value setemail(Php::Parameters &email)
                {
                    this->email=email[0].stringValue();
                return 0;
                }

            Php::Value setAddress(Php::Parameters &Address)
                {
                    this->Address=Address[0].stringValue();
                return 0;
                }

            Php::Value setzip(Php::Parameters &zip)
                {
                    this->zip=(int) zip[0];
                return 0;
                }

            Php::Value setTIN(Php::Parameters &tin)
                {
                    this->TIN=(int) tin[0];
                return 0;
                }

            Php::Value setNotes(Php::Parameters &Notes)
                {
                    this->Notes=Notes[0].stringValue();
                return 0;
                }

            void csetID(unsigned int ID)
                {
                    this->ID=ID;
                }

            void csetCompany(std::string Company)
                {
                    this->Company=Company;
                }

            void csetFirstName(std::string FName)
                {
                    this->FirstName=FName;
                }

            void csetLastName(std::string LastName)
                {
                    this->LastName=LastName;
                }

            void csetPhoneNumber(unsigned long int Phone)
                {
                    this->PhoneNumber=Phone;
                }

            void csetemail(std::string email)
                {
                    this->email=email;
                }

            void csetAddress(std::string Address)
                {
                    this->Address=Address;
                }

            void csetzip(unsigned long zip)
                {
                    this->zip=zip;
                }

            void csetTIN(unsigned long int tin)
                {
                    this->TIN=tin;
                }

            void csetNotes(std::string Notes)
                {
                    this->Notes=Notes;
                }

            unsigned int getID()
                {
                return this->ID;
                }

            std::string getCompany()
                {
                    return this->Company;
                }

            std::string getFirstName()
                {
                    return this->FirstName;
                }

            std::string getLastName()
                {
                    return this->LastName;
                }

            unsigned long int getPhoneNumber()
                {
                    return this->PhoneNumber;
                }

            std::string getemail()
                {
                    return this->email;
                }

            std::string getAddress()
                {
                    return this->Address;
                }

            unsigned long int getzip()
                {
                    return this->zip;
                }

            unsigned long int getTIN()
                {
                    return this->TIN;
                }

            std::string getNotes()
                {
                    return this->Notes;
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
