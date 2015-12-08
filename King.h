#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece {
private:

public:
	//CONSTRUCTOR
	King (bool white_color);
	
	//DESTRUCTOR
	~King ();
	
	bool valid_move (const char* start, const char* end, bool taking);

};

#endif /*KING_H*/
