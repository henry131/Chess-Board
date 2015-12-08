/*---------------------------------------------------------
Last Edited: 26th November 2015
Author: Henry Williams, hw5115, 01141713
Description: (Chess) Piece Class
---------------------------------------------------------*/

#include <iostream>
#include <cstring>
#include <map>

using namespace std;

#include "Piece.h"

//Constructor

Piece::Piece (bool color)
{
	white_color = color;
	type = n_a;
	first_move = true;
}

//Get Color Function

bool Piece::get_white_color () const
{
	return white_color;
}

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

bool Piece::check_first_move ()
{
	return first_move;
}

void Piece::not_first_move ()
{
	first_move = false;
}

void Piece::print () const
{
	if (white_color)
	{
		cout << "w";
	}
	else
	{
		cout << "b";
	}
	cout << type;
}
/*
ostream& operator << (ostream& out, const Piece& p)
{

}
*/



