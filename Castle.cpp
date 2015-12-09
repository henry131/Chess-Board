/*---------------------------------------------------------
Last Edited: 9th December 2015
Author: Henry Williams, hw5115, 01141713
Description: Castle Class
---------------------------------------------------------*/

#include "Castle.h"
#include "Piece.h"

//Constructor

Castle::Castle (bool white_color) : Piece (white_color)
{
	type = castle;
}

//Destructor

Castle::~Castle ()
{
	//blank
}

//Checks move is valid according to position's standard chess rules

bool Castle::valid_move (const char* start, const char* end, bool t)
{
	//Straight along column: valid
	if (start[0] == end[0])
		return true;
		
	//Straight along row: valid
	if (start[1] == end[1])
		return true;
	
	//Default case: invalid move
	return false;
}
