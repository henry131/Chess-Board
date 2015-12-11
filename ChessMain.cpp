/*-------------------------------------------------------------------
Program Title: chess
Course: C++ Programming - Assessed Exercise No.3
Deadline: 14th December 2015

Date Started: 26th November 2015
Last Edited: 11th December 2015
Author: Henry Williams, hw5115, 01141713
Description: Main function
-------------------------------------------------------------------*/

#include <iostream>
#include <cstring>

using namespace std;

#include "ChessBoard.h"

int main() {

    cout << "===========================" << endl;
    cout << "Testing the Chess Engine" << endl;
    cout << "===========================" << endl;
    cout << endl;

    ChessBoard cb;
    cout << endl;

    cb.submitMove("D7", "D6");
    cout << endl;

    cb.submitMove("D4", "H6");
    cout << endl;

    cb.submitMove("D2", "D4");
    cout << endl;
    
    cb.submitMove("F8", "B4");
    cout << endl;

    cout << "===========================" << endl;
    cout << "Alekhine vs. Vasic (1931)" << endl;
    cout << "===========================" << endl;
    cout << endl;

    cb.resetBoard();
    cout << endl;

    cb.submitMove("E2", "E4");
    cb.submitMove("E7", "E6");
    cout << endl;

    cb.submitMove("D2", "D4");
    cb.submitMove("D7", "D5");
    cout << endl;

    cb.submitMove("B1", "C3");
    cb.submitMove("F8", "B4");
    cout << endl;

    cb.submitMove("F1", "D3");
    cb.submitMove("B4", "C3");
    cout << endl;

    cb.submitMove("B2", "C3");
    cb.submitMove("H7", "H6");
    cout << endl;

    cb.submitMove("C1", "A3");
    cb.submitMove("B8", "D7");
    cout << endl;

    cb.submitMove("D1", "E2");
    cb.submitMove("D5", "E4");
    cout << endl;

    cb.submitMove("D3", "E4");
    cb.submitMove("G8", "F6");
    cout << endl;

    cb.submitMove("E4", "D3");
    cb.submitMove("B7", "B6");
    cout << endl;

    cb.submitMove("E2", "E6");
    cb.submitMove("F7", "E6");
    cout << endl;
		
    cb.submitMove("D3", "G6");
    cout << endl;
    
    
/*--------------       User Testing    ------------------------*/


		if (user_tests) //trigger user tests in ChessBoard.h
		{
		
		  cout << "=============================" << endl;
		  cout << "User Testing the Chess Engine" << endl;
		  cout << "=============================" << endl;
		  cout << endl;
		  
		  cb.resetBoard();
		  cout << endl;
		  
		  //Wrong input
		  cb.submitMove("A1","A9"); //No (w turn)
		  cb.submitMove("A1","I8"); //No (w turn)
		  cb.submitMove("A11","A3"); //No (w turn)
		  cout << endl;
		  
		  //Testing obstacle
		  cb.submitMove("C1", "A3"); //No (w turn)
		  cb.submitMove("E1", "E2"); //No (w turn)
		  //Take colour of own piece
		  cb.submitMove("A1", "B1"); //No (w turn)
		  cout << endl;
		  
		  //Testing Knight Movement
		  cb.submitMove("B1", "C3"); //Yes (b turn)
		  cb.submitMove("B8", "C6"); //Yes (w turn)
		  cb.submitMove("C3", "E4"); //Yes (b turn)
		  cb.submitMove("C6", "A6"); //No (b turn)
		  cb.submitMove("C6", "B8"); //Yes (w turn)
		  cout << endl;
		  
		  //Testing Pawn Movement
		  cb.submitMove("B2", "B4"); // Yes (b turn)
		  cb.submitMove("A7", "A6"); // Yes (w turn)
		  cb.submitMove("B4", "B6"); // No (w turn) 
		  cb.submitMove("B4", "B3"); // No (w turn)
		  cb.submitMove("B4", "C5"); // No (w turn)
		  cb.submitMove("B4", "B5"); // Yes (b turn)
		  cb.submitMove("A6", "B5"); // Yes (w turn) - taking W Pawn
		  cb.submitMove("C2", "C3"); // Yes (b turn)
		  cb.submitMove("H7", "H5"); //	Yes (w turn) 
		  cout << endl;
		  
		  //Castle only move straight (there is no pawn at B2)
		  cb.submitMove("A1", "C3"); // No (w turn)
		  //Bishop cannot move straight
		  cb.submitMove("C1", "C2"); // No (w turn)
		  cout << endl;
		  
		  cout << "============================" << endl;
		  cout << "        Fool's Mate" << endl;
		  cout << "============================" << endl;
		  cout << endl;

		  cb.resetBoard();
		  cout << endl;

		  cb.submitMove("F2", "F3");
		  cout << endl;
		  cb.submitMove("E7", "E5");
		  cout << endl;
		  cb.submitMove("G2", "G4");
		  cout << endl;
		  cb.submitMove("D8", "H4"); //Checkmate
		  cout << endl;
		  
		  cb.submitMove("A2","A3"); //No - game over
		  cout << endl;
		  
		  cout << "============================" << endl;
		  cout << "    Quickest Stalemate" << endl;
		  cout << "============================" << endl;
		  cout << endl;   
		  
		  cb.resetBoard();
		  cout << endl;

		  cb.submitMove("E2", "E3");
		  cout << endl;
		  cb.submitMove("A7", "A5");
		  cout << endl;
		  cb.submitMove("D1", "H5");
		  cout << endl;
		  
		  cb.submitMove("F7", "F6"); //no - would put own king in check
		  cout << endl;
		  
		  cb.submitMove("A8", "A6");
		  cout << endl;
		  cb.submitMove("H5", "A5");
		  cout << endl;
		  cb.submitMove("H7", "H5");
		  cout << endl;
		  cb.submitMove("H2", "H4");
		  cout << endl;
		  cb.submitMove("A6", "H6");
		  cout << endl;
		  cb.submitMove("A5", "C7");
		  cout << endl;
		  cb.submitMove("F7", "F6");
		  cout << endl;
		  cb.submitMove("C7", "D7");
		  cout << endl;
		  cb.submitMove("E8", "F7");
		  cout << endl;
		  cb.submitMove("D7", "B7");
		  cout << endl;
		  cb.submitMove("D8", "D3");
		  cout << endl;
		  cb.submitMove("B7", "B8");
		  cout << endl;
		  cb.submitMove("D3", "H7");
		  cout << endl;
		  cb.submitMove("B8", "C8");
		  cout << endl;
		  cb.submitMove("F7", "G6");
		  cout << endl;
		  cb.submitMove("C8", "E6"); //stalemate
		  cout << endl;
		}

    return 0;
}
