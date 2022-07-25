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
        string load_file;
       for (int i=0; i < argc; i++){
		string command = argv[i];
		if (command == "-testing"){
			testing = true;
		}
		else if (command == "-load"){
			if ((i+1) <  argc){
				load_file = argv[i+1];
			}
		}
	}    

        if (testing){
                cout << "Entering Testing Mode." << endl;
                theGame.setTestingMode();
        }

        
        //int players;
        //cout << "Please enter the number of players that will be playing." << endl;
        //cin >> players;
        //theGame.init(players);
        theGame.initTiles();
        theGame.play();

}
