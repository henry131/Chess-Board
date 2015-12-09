/*---------------------------------------------------------
Last Edited: 9th December 2015
Author: Henry Williams, hw5115, 01141713
Description: Pawn Class
---------------------------------------------------------*/

#include "Pawn.h"
#include "Piece.h"

//Constructor

Pawn::Pawn (bool color_white) : Piece (color_white)
{
	type = pawn;
}

//Destructor

Pawn::~Pawn ()
{
	//blank
}

//Checks move is valid according to position's standard chess rules

bool Pawn::valid_move (const char* start, const char* end, bool t)
{
	int max_length = 1;
	
	//If pawn's first move then can move two rows (if not taking)
	if (first_move && !t)
		max_length = 2;

	//Check column movement
	
	if (t)
	{
		//If taking, must move to adjacent column otherwise invalid
		if (!(end[0] == (start[0] + 1) || end[0] == (start[0] - 1)))
			return false;
	}
	else
	{
		//If not taking, must stay in same column	otherwise invalid
		if (end[0] != start[0])
			return false;
	}
	
	//Check row movement
	//for white, must move "up" board (end - start)
	//for black, must move "down" board (start - end)
	
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
	
	//Default case: valid move
	return true;
}
