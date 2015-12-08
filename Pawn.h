#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece {
private:
public:

	//CONSTURUCTOR
	Pawn (bool white_color);

	~Pawn ();

	bool valid_move (const char* start, const char* end, bool taking);
	
	//void print ();
};

#endif /*PAWN_H*/
