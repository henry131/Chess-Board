#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece {
public:
	
	//CONSTRUCTOR - SETS TYPE TO Knight
	Knight (bool white_color);
	
	//VIRTUAL DESTRUCTOR
	~Knight ();
	
	//VIRTUAL
	//DOES start TO end MOVE (TAKING = t), CONFORM WITH PIECE RULES
	bool valid_move (const char* start, const char* end, bool t);

};

#endif /*KNIGHT_H*/
