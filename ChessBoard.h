#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include<cstring>
#include<map>

#include "Piece.h"

typedef map<string,Piece*> ::iterator it_type;

class ChessBoard {
private:
	
	//ATTRIBUTES
	
	map < string , Piece* > board;
	bool game_over;
	bool is_taking;
	bool white_turn;
	
	//DELETE POINTERS ETC
	void delete_pieces ();
	
	//CONFIGURE BOARD WITH STARTING CHESS CONFIG
	void configure ();
	
	//CHANGE PLAYERS TURN BOOL
	void change_turn();
	
	//VALIDATES A MOVE BASED ON PIECE'S ABILITY
	bool validate_move (const char* start, const char* end, bool t);
	
	//CHECK VALIDITY OF SQUARE INPUT
	bool check_squares (const char* square) const;
	
	//CHECK OBSTACLES IN WAY OF VALID PIECE MOVE
	bool check_obstacles (const char* start, const char* end);
	
	//LOCATE THE KING POSITION
	string find_king (bool white);
	
	//CHECK WHETHER MOVE PUTS OWN KING IN CHECK
	bool king_in_check (bool white, const char* king);
	
	//CHECK WHETHER PLAYER CAN MAKE A MOVE THAT DOES NOT LEAVE KING IN CHECK
	bool stalemate (bool white, const char* k);
	
public:

	//CONSTRUCTOR
	ChessBoard ();

	//DESTRUCTOR
	~ChessBoard ();
	
	//RESET BOARD
	void resetBoard ();

	//SUBMIT MOVE
	void submitMove (const char* start, const char* end);	
	
	//PRINT (cout) CURRENT STATE OF CHESSBOARD (debugging)
	void print ();
};

#endif /*CHESSBOARD_H*/
