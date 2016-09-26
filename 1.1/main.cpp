//Programm zur Berechnung der Anzahl der Situationen einer akterm an denen
//potentiell Kaltluftabflüsse entstehen können
//Das Kriterium hierfür sieht folgendermaßen aus:
//Als Situation wird eine Stunde gezählt, wenn
//AK = 1; v < 1,5 m/s
//Weiterhin wird eine Situation erst dann regisitriert, wenn
//die Kriterien mindestens 2 Stunden vorher bereits erfüllt waren

#include "file_handling.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    string filename_input{"S:\\Datenban\\Wetter\\Programme\\Kaltluft\\input_kaltluft.txt"};
    ifstream file_in;
    string akterm_name{""};
    ifstream akterm_in;
    int calms_ak1{0};

    file_in.open(filename_input, ios::in);
    read_input(file_in, akterm_name);
    akterm_in.open(akterm_name, ios::in);

    get_calms_ak1(akterm_in, calms_ak1);

    cout << "Potentielle Kaltluftsituationen: " << calms_ak1 << "\n";
    cout << "Prozentualer Anteil an Jahresstunden: " << calms_ak1/8760.0*100.0 << "\%\n";

    do
    {
        ;
    }while(true);

    return 0;
}
