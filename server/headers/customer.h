#include <string>
#include <uniclient.h>
#include <my_time.h>

#ifndef CUSTOMER_H
#define CUSTOMER_H

namespace UniClient
{

class Customer
	{
		private:
			unsigned int ID;
			std::string Company;
			std::string FirstName;
			std::string LastName;
			unsigned long int PhoneNumber;
			std::string email;
			std::string Address;
			int zip;
			std::string Notes;
			int TIN;
			Time added;
			Time last_interaction;
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
					this->added=src.added;
					this->last_interaction=src.last_interaction;
				return *this;
				}

			void setID(unsigned int id)
				{
					this->ID=id;
				}
			void setCompany(std::string company)
				{
					this->Company=company;
				}
			void setFirstName(std::string name)
				{
					this->FirstName=name;
				}
			void setLastName(std::string lname)
				{
					this->LastName=lname;
				}
			void setPhoneNumber(unsigned long int phone)
				{
					this->PhoneNumber=phone;
				}
			void setemail(std::string email)
				{
					this->email=email;
				}
			void setAddress(std::string address)
				{
					this->Address=address;
				}
			void setzip(int zip)
				{
					this->zip=zip;
				}
			void setNotes(std::string notes)
				{
					this->Notes=notes;
				}
			void setTIN(int tin)
				{
					this->TIN=tin;
				}
			void setAdded(Time time)
				{
					this->added=time;
				}
			void setLastInteraction(Time time)
				{
					this->last_interaction=time;
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
			int getzip()
				{
					return this->zip;
				}
			std::string getNotes()
				{
					return this->Notes;
				}
			int getTIN()
				{
					return this->TIN;
				}
			Time getAdded(void)
				{
					return this->added;
				}
			Time getLastInteraction(void)
				{
					return this->last_interaction;
				}

	};

}

#endif
