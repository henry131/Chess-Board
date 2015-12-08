#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece {
private:

public:
	//CONSTRUCTOR
	Queen (bool white_color);
	
	~Queen ();
	
	bool valid_move (const char* start, const char* end, bool taking);

};

#endif /*QUEEN_H*/
