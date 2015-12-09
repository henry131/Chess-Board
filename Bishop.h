#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece {
public:
	//CONSTRUCTOR - SETS TYPE TO Bishop
	Bishop (bool white_color);
	
	//VIRTUAL DESTRUCTOR
	~Bishop ();
	
	//VIRTUAL
	//DOES start TO end MOVE (TAKING = t), CONFORM WITH PIECE RULES
	bool valid_move (const char* start, const char* end, bool t);

};

#endif /*BISHOP_H*/
