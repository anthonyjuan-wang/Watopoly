#include "displayBoard.h"
#include "board.h"
#include "tile.h"

displayBoard::displayBoard() {}

displayBoard::~displayBoard() {}

Board displayBoard::getBoard() {
        // Need to also send 
    //      Position
    //      Price to Buy
    //      Improvement Cost
    //      Tutition With Expenses (all)
    Tile AL {
        AL->blockName = "AL";
        AL->monopoly = "Arts1";
        AL->purchaseCost = 40;
        AL->imrpovementCost = 50;
        AL->tuitionWithImprovements = {{0,2}, {1, 10}, {2, 30}, {3,90}, {4, 160}, {5, 250}};
    }

    Tile ML {
        
    }

    board.emplace_back(AL);
    board.emplace_back("ML");
    board.emplace_back("ECH");
    board.emplace_back("PAS");
    board.emplace_back("HH");
    board.emplace_back("RCH");
    board.emplace_back("DWE");
    board.emplace_back("CPH");
    board.emplace_back("LHI");
    board.emplace_back("BMH");
    board.emplace_back("OPT");
    board.emplace_back("EV1");
    board.emplace_back("EV2");
    board.emplace_back("EV2");
    board.emplace_back("EV3");
    board.emplace_back("PHYS");
    board.emplace_back("B1");
    board.emplace_back("B2");
    board.emplace_back("EIT");
    board.emplace_back("ESC");
    board.emplace_back("C2");
    board.emplace_back("MC");
    board.emplace_back("DC");
// AL Arts1 40 50 2 10 30 90 160 250
// ML Arts1 60 50 4 20 60 180 320 450
// ECH Arts2 100 50 6 30 90 270 400 550
// PAS Arts2 100 50 6 30 90 270 400 550
// HH Arts2 120 50 8 40 100 300 450 600
// RCH Eng 140 100 10 50 150 450 625 750
// DWE Eng 140 100 10 50 150 450 625 750
// CPH Eng 160 100 12 60 180 500 700 900
// LHI Health 180 100 14 70 200 550 750 950
// BMH Health 180 100 14 70 200 550 750 950
// OPT Health 200 100 16 80 220 600 800 1000
// EV1 Env 220 150 18 90 250 700 875 1050
// EV2 Env 220 150 18 90 250 700 875 1050
// EV3 Env 240 150 20 100 300 750 925 1100
// PHYS Sci1 260 150 22 110 330 800 975 1150
// B1 Sci1 260 150 22 110 330 800 975 1150
// B2 Sci1 280 150 24 120 360 850 1025 1200
// EIT Sci2 300 200 26 130 390 900 1100 1275
// ESC Sci2 300 200 26 130 390 900 1100 1275
// C2 Sci2 320 200 28 150 450 1000 1200 1400
// MC Math 350 200 35 175 500 1100 1300 1500
// DC Math 400 200 50 200 600 1400 1700 2000

}

void displayBoard::print() {

}