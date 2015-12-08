/*---------------------------------------------------------
Last Edited: 26th November 2015
Author: Henry Williams, hw5115, 01141713
Description: Bishop Class
---------------------------------------------------------*/

#include <iostream>

using namespace std;

#include "Bishop.h"
#include "Piece.h"

//Constructor

Bishop::Bishop (bool white_color) : Piece (white_color)
{
	type = bishop;
}

Bishop::~Bishop ()
{
	//blank
}

bool Bishop::valid_move (const char* start, const char* end, bool taking)
{
	char i[3];
	i[0] = start[0];
	i[1] = start[1];
	i[2] = '\0';

	
	//Diagonal "up" right
	if (start[0] < end[0] && start[1] < end[1])
	{
		while (i[0] <= 'H' && i[1] <= '8')
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
		while (i[0] >= 'A' && i[1] <= '8')
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
		while (i[0] >= 'A' && i[1] >= '1')
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
		while (i[0] <= 'H' && i[1] >= '1')
		{
			i[0]++;
			i[1]--;
			if (i[0] == end[0] && i[1] == end[1])
				return true;
		}
	}
	return false;
}

