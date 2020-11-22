#pragma once

#include "Stocznia.hpp"

unsigned int transportujFlota(unsigned int towar)
{
    
	if (towar != 0)
	{
		unsigned int przewieziony_towar=0;
		unsigned int ilosc_zaglowcow=0;
		
		do
		{
			Stocznia stocznia{};
			Statek* s1 = stocznia();
			przewieziony_towar += s1->transportuj();
			if (Zaglowiec* z = dynamic_cast<Zaglowiec*>(s1))
			{
				ilosc_zaglowcow += 1;
			}
			delete s1;
		}
		while(przewieziony_towar < towar);
		
		std::cout << "Funkcja stworzyla: " << ilosc_zaglowcow << " zaglowcow";
        
        return ilosc_zaglowcow;
	}
    else
    {
    	std::cout<< "Nie utworzono, zadnego statku - nie bylo towaru do przewiezienia" ;
	}
    return 0;
}
