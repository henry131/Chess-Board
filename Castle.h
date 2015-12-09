#ifndef CASTLE_H
#define CASTLE_H

#include "Piece.h"

class Castle : public Piece {
public:

	//CONSTRUCTOR - SETS TYPE TO Castle 
	Castle (bool white_color);
	
	//VIRTUAL DESTRUCTOR
	~Castle ();
	
	//VIRTUAL
	//DOES start TO end MOVE (TAKING = t), CONFORM WITH PIECE RULES
	bool valid_move (const char* start, const char* end, bool t);

};

#endif /*CASTLE_H*/
