#include "boarddisplay.h"
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

 void BoardDisplay::print(){
 cout << setfill('_') << setw(90) << "" << endl;
    cout << "|Goose  |       |NEEDLES|       |       |V1     |       |       |CIF    |       |GO TO  |" << endl;
    cout << "|NESTING|       |HALL   |       |       |       |       |       |       |       |TIMS   |" << endl;
    cout << "|       |EV1    |       |EV2    |EV2    |       |PHYS   |B1     |       |B2     |       |" << endl;
    for (int i = 0; i < 11; i++)
    {
        cout << "|" << setfill(' ') << setw(7) << "";
    }
    cout << "|" << endl;
    for (int i = 0; i < 11; i++)
    {
        cout << "|" << setfill('_') << setw(7) << "";
    }
    cout << "|" << endl;
    cout << "|       |" << setfill(' ') << setw(80) << "|       |" << endl;
    cout << "|-------|" << setfill(' ') << setw(80) << "|-------|" << endl;
    cout << "|OPT    |" << setfill(' ') << setw(80) << "|EIT    |" << endl;
    cout << "|       |" << setfill(' ') << setw(80) << "|       |" << endl;
    cout << "|_______|" << setfill(' ') << setw(80) << "|_______|" << endl;
    cout << "|       |" << setfill(' ') << setw(80) << "|       |" << endl;
    cout << "|-------|" << setfill(' ') << setw(80) << "|-------|" << endl;
    cout << "|BMH    |" << setfill(' ') << setw(80) << "|ESC    |" << endl;
    cout << "|       |" << setfill(' ') << setw(80) << "|       |" << endl;
    cout << "|_______|" << setfill(' ') << setw(80) << "|_______|" << endl;
    cout << "|SLC    |" << setfill(' ') << setw(80) << "|SLC    |" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "|       |" << setfill(' ') << setw(80) << "|       |" << endl;
    }
    cout << "|_______|" << setfill(' ') << setw(80) << "|_______|" << endl;
    cout << "|       |" << setfill(' ') << setw(80) << "|       |" << endl;
    cout << "|-------|" << setfill(' ') << setw(80) << "|-------|" << endl;

    // print watopoly sign
    cout << "|LHI    |" << setfill (' ') << setw (59);
    cout << "                 |                     |       ";
    cout << setw (21) << "|C2     |" << endl;
    cout << "|       |" << setfill (' ') << setw (60);
    cout << "\\ \\  \\   / _` | __|  _ \\  __ \\   _ \\  | |   |  ";
    cout << setw (20) << "|       |" << endl;
    cout << "|_______|" << setfill (' ') << setw (60);
    cout << " \\ \\  \\ / (   | |   (   | |   | (   | | |   |  ";
    cout << setw (20) << "|_______|" << endl;
    cout << "|UWP    |" << setfill (' ') << setw (60);
    cout << " \\_/\\_/ \\__,_|\\__|\\___/  .__/ \\___/ _|\\__, |  ";
    cout << setw (20) << "|REV    |" << endl;
    cout << "|       |" << setfill (' ') << setw (60);
    cout << "                       _|            ____/  ";
    cout << setw (20) << "|       |" << endl;
    

    // end of watopoly sign

    cout << "|       |" << setfill(' ') << setw(80) << "|       |" << endl;
    cout << "|       |" << setfill(' ') << setw(80) << "|       |" << endl;
    cout << "|_______|" << setfill(' ') << setw(80) << "|_______|" << endl;
    cout << "|       |" << setfill(' ') << setw(80) << "|       |" << endl;
    cout << "|-------|" << setfill(' ') << setw(80) << "|-------|" << endl;
    cout << "|DWE    |" << setfill(' ') << setw(80) << "|MC     |" << endl;
    cout << "|       |" << setfill(' ') << setw(80) << "|       |" << endl;
    cout << "|_______|" << setfill(' ') << setw(80) << "|_______|" << endl;
    cout << "|PAC    |" << setfill(' ') << setw(80) << "|COOP   |"<< endl;
    cout << "|       |" << setfill(' ') << setw(80) << "|FEE    |" << endl;
    cout << "|       |" << setfill(' ') << setw(80) << "|       |" << endl;
    cout << "|       |" << setfill(' ') << setw(80) << "|       |" << endl;
    cout << "|_______|" << setfill(' ') << setw(80) << "|_______|" << endl;
    cout << "|       |" << setfill(' ') << setw(80) << "|       |" << endl;
    cout << "|-------|" << setfill(' ') << setw(80) << "|-------|" << endl;
    cout << "|RCH    |" << setfill(' ') << setw(80) << "|DC     |" << endl;
    cout << "|       |" << setfill(' ') << setw(80) << "|       |" << endl;
    cout << "|_______|" << setfill('_') << setw(80) << "|_______|" << endl;
    cout << "|DC Tims|       |       |NEEDLES|       |MKV    |TUITION|       |SLC    |       |COLLECT|" << endl;
    //
    cout << "|Line   |       |       |HALL   |       |MKV    |       |       |SLC    |       |OSAP   |" << endl;
    cout << "|       |HH     |PASS   |       |ECH    |       |       |B1     |       |B2     |       |" << endl;

    for (int i = 0; i < 11; i++)
{
        cout << "|" << setfill(' ') << setw(7) << "";
    }     cout << "|" << endl; 
    for (int i = 0; i < 11; i++)
    {
        cout << "|" << setfill('_') << setw(7) << "";
    }    cout << "|" << endl; 
 
    

    



    


    /*
    cout << "                |                     |       "<< endl;
    cout << "\\ \\  \\   / _` | __|  _ \\  __ \\   _ \\  | |   |  " << endl;
    cout << " \\ \\  \\ / (   | |   (   | |   | (   | | |   |  " << endl;
    cout <<"  \\_/\\_/ \\__,_|\\__|\\___/  .__/ \\___/ _|\\__, | " << endl;
    cout <<"                         _|            ____/ " << endl;
    */

 }