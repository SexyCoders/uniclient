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
			Problem operator=(Problem src)
				{
					this->reg_id=src.reg_id;
					this->plant=src.plant;
					this->Type=src.Type;
					this->Pos=src.Pos;
					this->ErrorCode=src.ErrorCode;
					this->ReportedDate=src.ReportedDate;
					this->ReportedUser=src.ReportedUser;
					this->ErrorNotes=src.ErrorNotes;
					this->AssignedMech=src.AssignedMech;
					this->ResolvedDate=src.ResolvedDate;
					this->MechNotes=src.MechNotes;
				return *this;
				}
	};
};

#endif
