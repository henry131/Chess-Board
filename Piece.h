#ifndef PIECE_H
#define PIECE_H

#include <cstring>
#include <map>
#include <iostream>

using namespace std;

enum Classification
{
	n_a,
	king,
	queen,
	knight,
	bishop,
	castle,
	pawn
};

class Piece {
protected:

	/**ATTRIBUTES**/

	Classification type;
	bool white_color;
	bool first_move;
	
public:
	
	//CONSTRUCTOR - SETS THE COLOR AND FIRST_MOVE TO TRUE
	Piece (bool color);
	
	//VIRTUAL DESTRUCTOR
	virtual ~Piece () {};
	
	//VIRTUAL VALID MOVE FUNCTION
	virtual bool valid_move (const char*, const char*, bool) = 0;

	//RETURNS FIRST_MOVE BOOL
	bool check_first_move ();
	
	//CHANGES FIRST_MOVE BOOL TO FALSE
	void not_first_move ();

	//RETURNS WHITE_COLOR BOOL
	bool get_white_color () const;
	
	//RETURNS STRING TYPE OF PIECE BASED ON CLASSIFICATION, e.g."King"
	string get_type() const;
	
};


#endif /*PIECE_H*/
