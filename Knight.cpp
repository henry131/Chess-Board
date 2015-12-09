/*---------------------------------------------------------
Last Edited: 9th December 2015
Author: Henry Williams, hw5115, 01141713
Description: Knight Class
---------------------------------------------------------*/

#include <cstdlib>

#include "Knight.h"
#include "Piece.h"

//Constructor

Knight::Knight (bool white_color) : Piece (white_color)
{
	type = knight;
}

//Destructor

Knight::~Knight ()
{
	//blank
}

//Checks move is valid according to position's standard chess rules

bool Knight::valid_move (const char* start, const char* end, bool t)
{
	if (abs(end[0] - start [0]) == 2 && abs(end[1] - start [1]) == 1)
		return true;
	
	if (abs(end[0] - start [0]) == 1 && abs(end[1] - start [1]) == 2)
		return true;
	
	//Default case: invalid move
	return false;
}

