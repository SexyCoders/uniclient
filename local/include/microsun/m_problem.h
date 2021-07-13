#include <string>
#include <phpcpp.h>
#include <my_time.h>
#include <m_plant.h>
#include <m_user.h>

#ifndef PROBLEM_H
#define PROBLEM_H

namespace Microsun{
class Problem : public Php::Base
	{
		public:
			unsigned long int reg_id;
			Microsun::Plant plant;
			std::string Type;
			int Pos;
			std::string ErrorCode;
			Time ReportedDate;
			Microsun::User ReportedUser;
			std::string ErrorNotes;
			Microsun::User AssignedMech;
			Time ResolvedDate;
			std::string MechNotes;

			Problem()
				{
				}
	};
};

#endif
