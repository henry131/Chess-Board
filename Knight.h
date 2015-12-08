#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece {
private:

public:
	
	//Constructor
	Knight (bool white_color);
	
	~Knight ();
	
	bool valid_move (const char* start, const char* end, bool taking);

};

#endif /*KNIGHT_H*/
