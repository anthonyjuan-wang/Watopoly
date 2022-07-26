#include "boarddisplay.h"
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "tile.h"
#include "player.h"
#include "board.h"


using namespace std;

BoardDisplay::BoardDisplay(Board *b): theBoard{b} {}


void BoardDisplay::printImprovements(std::shared_ptr<Tile> tile){
    int improvement = tile->getImprovement();
    for (int i = 0; i < 7; i++){
        if (i < improvement) cout << "X";
        else cout << "-";
    }  
}

void BoardDisplay::printPlayers(std::vector<std::shared_ptr<Player>> players, int index){
    int counter = 0;
    for (int i = 0; i < players.size(); i++){
         if (players[i]->getPos() == index){
            cout << players[i]->getPiece();
            counter++;
         }
    }
    while (counter < 7){
        cout << " ";
        counter++;
    }
}



void BoardDisplay::print() {



// Line 1
    cout << setfill('_') << setw(90) << "" << endl;
    cout << "|Goose  |       |NEEDLES|       |       |V1     |       |       |CIF    |       |GO TO  |" << endl;

// Line 2
    cout << "|NESTING|";
    printImprovements(theBoard->getTiles()[21]);
    cout << "|HALL   |";
    printImprovements(theBoard->getTiles()[22]);
    cout << "|";
    printImprovements(theBoard->getTiles()[23]);  
    cout << "|       |";
    printImprovements(theBoard->getTiles()[24]);
    cout << "|";
    printImprovements(theBoard->getTiles()[25]); 
    cout << "|       |";
    printImprovements(theBoard->getTiles()[26]); 
    cout << "|TIMS   |" << endl;


// Line 3
    cout << "|       |EV1    |       |EV2    |EV3    |       |PHYS   |ML     |       |AL     |       |" << endl;
    for (int i = 0; i < 11; i++) {
        cout << "|" << setfill(' ') << setw(7) << "";
    }    cout << "|" << endl;


// Line 4 
    for (int i = 20; i <=  30; i++){
        cout << "|";
        printPlayers(theBoard->getPlayers(),i);
    }   cout << "|" << endl;

// Line 5
     for (int i = 0; i < 11; i++) {
        cout << "|" << setfill('_') << setw(7) << "";
    }    cout << "|" << endl;

// Line 6 
    cout << "|       |" << setfill(' ') << setw(80) << "|       |" << endl;


// Line 7
    cout << "|";
    printImprovements(theBoard->getTiles()[19]);
    cout << "|" <<  setfill(' ') << setw(72);
    cout << "|";
    printImprovements(theBoard->getTiles()[31]);
    cout << "|" << endl;

// Line 8
    cout << "|OPT    |" << setfill(' ') << setw(80) << "|EIT    |" << endl;

// Line 9 
    cout << "|";
    printPlayers(theBoard->getPlayers(), 19);    
    cout << "|" << setfill (' ') << setw (72);
    cout << "|";
    printPlayers(theBoard->getPlayers(), 31);
    cout << "|" << endl;



// Line 10
    cout << "|_______|" << setfill(' ') << setw(80) << "|_______|" << endl;
// Line 11
    cout << "|       |" << setfill(' ') << setw(80) << "|       |" << endl;
// Line 12 
    cout << "|";
    printImprovements(theBoard->getTiles()[18]);
    cout << "|"  << setfill(' ') << setw(72);
    cout << "|";
    printImprovements(theBoard->getTiles()[32]);
    cout << "|" << endl;

// Line 13
    cout << "|BMH    |" << setfill(' ') << setw(80) << "|ESC    |" << endl;

// Line 14 
    cout << "|";
    printPlayers(theBoard->getPlayers(), 18);
    cout << "|" << setfill(' ') << setw(72); 
    cout << "|";
    printPlayers(theBoard->getPlayers(), 32);
    cout << "|" << endl;

// Line 15
    cout << "|_______|" << setfill(' ') << setw(80) << "|_______|" << endl;
// 16
    cout << "|SLC    |" << setfill(' ') << setw(80) << "|SLC    |" << endl;


// 17
    cout << "|       |" << setfill(' ') << setw(80) << "|       |" << endl;
// 18
    cout << "|";
    printPlayers(theBoard->getPlayers(), 17);
    cout << "|" << setfill(' ') << setw(72); 
    cout << "|";
    printPlayers(theBoard->getPlayers(), 33);  
    cout << "|" << endl;
    
// 19 
    cout << "|       |" << setfill(' ') << setw(80) << "|       |" << endl;

// 20
    cout << "|_______|" << setfill(' ') << setw(80) << "|_______|" << endl;
    cout << "|       |" << setfill(' ') << setw(80) << "|       |" << endl;

    cout << "|";
    printImprovements(theBoard->getTiles()[16]);
    cout << "|"  << setfill(' ') << setw(72);
    cout << "|";
    printImprovements(theBoard->getTiles()[34]);
    cout << "|" << endl;

 // 21
    // print watopoly sign
    cout << "|LHI    |" << setfill (' ') << setw (59);
    cout << "                 |                     |       ";
    cout << setw (21) << "|C2     |" << endl;

    // 22
    cout << "|";
    printPlayers(theBoard->getPlayers(), 16);
    cout << "|" << setfill (' ') << setw (52);
    cout << "             \\ \\  \\   / _` | __|  _ \\  __ \\   _ \\  | |   |  ";
    cout << setw (12) << "|";
    printPlayers(theBoard->getPlayers(), 34);  
    cout << "|" << endl;    

    // 23, 24, 25
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
    cout << "|";
    printPlayers(theBoard->getPlayers(), 15);
    cout << "|" << setfill(' ') << setw(72); 
    cout << "|";
    printPlayers(theBoard->getPlayers(), 35);  
    cout << "|" << endl;
    cout << "|       |" << setfill(' ') << setw(80) << "|       |" << endl;
    cout << "|_______|" << setfill(' ') << setw(80) << "|_______|" << endl;
    cout << "|       |" << setfill(' ') << setw(80) << "|NEEDLES|" << endl;
    cout << "|";
    printImprovements(theBoard->getTiles()[15]);
    cout << "|" << setfill(' ') << setw(80) << "|HALL   |" << endl;
    cout << "|CPH    |" << setfill(' ') << setw(80) << "|       |" << endl;

    cout << "|";
    printPlayers(theBoard->getPlayers(), 14);
    cout << "|" << setfill(' ') << setw(72); 
    cout << "|";
    printPlayers(theBoard->getPlayers(), 36);  
    cout << "|" << endl;


    cout << "|_______|" << setfill(' ') << setw(80) << "|_______|" << endl;
    cout << "|       |" << setfill(' ') << setw(80) << "|       |" << endl;
    cout << "|";
    printImprovements(theBoard->getTiles()[13]);
    cout << '|' << setfill(' ') << setw(72);
    cout << "|";
    printImprovements(theBoard->getTiles()[37]);
    cout << "|" << endl;


    cout << "|DWE    |" << setfill(' ') << setw(80) << "|MC     |" << endl;
    cout << "|";
    printPlayers(theBoard->getPlayers(), 13);
    cout << "|" << setfill(' ') << setw(72); 
    cout << "|";
    printPlayers(theBoard->getPlayers(), 37);
    cout << "|" << endl;
    cout << "|_______|" << setfill(' ') << setw(80) << "|_______|" << endl;
    cout << "|PAC    |" << setfill(' ') << setw(80) << "|COOP   |"<< endl;
    cout << "|       |" << setfill(' ') << setw(80) << "|FEE    |" << endl;
    cout << "|";
    printPlayers(theBoard->getPlayers(), 12);
    cout << "|" << setfill(' ') << setw(72); 
    cout << "|";
    printPlayers(theBoard->getPlayers(), 38);  
    cout << "|" << endl;
    cout << "|       |" << setfill(' ') << setw(80) << "|       |" << endl;
    cout << "|_______|" << setfill(' ') << setw(80) << "|_______|" << endl;
    cout << "|       |" << setfill(' ') << setw(80) << "|       |" << endl;
    cout << "|";
    printImprovements(theBoard->getTiles()[11]);
    cout << '|' << setfill(' ') << setw(72);
    cout << "|";
    printImprovements(theBoard->getTiles()[39]);
    cout << "|" << endl;
    cout << "|RCH    |" << setfill(' ') << setw(80) << "|DC     |" << endl;
    cout << "|";
    printPlayers(theBoard->getPlayers(), 11);
    cout << "|" << setfill(' ') << setw(72); 
    cout << "|";
    printPlayers(theBoard->getPlayers(), 39);  
    cout << "|" << endl;
    cout << "|_______|" << setfill('_') << setw(80) << "|_______|" << endl;
    cout << "|DC Tims|       |       |NEEDLES|       |MKV    |TUITION|       |SLC    |       |COLLECT|" << endl;    
    cout << "|Line   |";
    printImprovements(theBoard->getTiles()[9]);
    cout << "|"; 
    printImprovements(theBoard->getTiles()[8]); 
    cout << "|HALL   |";
    printImprovements(theBoard->getTiles()[6]); 
    cout << "|       |       |";
    printImprovements(theBoard->getTiles()[3]);
    cout << "|       |";
    printImprovements(theBoard->getTiles()[1]);
    cout << "|OSAP   |" << endl;
    cout << "|       |HH     |PASS   |       |ECH    |       |       |B1     |       |B2     |       |" << endl;  
    for (int i = 10; i >= 0; i--) {
        cout << "|";
        printPlayers(theBoard->getPlayers(), i);  
    }       cout << "|" << endl;
    
    for (int i = 0; i < 11; i++) {
        cout << "|" << setfill('_') << setw(7) << "";
    } cout << "|" << endl; 



}

