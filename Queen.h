#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece {
public:
	//CONSTRUCTOR- SETS TYPE TO Queen
	Queen (bool white_color);
	
	//VIRTUAL DESTRUCTOR	
	~Queen ();
	
	//VIRTUAL
	//DOES start TO end MOVE (TAKING = t), CONFORM WITH PIECE RULES
	bool valid_move (const char* start, const char* end, bool t);

};

#endif /*QUEEN_H*/
