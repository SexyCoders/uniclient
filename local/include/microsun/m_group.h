#include <microsun.h>
#include <m_user.h>

#ifndef MICROSUN_GROUP
#define MICROSUN_GROUP

namespace Microsun{
class Group{
	public:
		std::string name;
		std::vector<Microsun::User> users;
		Group()
			{}
		~Group()
			{}
};
};

#endif
