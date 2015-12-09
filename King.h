#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece {
public:

	//CONSTRUCTOR - SETS TYPE TO king
	King (bool white_color);
	
	//VIRTUAL DESTRUCTOR
	~King ();
	
	//VIRTUAL
	//DOES start TO end MOVE (TAKING = t), CONFORM WITH PIECE RULES
	bool valid_move (const char* start, const char* end, bool t);

};

#endif /*KING_H*/
