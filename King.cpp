/*---------------------------------------------------------
Last Edited: 26th November 2015
Author: Henry Williams, hw5115, 01141713
Description: King Class
---------------------------------------------------------*/

#include <iostream>
#include <cmath>

using namespace std;

#include "King.h"
#include "Piece.h"

//Constructor

King::King (bool white_color) : Piece (white_color)
{
	type = king;
}

King::~King ()
{
	//blank
}

bool King::valid_move (const char* start, const char* end, bool taking)
{
	if (abs(end[0] - start[0]) > 1 || abs(end[1] - start[1]) > 1)
		return false;
	return true;
}

