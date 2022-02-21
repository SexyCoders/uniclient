#include <uniclient.h>
#include <phpcpp.h>

#ifndef PHP_UNICLIENT_H
#define PHP_UNICLIENT_H

namespace  UniClient
{
	class PhpUniClient : public Php::Base
		{
			public:
			PhpUniClient(){};
			~PhpUniClient(){};
			Php::Value GET(Php::Parameters &arg);
		};
}

#endif
