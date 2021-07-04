#include <phpcpp.h>
#include <string>
#include <my_time.h>
#include <m_customer.h>
#include <m_county.h>
#include <m_constructor.h>
#include <m_panel.h>
#include <m_mounter.h>
#include <m_cboard.h>
#include <m_inverter.h>


#ifndef PLANT_H
#define PLANT_H
namespace Microsun{
class Plant : public Php::Base
	{
		private:
		std::string ID;
		float Power;
		Customer* Owner;
		County* county;
		std::string Borough;
		std::string Location;
		double Area;
		long int NPanels;
		Panel* panel;
		std::string Strings;
		Mounter*  Mounting;
		Inverter* inverter;
		CBoard* cboard;
		Constructor* constructor;
		unsigned long int ConnectionNumber;
		Time* ConnectionDate;
		Time* TrackerBegin;
		float SellPrice;
		public:
		Plant()
				{
						this->Owner=new Microsun::Customer();
						this->county=new Microsun::County();
						this->panel=new Microsun::Panel();
						this->Mounting=new Microsun::Mounter();
						this->inverter=new Microsun::Inverter();
						this->cboard=new Microsun::CBoard();
						this->constructor=new Microsun::Constructor();
						this->ConnectionDate=new Time();
						this->TrackerBegin=new Time();

				}

			Plant(std::string ID,float Power,Customer Owner,County county,
					std::string Borough,std::string Location,double Area,long int NPanels,
					Panel panel,std::string Strings,Mounter mounting,Inverter inverter,CBoard cboard,
					Constructor constructor,unsigned long int ConnectionNumber,Time ConnectionDate,Time TrackerBegin,float SellPrice)
				{
					this->ID=ID;
					this->Power=Power;
					this->Owner=new Microsun::Customer();
					*this->Owner=Owner;
					this->county=new Microsun::County();
					*this->county=county;
					this->Borough=Borough;
					this->Location=Location;
					this->Area=Area;
					this->NPanels=NPanels;
					this->panel=new Microsun::Panel();
					*this->panel=panel;
					this->Strings=Strings;
					this->Mounting=new Microsun::Mounter();
					*this->Mounting=mounting;
					this->inverter=new Microsun::Inverter();
					*this->inverter=inverter;
					this->cboard=new Microsun::CBoard();
					*this->cboard=cboard;
					this->constructor=new Microsun::Constructor();
					*this->constructor=constructor;
					this->ConnectionNumber=ConnectionNumber;
					*this->ConnectionDate=ConnectionDate;
					*this->TrackerBegin=TrackerBegin;
					this->SellPrice=SellPrice;
				}
		public:
			void setID(std::string ID)
				{
						this->ID=ID;
				}
			Php::Value getID(void)
				{
				return this->ID;
				}
			Php::Value getPower(void)
				{
				return this->Power;
				}
			Php::Value getOwner(void)
				{
				return Php::Object("MicrosunCustomer",this->Owner);
				}
			Php::Value getCounty(void)
				{
				return Php::Object("MicrosunCounty",this->county);
				}
			Php::Value getBorough(void)
				{
				return this->Borough;
				}
			Php::Value getLocation(void)
				{
				return this->Location;
				}
			Php::Value getArea(void)
				{
				return this->Area;
				}
			Php::Value getNPanels(void)
				{
				return (double) this->NPanels;
				}
			Php::Value getPanel(void)
				{
				return Php::Object("MicrosunPanel",this->panel);
				}
			Php::Value getStrings(void)
				{
				return this->Strings;
				}
			Php::Value getMounting(void)
				{
				return Php::Object("MicrosunMounter",this->Mounting);
				}
			Php::Value getInverter(void)
				{
				return Php::Object("MicrosunInverter",this->inverter);
				}
			Php::Value getCBoard(void)
				{
				return Php::Object("MicrosunCBoard",this->cboard);
				}
			Php::Value getConstructor(void)
				{
				return Php::Object("MicrosunConstructor",this->constructor);
				}
			Php::Value getConnectionNumber(void)
				{
				return (double) this->ConnectionNumber;
				}
			Php::Value getConnectionDate(void)
				{
				return this->ConnectionDate->toString();
				}
			Php::Value getTrackerBegin(void)
				{
				return this->TrackerBegin->toString();
				}
			Php::Value getSellPrice(void)
				{
				return (double) this->SellPrice;
				}

		
			void setPower(float Power)
				{
						this->Power=Power;
				}
			void setOwner(Customer owner)
				{
						*this->Owner=owner;
				}
			void setCounty(County county)
				{
						*this->county=county;
				}
			void setBorough(std::string Borough)
				{
						this->Borough=Borough;
				}
			void setLocation(std::string Location)
				{
						this->Location=Location;
				}
			void setArea(double Area)
				{
						this->Area=Area;
				}
			void setNPanels(long int NPanels)
				{
						this->NPanels=NPanels;
				}
			void setPanel(Panel panel)
				{
						*this->panel=panel;
				}
			void setStrings(std::string Strings)
				{
						this->Strings=Strings;
				}
			void setMounting(Mounter mounting)
				{
						*this->Mounting=mounting;
				}
			void setInverter(Inverter inverter)
				{
						*this->inverter=inverter;
				}
			void setCBoard(CBoard cboard)
				{
						*this->cboard=cboard;
				}
			void setConstructor(Constructor constructor)
				{
						*this->constructor=constructor;
				}
			void setConnectionNumber(unsigned long int ConnNum)
				{
						this->ConnectionNumber=ConnNum;
				}
			void setConnectionDate(Time ConnDate)
				{
						*this->ConnectionDate=ConnDate;
				}
			void setTrackerBeggin(Time TrackerBegin)
				{
						*this->TrackerBegin=TrackerBegin;
				}
			void setSellPrice(float Price)
				{
						this->SellPrice=Price;
				}
	};
};
#endif
