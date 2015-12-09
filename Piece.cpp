/*---------------------------------------------------------
Last Edited: 9th December 2015
Author: Henry Williams, hw5115, 01141713
Description: (Chess) Piece Class
---------------------------------------------------------*/

#include <cstring>

#include "Piece.h"

//Constructor

Piece::Piece (bool color)
{
	white_color = color;
	type = n_a;
	first_move = true;
}

//Returns first_move bool (used to monitor pawn 2 vs 1 squares)

bool Piece::check_first_move ()
{
	return first_move;
}

//Sets first_move to false (used to monitor pawn 2 vs 1 squares)

void Piece::not_first_move ()
{
	first_move = false;
}

//Returns white_color bool

bool Piece::get_white_color () const
{
	return white_color;
}

//Returns string representation of piece based on classification
//e.g."King"

string Piece::get_type () const
{
	switch(type)
	{
		case 0: break;
		case 1: return "King";
			break;
		case 2: return "Queen";
			break;
		case 3: return "Knight";
			break;
		case 4: return "Bishop";
			break;
		case 5: return "Rook";
			break;
		case 6: return "Pawn";
			break;
		default:
			break;	
	}
	return "";//Should never get here
}

