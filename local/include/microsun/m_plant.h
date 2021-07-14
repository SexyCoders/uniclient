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
		public:
			std::string ID;
			float Power;
			Customer Owner;
			County county;
			std::string Borough;
			std::string Location;
			double Area;
			long int NPanels;
			Panel panel;
			std::string Strings;
			Mounter  Mounting;
			Inverter inverter;
			CBoard cboard;
			Constructor constructor;
			unsigned long int ConnectionNumber;
			Time ConnectionDate;
			Time TrackerBegin;
			float SellPrice;
		public:
			Plant()
					{
					}
			Plant operator=(Plant src)
				{
					this->ID=src.ID;
					this->Power=src.Power;
					this->Owner=src.Owner;
					this->county=src.county;
					this->Borough=src.Borough;
					this->Location=src.Location;
					this->Area=src.Area;
					this->NPanels=src.NPanels;
					this->panel=src.panel;
					this->Strings=src.Strings;
					this->Mounting=src.Mounting;
					this->inverter=src.inverter;
					this->cboard=src.cboard;
					this->constructor=src.constructor;
					this->ConnectionNumber=src.ConnectionNumber;
					this->ConnectionDate=src.ConnectionDate;
					this->TrackerBegin=src.TrackerBegin;
					this->SellPrice=src.SellPrice;
				return *this;
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
				return Php::Object("MicrosunCustomer",&this->Owner);
				}
			Php::Value getCounty(void)
				{
				return Php::Object("MicrosunCounty",&this->county);
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
				return Php::Object("MicrosunPanel",&this->panel);
				}
			Php::Value getStrings(void)
				{
				return this->Strings;
				}
			Php::Value getMounting(void)
				{
				return Php::Object("MicrosunMounter",&this->Mounting);
				}
			Php::Value getInverter(void)
				{
				return Php::Object("MicrosunInverter",&this->inverter);
				}
			Php::Value getCBoard(void)
				{
				return Php::Object("MicrosunCBoard",&this->cboard);
				}
			Php::Value getConstructor(void)
				{
				return Php::Object("MicrosunConstructor",&this->constructor);
				}
			Php::Value getConnectionNumber(void)
				{
				return (double) this->ConnectionNumber;
				}
			Php::Value getConnectionDate(void)
				{
				return this->ConnectionDate.toString();
				}
			Php::Value getTrackerBegin(void)
				{
				return this->TrackerBegin.toString();
				}
			Php::Value getSellPrice(void)
				{
				return (double) this->SellPrice;
				}
	};
};
#endif
