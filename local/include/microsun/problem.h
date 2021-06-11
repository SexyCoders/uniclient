#include <string>
#include <phpcpp.h>
#include <my_time.h>
#include <plant.h>
#include <user.h>

#ifndef PROBLEM_H
#define PROBLEM_H

namespace Microsun{
class Problem : public Php::Base
	{
		private:
			unsigned long int reg_id;
			Microsun::Plant* plant;
			std::string Type;
			int Pos;
			std::string ErrorCode;
			Time* ReportedDate;
			Microsun::User* ReportedUser;
			std::string ErrorNotes;
			Microsun::User* AssignedMech;
			Time* ResolvedDate;
			std::string MechNotes;
		public:
			Problem()
				{
					this->plant=new Microsun::Plant();
					this->ReportedDate=new Time();
					this->ReportedUser=new Microsun::User();
					this->AssignedMech=new Microsun::User();
					this->ResolvedDate=new Time();
				}
			Php::Value phpgetID()
				{
				return (double) this->reg_id;
				}
			Php::Value phpgetPlant()
				{
				return Php::Object("Plant",this->plant);
				}
			Php::Value phpgetType()
				{
					return this->Type;
				}
			Php::Value phpgetPos()
				{
					return this->Pos;
				}
			Php::Value phpgetErrorCode()
				{
				return this->ErrorCode;
				}
			Php::Value phpgetReportedDate()
				{
				return Php::Object("Time",this->ReportedDate);
				}
			Php::Value phpgetReportedUser()
				{
				return Php::Object("User",this->ReportedUser);
				}
			Php::Value phpgetErrorNotes()
				{
				return this->ErrorNotes;
				}
			Php::Value phpgetAssignedMech()
				{
				return Php::Object("User",this->AssignedMech);
				}
			Php::Value phpgetResolvedDate()
				{
				return Php::Object("Time",this->ResolvedDate);
				}
			Php::Value phpgetMechNotes()
				{
				return this->MechNotes;
				}
			void setID(unsigned long int id)
				{
					this->reg_id=id;
				}
			void setPlant(Plant plant)
				{
					*this->plant=plant;
				}
			void setType(std::string type)
				{
					this->Type=type;
				}
			void setPos(int pos)
				{
					this->Pos=pos;
				}
			void setErrorCode(std::string ErrorCode)
				{
					this->ErrorCode=ErrorCode;
				}
			void setReportedDate(Time date)
				{
					*this->ReportedDate=date;
				}
			void setReportedUser(User user)
				{
					*this->ReportedUser=user;
				}
			void setErrorNotes(std::string notes)
				{
					this->ErrorNotes=notes;
				}
			void setAssignedMech(User mech)
				{
					*this->AssignedMech=mech;
				}
			void setResolvedDate(Time date)
				{
					*this->ResolvedDate=date;
				}
			void setMechNotes(std::string notes)
				{
					this->MechNotes=notes;
				}
	};
};

#endif
