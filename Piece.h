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
private:
protected:

	Classification type;
	bool white_color;
	bool first_move;
	
public:
	
	//CONSTRUCTOR
	Piece (bool color);
	
	//DESTRUCTOR
	virtual ~Piece () {};
	
	virtual bool valid_move (const char*, const char*, bool) = 0;

	bool check_first_move ();
	
	void not_first_move ();

	bool get_white_color () const;
	
	string get_type() const;
	
	void print() const;
	
};


#endif /*PIECE_H*/
