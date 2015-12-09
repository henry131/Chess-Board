/*---------------------------------------------------------
Last Edited: 9th December 2015
Author: Henry Williams, hw5115, 01141713
Description: Queen Class
---------------------------------------------------------*/

#include "Queen.h"
#include "Piece.h"

//Constructor

Queen::Queen (bool white_color) : Piece (white_color)
{
	type = queen;
}

//Destructor

Queen::~Queen ()
{
	//blank
}

//Checks move is valid according to position's standard chess rules

bool Queen::valid_move (const char* start, const char* end, bool t)
{
	//Straight along column is valid
	if (start[0] == end[0])
		return true;
		
	//Straight along row is valid
	if (start[1] == end[1])
		return true;
	
	//Set i to be at start
	char i[3];
	i[0] = start[0];
	i[1] = start[1];
	i[2] = '\0';
	
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
	
	//Default case: not valid move
	return false;
}

