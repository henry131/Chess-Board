/*---------------------------------------------------------
Last Edited: 26th November 2015
Author: Henry Williams, hw5115, 01141713
Description: Pawn Class
---------------------------------------------------------*/

#include <iostream>

using namespace std;

#include "Pawn.h"
#include "Piece.h"

//Constructor

Pawn::Pawn (bool color_white) : Piece (color_white)
{
	type = pawn;
}

Pawn::~Pawn ()
{
	//blank
}

bool Pawn::valid_move (const char* start, const char* end, bool taking)
{
	int max_length = 1;
	
	//If pawn still hasn't moved then it can move two rows (if not taking)
	if (first_move && !taking)
		max_length = 2;

	//Check column movement
	if (taking)
	{
		//If taking, must move to adjacent column
		if (!(end[0] == (start[0] + 1) || end[0] == (start[0] - 1)))
			return false;
	}
	else
	{
		//If not taking, must stay in same column	
		if (end[0] != start[0])
			return false;
	}
	
	//Check row movement
	if (white_color)
	{
		if ((end[1] - start[1]) > max_length || (end[1] - start[1]) <= 0)
				return false;
	}
	else
	{
		if ((start[1] - end[1]) > max_length || (start[1] - end[1]) <= 0)
				return false;
	}
	
	return true;
}
