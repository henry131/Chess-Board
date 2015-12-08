/*---------------------------------------------------------
Last Edited: 26th November 2015
Author: Henry Williams, hw5115, 01141713
Description: Knight Class
---------------------------------------------------------*/

#include <iostream>
#include <cmath>

using namespace std;

#include "Knight.h"
#include "Piece.h"

//Constructor

Knight::Knight (bool white_color) : Piece (white_color)
{
	type = knight;
}

Knight::~Knight ()
{
	//blank
}

bool Knight::valid_move (const char* start, const char* end, bool taking)
{
	if (abs(end[0] - start [0]) == 2 && abs(end[1] - start [1]) == 1)
		return true;
	if (abs(end[1] - start [1]) == 2 && abs(end[0] - start [0]) == 1)
		return true;
	return false;
}

