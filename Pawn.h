#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece {
public:

	//CONSTURUCTOR - SETS TYPE TO pawn
	Pawn (bool white_color);

	//VIRTUAL DESTRUCTOR
	~Pawn ();

	//VIRTUAL
	//DOES start TO end MOVE (TAKING = t), CONFORM WITH PIECE RULES
	bool valid_move (const char* start, const char* end, bool t);
	
};

#endif /*PAWN_H*/
