/*---------------------------------------------------------
Last Edited: 26th November 2015
Author: Henry Williams, hw5115, 01141713
Description: Castle Class
---------------------------------------------------------*/

#include <iostream>

using namespace std;

#include "Castle.h"
#include "Piece.h"

//Constructor

Castle::Castle (bool white_color) : Piece (white_color)
{
	type = castle;
}

Castle::~Castle ()
{
	//blank
}

bool Castle::valid_move (const char* start, const char* end, bool taking)
{
	//Straight along column
	if (start[0] == end[0])
		return true;
	//Straight along row
	if (start[1] == end[1])
		return true;
	
	return false;
}
