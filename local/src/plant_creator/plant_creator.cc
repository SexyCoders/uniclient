#include <m_plant.h>
#include <string>
#include <iostream>
#include <stdio.h>

int main(int argc,char** argv)
    {
        printf("ID: "); 
        std::string ID;
        std::cin>>ID;
        printf("POWER: "); 
        float power;
        std::cin>>power;
        printf("OWNER: "); 
        int owner_id;
        std::cin>>owner_id;
        printf("COUNTY: "); 
        int county_id;
        std::cin>>county_id;
        printf("BOROUGH: "); 
        std::string borough;
        std::cin>>borough;
        printf("LOCATION: "); 
        std::string location;
        std::cin>>location;
        printf("AREA: "); 
        float area;
        std::cin>>area;
        printf("NPANELS: "); 
        int npanels;
        std::cin>>npanels;
        printf("PANEL: "); 
        int panel;
        std::cin>>panel;
        printf("STRINGS: "); 
        std::string _string;
        std::cin>>_string;
        printf("MOUNTING: "); 
        int mounting;
        std::cin>>mounting;
        printf("INVERTER: "); 
        int inverter;
        std::cin>>inverter;
        printf("CBOARD: "); 
        int cboard;
        std::cin>>cboard;
        printf("CONSTRUCTOR: "); 
        int constr;
        std::cin>>constr;
        printf("CONNUMBER: "); 
        long int connumber;
        std::cin>>connumber;
        printf("CONDATE: "); 
        std::string conndate;
        std::cin>>conndate;
        printf("TRACKBEGIN: "); 
        std::string trackbegin;
        std::cin>>trackbegin;
        printf("PRICE: "); 
        float price;
        std::cin>>price;
    }
