#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include<cstring>
#include<map>

#include "Piece.h"

typedef map<string,Piece*> ::iterator it_type;

class ChessBoard {
private:
	
	/**ATTRIBUTES**/
	
	map < string , Piece* > board;
	bool game_over;
	bool is_taking;
	bool white_turn;
	
	//FREE MEMORY ON HEAP AND CLEAR BOARD
	void delete_pieces ();
	
	//CONFIGURE BOARD WITH STARTING CHESS CONFIG
	void configure ();
	
	//CHANGE PLAYERS TURN
	void change_turn();
	
	//CHECK VALIDITY OF square INPUT
	bool check_squares (const char* square) const;
	
	//ANY OTHER PIECES BETWEEN start AND end MAKING MOVE INVALID
	bool check_obstacles (const char* start, const char* end);
	
	//IS start TO end A VALID MOVE FOR PIECE (TAKING OR NOT (t))
	bool validate_move (const char* start, const char* end, bool t);
	
	//RETURNS white PLAYER'S KING POSITION
	string find_king (bool white);
	
	//CAN white PLAYER'S KING (ON SQUARE k) BE "TAKEN" NEXT GO
	bool king_in_check (bool white, const char* king);
	
	//CAN white MOVE WITHOUT PUTTING KING (ON SQUARE k) IN CHECK
	bool stalemate (bool white, const char* k);
	
public:

	//CONSTRUCTOR - CONFIGURES BOARD TO STARTING POSITION
	ChessBoard ();

	//DESTRUCTOR - FREES HEAP MEMORY AND CLEARS BOARD
	~ChessBoard ();
	
	//FREES MEMORY, CLEARS THEN RECONFIGURES BOARD TO STARTING POS
	void resetBoard ();

	//IF VALID, MOVE PIECE FROM start TO end, TAKE PIECE IF ONE IN end
	//IF INVALID MOVE PRINT ERROR MESSAGE
	//PRINTS (cout) OUTPUT INCL WHETHER PLAYER IN CHECK/STALE (-MATE) 
	void submitMove (const char* start, const char* end);	
	
	//PRINT (cout) CURRENT STATE OF CHESSBOARD (debugging)
	void print ();
};

#endif /*CHESSBOARD_H*/
