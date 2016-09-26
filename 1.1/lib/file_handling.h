#ifndef FILE_HANDLING_H
#define FILE_HANDLING_H

#include <fstream>
#include <string>

//Funktion, um input-Datei einzulesen
void read_input(std::ifstream &file_in, std::string &akterm);

//Funktion, die aus aktermZeile Wind und AK ermittelt
void read_line(std::ifstream &akterm_in, int &year, int &month, 
     int &day, int &hour, int &qdd, int &qff, int &wd, int &ak, int &v);

//Funktion, um Kalmen auszuzählen
void get_calms_ak1(std::ifstream &akterm_in, int &counter);

#endif // FILE_HANDLING_H
