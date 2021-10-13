#include <etc.h>
#include <string>
#include <phpcpp.h>
#include <my_time.h>


namespace UniClient{
		class Database;
	};

#ifndef PROBLEM_H
#define PROBLEM_H

namespace UniClient::Microsun{
class Problem : public Php::Base
	{
		public:
			unsigned long int reg_id;
			UniClient::Microsun::Plant* plant;
			std::string Type;
			int Pos;
			std::string ErrorCode;
			Time* ReportedDate;
			UniClient::etc::User* ReportedUser;
			std::string ErrorNotes;
			UniClient::etc::User* AssignedMech;
			Time* ResolvedDate;
			std::string MechNotes;

			//system
			UniClient::Database* database;

			Problem()
				{
					this->plant=new Plant();
					this->ReportedDate=new Time();
					this->ReportedUser=new UniClient::etc::User();
					this->AssignedMech=new UniClient::etc::User();
					this->ResolvedDate=new Time();
				}
			Problem(UniClient::Database* db)
				{
					this->plant=new UniClient::Microsun::Plant();
					this->ReportedDate=new Time();
					this->ReportedUser=new UniClient::etc::User();
					this->AssignedMech=new UniClient::etc::User();
					this->ResolvedDate=new Time();
					this->database=db;
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
			Php::Value getRegId()
				{
				return (int)this->reg_id;
				}
			Php::Value getPlantID()
				{
				return this->plant->ID;
				};
			Php::Value getType()
				{
				return this->Type;
				}
			Php::Value getPos()
				{
				return this->Pos;
				}
			Php::Value getErrorCode()
				{
				return this->ErrorCode;
				}
			Php::Value getReportedDate()
				{
				return this->ReportedDate->toString();
				}
			Php::Value getReportedUser()
				{
				return this->ReportedUser->username;
				}
			Php::Value getErrorNotes()
				{
				return this->ErrorNotes;
				}
			Php::Value getAssignedMech()
				{
				return this->AssignedMech->username;
				}
			Php::Value getResolvedDate()
				{
				return this->ResolvedDate->toString();
				}
			Php::Value getMechNotes()
				{
				return this->MechNotes;
				}
	};
};

#endif
