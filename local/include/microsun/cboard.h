#include <string>
#include <phpcpp.h>

#ifndef CBOARD_H
#define CBOARD_H

namespace UniClient::Microsun{
class CBoard : public Php::Base
	{
		public:
			unsigned int ID;
			std::string Model;
		public:
			CBoard(unsigned int,std::string);
			CBoard()
				{
				}

			CBoard operator=(CBoard src)
				{
					this->ID=src.ID;
					this->Model=src.Model;
				return *this;
				}

			unsigned int getID(void)
				{
				return this->ID;
				}
			std::string getModel(void)
				{
				return this->Model;
				}
				
			//php access functions
			Php::Value phpgetID(void)
				{
				return (double) this->ID;
				}
			Php::Value phpgetModel(void)
				{
				return this->Model;
				}
	};
};

#endif
