#include <phpcpp.h>
#include <string>
#include <my_time.h>
#include <customer.h>
#include <county.h>
#include <constructor.h>
#include <panel.h>
#include <mounter.h>
#include <cboard.h>
#include <inverter.h>


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
						this->Owner=new Customer();
						this->county=new County();
						this->panel=new Panel();
						this->Mounting=new Mounter();
						this->inverter=new Inverter();
						this->cboard=new CBoard();
						this->constructor=new Constructor();
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
					this->Owner=new Customer();
					*this->Owner=Owner;
					this->county=new County();
					*this->county=county;
					this->Borough=Borough;
					this->Location=Location;
					this->Area=Area;
					this->NPanels=NPanels;
					this->panel=new Panel();
					*this->panel=panel;
					this->Strings=Strings;
					this->Mounting=new Mounter();
					*this->Mounting=mounting;
					this->inverter=new Inverter();
					*this->inverter=inverter;
					this->cboard=new CBoard();
					*this->cboard=cboard;
					this->constructor=new Constructor();
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
				return Php::Object("Customer",this->Owner);
				}
			Php::Value getCounty(void)
				{
				return Php::Object("County",this->county);
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
				return Php::Object("Panel",this->panel);
				}
			Php::Value getStrings(void)
				{
				return this->Strings;
				}
			Php::Value getMounting(void)
				{
				return Php::Object("Mounter",this->Mounting);
				}
			Php::Value getInverter(void)
				{
				return Php::Object("Inverter",this->inverter);
				}
			Php::Value getCBoard(void)
				{
				return Php::Object("CBoard",this->cboard);
				}
			Php::Value getConstructor(void)
				{
				return Php::Object("Constructor",this->constructor);
				}
			Php::Value getConnectionNumber(void)
				{
				return (double) this->ConnectionNumber;
				}
			Php::Value getConnectionDate(void)
				{
				return Php::Object("Time",this->ConnectionDate);
				}
			Php::Value getTrackerBegin(void)
				{
				return Php::Object("Time",this->TrackerBegin);
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
