/*---------------------------------------------------------
Last Edited: 26th November 2015
Author: Henry Williams, hw5115, 01141713
Description: Queen Class
---------------------------------------------------------*/

#include <iostream>

using namespace std;

#include "Queen.h"
#include "Piece.h"

//Constructor

Queen::Queen (bool white_color) : Piece (white_color)
{
	type = queen;
}

Queen::~Queen ()
{
	//blank
}

bool Queen::valid_move (const char* start, const char* end, bool taking)
{
	char i[3];
	i[2] = '\0';
	
	//Straight along column
	if (start[0] == end[0])
		return true;
	//Straight along row
	if (start[1] == end[1])
		return true;
	
	//Set i to be at start
	i[0] = start[0];
	i[1] = start[1];
	
	//Diagonal "up" right
	if (start[0] < end[0] && start[1] < end[1])
	{
		while (i[0] < 'H' && i[1] < '8')
		{
			i[0]++;
			i[1]++;
			if (i[0] == end[0] && i[1] == end[1])
				return true;
		}
	}
	
	//Diagonal "up" left
	if (start[0] > end[0] && start[1] < end[1])
	{
		while (i[0] > 'A' && i[1] < '8')
		{
			i[0]--;
			i[1]++;
			if (i[0] == end[0] && i[1] == end[1])
				return true;
		}
	}
	
	//Diagonal "down" left
	if (start[0] > end[0] && start[1] > end[1])
	{
		while (i[0] > 'A' && i[1] > '1')
		{
			i[0]--;
			i[1]--;
			if (i[0] == end[0] && i[1] == end[1])
				return true;
		}
	}
	
	//Diagonal "down" right
	if (start[0] < end[0] && start[1] > end[1])
	{
		while (i[0] < 'H' && i[1] > '1')
		{
			i[0]++;
			i[1]--;
			if (i[0] == end[0] && i[1] == end[1])
				return true;
		}
	}
	return false;
}

