#include <iostream>
#include <string>
#include "board.h"
#include "boarddisplay.h"
using namespace std;

int main(int argc, char *argv[]) {

        cout << "Welcome to Waterloo's spin on monopoly, Watopoly." << endl;
        cin.exceptions(ios::eofbit | ios::failbit);
        srand (time(NULL));
        string cmd;
        Board theGame{};
        bool testing = false;
        bool errorRaised = false;
        string filename = "N/A";
      
         for (int i=0; i < argc; i++){
		string command = argv[i];
		if (command == "-testing"){
			testing = true;
		}
		else if (command == "-load"){
			if ( argc > (i + 1)){
				filename = argv[i+1];
			}
		}
         }


        if (testing){
                cout << "Entering Testing Mode." << endl;
                theGame.setTestingMode();
        } 

   
        if (filename != "N/A"){
                try{
                        cout << "Loading file...." << endl;
                        cout << filename << endl;
                        theGame.loadGame(filename);
                        cout << "file " << filename  << " successfully loaded" << endl;
                }
                catch (const invalid_argument& error) {
                        errorRaised  = true;
                        cerr << error.what() << endl;
                        cout << "The file format was invalid." << endl;
                }
        }
        
       if (!errorRaised && filename != "N/A"){
                theGame.play();
        }

        else{
        int totalPlayers = 0; // value will change when players are deleted
        
        // ask the user for the number of players
        while (true) {
                cout << "How many players are there? ";
                cin >> totalPlayers;

                if (totalPlayers >= 2 && totalPlayers <= 8) {
                        theGame.init(totalPlayers);
                        break;
                }
                else {
                        cout << "The number of players you entered is invalid" << endl;
               }
        }
        theGame.play();
        }
}
