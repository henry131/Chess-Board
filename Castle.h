#ifndef CASTLE_H
#define CASTLE_H

#include "Piece.h"

class Castle : public Piece {
private:

public:
	//CONSTRUCTOR
	Castle (bool white_color);
	
	~Castle ();
	
	bool valid_move (const char* start, const char* end, bool taking);

};

#endif /*CASTLE_H*/
