/*---------------------------------------------------------
Last Edited: 9th December 2015
Author: Henry Williams, hw5115, 01141713
Description: King Class
---------------------------------------------------------*/

#include <cstdlib>

#include "King.h"
#include "Piece.h"

//Constructor

King::King (bool white_color) : Piece (white_color)
{
	type = king;
}

//Destructor

King::~King ()
{
	//blank
}

//Checks move is valid according to position's standard chess rules

bool King::valid_move (const char* start, const char* end, bool t)
{
	//If moving more than 1 square (straight or diagonally): invalid
	if (abs(end[0] - start[0]) > 1 || abs(end[1] - start[1]) > 1)
		return false;
		
	//Default case: valid move
	return true;
}

