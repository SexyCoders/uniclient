#include <microsun.h>
#include <m_user.h>
#include <phpcpp.h>

#ifndef MICROSUN_GROUP
#define MICROSUN_GROUP

namespace Microsun{
class Group{
	public:
		std::string name;
		std::vector<Microsun::User> users;
		//Microsun::User* users;
		//int size;
		Group()
			{}
		~Group()
			{}
		Group operator=(Group src)
			{
				this->name=src.name;
				this->users=src.users;
			}
		//int add(Microsun::User T)
			//{
                //Microsun::User* temp=this->users;
                //this->users=new Microsun::User[++this->size];
                //std::copy(temp,&temp[this->size-1],this->users);
                //this->users[this->size-1]=T;
                //(this->size>1)?delete[] temp:(void)0;
			//return this->size;
			//}
};
};

#endif