#include "file_handling.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

void read_input(std::ifstream &file_in, std::string &akterm)
{

    file_in >> akterm >> akterm;

}

void read_line(std::ifstream &akterm_in, int &year, int &month, 
     int &day, int &hour, int &qdd, int &qff, int &wd, int &ak, int &v)
{

    std::string dummy{};
    akterm_in >> dummy >> year >> month >> day >> hour >> dummy >> qdd >> qff >> wd;
    akterm_in >> v >> dummy >> ak >> dummy >> dummy >> dummy;

}


void get_calms_ak1(std::ifstream &akterm_in, int &counter)
{
    std::string dummy{""};
    do
    {
        akterm_in >> dummy;
    }while(dummy != "AK");

	int year{0};
	int month{0};
	int day{0};
	int hour{0};
	int qdd{0};
	int qff{0};
	int wd{0};
    int ak{0};
    int v{0};
    int count_period_length{0};
    
    std::string akterm_mod_name{"akterm_mod.dmna"};
    std::ofstream akterm_mod;
    
    akterm_mod.open(akterm_mod_name, std::ios::out);

    for(int i = 0; i<8760; i++)
    {
        read_line(akterm_in, year, month, day, hour, qdd, qff, wd, ak, v);
        //Ausbreitungsklasse 1, Windgeschwindigkeitsklasse 1 oder 2
        //Und Windrichtung 270-300°  --->  && (wd >= 270 && wd <= 300)
        //und Nacht (vereinfacht zu Stunden zwischen 20:00 und 7:00)
        if(/*ak == 1 && */v < 20 && (
           (i%7 == 0 && ((hour >= 11 && hour <= 13) || (hour >= 17 && hour <= 22))) || //MONTAG
           (i%7 == 1 && ((hour >= 11 && hour <= 13) || (hour >= 17 && hour <= 22))) || //DIENSTAG
           (i%7 == 2 && ((hour >= 11 && hour <= 13) || (hour >= 17 && hour <= 22))) || //MITTWOCH
           (i%7 == 3 && ((hour >= 11 && hour <= 13) || (hour >= 17 && hour <= 22))) || //DONNERSTAG
           (i%7 == 4 && ((hour >= 11 && hour <= 13) || (hour >= 17 && hour <= 22))) || //FREITAG
           (i%7 == 5 && (hour >= 15 && hour <= 22)) || //SAMSTAG
           (i%7 == 6 && (hour >= 12 && hour <= 22))))  //SONNTAG
        {
			count_period_length++;
			if(count_period_length >= 0)
			{
				akterm_mod << "AK 10446 ";
				akterm_mod << std::setw(4) << std::setfill(' ') << year << " ";
				akterm_mod << std::setw(2) << std::setfill('0') << month << " ";
				akterm_mod << std::setw(2) << std::setfill('0') << day << " ";
				akterm_mod << std::setw(2) << std::setfill('0') << hour << " ";
				akterm_mod << "00 " << qdd << " " << qff << " ";
				akterm_mod << std::setw(3) << std::setfill(' ') << wd << " ";
				akterm_mod << std::setw(3) << std::setfill(' ') << v << " ";
				akterm_mod << "1 " << ak << " 1 -999 9\n";
				
                counter++;
			}
        }
        else
        {
            count_period_length = 0;
        }

        if(i != 8759)
            akterm_in >> dummy;
    }
    
    akterm_mod.close();

}
