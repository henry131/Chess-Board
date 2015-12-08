#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece {
private:

public:
	//CONSTRUCTOR
	Bishop (bool white_color);
	
	~Bishop ();
	
	bool valid_move (const char* start, const char* end, bool taking);

};

#endif /*BISHOP_H*/
