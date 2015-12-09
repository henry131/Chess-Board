/*---------------------------------------------------------
Last Edited: 9th December 2015
Author: Henry Williams, hw5115, 01141713
Description: ChessBoard Class
---------------------------------------------------------*/

#include <iostream>
#include <cstring>
#include <map>

#include "ChessBoard.h"
#include "Piece.h"
#include "Pawn.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Castle.h"

using namespace std;

//Constructor: call private configure function

ChessBoard::ChessBoard ()
{
	configure ();
}

//Destructor: call private delete pieces function (empty heap)

ChessBoard::~ChessBoard ()
{
	delete_pieces();
}

//Delete Pieces, frees the memory on the heap and clears board

void ChessBoard::delete_pieces ()
{
	//Free memory on heap
	for (it_type iter = board.begin(); iter != board.end(); iter++)
	{
				delete iter->second;
	}
	//Remove all destroyed elements from map container
	board.clear();
}


//Resets Board from current to standard starting condition

void ChessBoard::resetBoard ()
{
	//Delete the board contents 
	delete_pieces();
	//Reconfigure board
	configure();
}

//Configures the chess board to standard starting condition
//map board<string,Piece*> holds contents of board
//squares with no pieces on set to NULL

void ChessBoard::configure ()
{
	char i[3];
	i[2] = '\0';

	//white pieces (passing true to constructor means white)
	board["A1"] = new Castle(true);
	board["B1"] = new Knight(true);
	board["C1"] = new Bishop(true);
	board["D1"] = new Queen(true);
	board["E1"] = new King(true);
	board["F1"] = new Bishop(true);
	board["G1"] = new Knight(true);
	board["H1"] = new Castle(true);

	i[1] = '2';
	for (i[0] = 'A'; i[0] < 'I'; i[0]++)
	{
		board[i] = new Pawn(true);
	}

	//black pieces (passing false to constructor)
	board["A8"] = new Castle(false);
	board["B8"] = new Knight(false);
	board["C8"] = new Bishop(false);
	board["D8"] = new Queen(false);
	board["E8"] = new King(false);
	board["F8"] = new Bishop(false);
	board["G8"] = new Knight(false);
	board["H8"] = new Castle(false);
	
	i[1] = '7';
	for (i[0] = 'A'; i[0] < 'I'; i[0]++)
	{
		board[i] = new Pawn(false);
	}
	
	//Set rest of board to NULL
	i[1] = '3';
	for (i[0] = 'A'; i[0] < 'I'; i[0]++)
	{
		for (; i[1] < '7'; i[1]++)
		{
			board[i] = NULL;
		}
	}

	//game is now on
	game_over = false;

	//not yet taking
	is_taking = false;

	//white always starts
	white_turn = true;

	cout << "A new chess game is started!" << endl;
}

//Changes players turn

void ChessBoard::change_turn ()
{
	(white_turn) ? white_turn = false : white_turn = true;
}


//Checks the square input is valid ("A1" to "H8")
//Called in submit_move()

bool ChessBoard::check_squares (const char* square) const
{	
	if (square[2] != '\0')
	{
		cout << "Invalid Input: Incorrect length" << endl;
		return false;
	}

	if (square[0] < 'A' || square[0] > 'H')
	{
		cout << "Invalid Input: Board columns are from A-H" << endl;
		return false;
	}
	
	if (square[1] < '1' || square [1] > '8')
	{
		cout << "Invalid Input: Board rows are from 1-8" << endl;
		return false;
	}
	
	//If passes checks
	return true;
}

//Checks if any pieces between start and end
//Called in validate_move()

bool ChessBoard::check_obstacles (const char* start, const char* end)
{
	char i[3];
	i[2] = '\0';
	
	//Straight along column
	if (start[0] == end[0])
	{
		i[0] = start[0];
		if (start[1] < end[1])
		{
			for (i[1] = start[1]+1; i[1] < end[1]; i[1]++)
			{
				if (board[i]!=NULL)
					return false;
			}
		}
		else
		{
			for (i[1] = start[1]-1; i[1] > end[1]; i[1]--)
			{
				if (board[i]!=NULL)
					return false;
			}
		}
	}
	
	//Straight along row
	if (start[1] == end[1])
	{
		i[1] = start[1];
		if (start[0] < end[0])
		{
			for (i[0] = start[0]+1; i[0] < end[0]; i[0]++)
			{
				if (board[i] != NULL)
					return false;
			}
		}
		else
		{
			for (i[0] = start[0]-1; i[0] > end[0]; i[0]--)
			{
				if (board[i] !=NULL)
					return false;
			}
		}
	}
	
	//Reset i to be at start
	i[0] = start[0]; i[1] = start[1];
	
	//Diagonal "up" right
	if (start[0] < end[0] && start[1] < end[1])
	{
		while (end[0] != i[0])
		{
			i[0]++;
			i[1]++;
			if (i[0] == end[0] && i[1] == end[1])
				break;
			if (board[i] != NULL)
				return false;
		}
	}
	
	//Diagonal "up" left
	if (start[0] > end[0] && start[1] < end[1])
	{
		while (end[0] != i[0])
		{
			i[0]--;
			i[1]++;
			if (i[0] == end[0] && i[1] == end[1])
				break;
			if (board[i] != NULL)
				return false;
		}
	}
	
	//Diagonal "down" left
	if (start[0] > end[0] && start[1] > end[1])
	{
		while (end[0] != i[0])
		{
			--i[0];
			--i[1];
			if (i[0] != end[0] && board[i] != NULL)
				return false;
		}
	}
	
	//Diagonal "down" right
	if (start[0] < end[0] && start[1] > end[1])
	{
		while (end[0] != i[0])
		{
			i[0]++;
			i[1]--;
			if (i[0] == end[0] && i[1] == end[1])
				break;
			if (board[i] != NULL)
				return false;
		}
	}
	
	//If no obstacles return true
	return true;
}

//validation of move incl. conforming to piece movement restrictions

bool ChessBoard::validate_move (const char* start, const char* end, bool t)
{
	//Check square inputs are different
	if (start[0] == end[0] && start[1] == end[1])
		return false;

	//Check if attempting to take own piece
	if (t)
		if ((board[start]->get_white_color() && 
		board[end]->get_white_color())
		|| (!board[start]->get_white_color() &&
		!board[end]->get_white_color()))
			return false;
	
	//Validate movement type at Piece level
	if (!board[start]->valid_move(start,end,t))
		return false;
	
	//Check obstacles
	if (board[start]->get_type() != "Knight") 
		if (!check_obstacles(start,end))
			return false;
			
	//If passes checks, move is validated (for these checks)
	return true;
}

//Will make move from start to end if it is valid based on standard
//rules of chess (excl. castling, en passant & pawn promotion)
//If the move is invalid then an error message will be output
//If the move is successful then the result will be output including
//any pieces being taken and the current check/stale (-mate) status

void ChessBoard::submitMove (const char* start, const char* end)
{
	const char* king;
	
	//Check game still going (no checkmate or stalemate)
	
	if (game_over)
	{
		cout << "Game Over: reset board if you wish to restart" << endl;
		return;
	}	

	//Check valid square inputs (helper function)
	
	if (!check_squares(start) || !check_squares(end))
		return;
	
	//Check there is a piece on start square
	
	if (board[start] == NULL)
	{
		cout << "There is no piece at position " << start << "!" << endl;
		return;
	}
	
	//Check piece in start square is right color (his/her turn)
	
	if (board[start]->get_white_color())
	{
		if (!white_turn)
		{	
			cout << "It is not White's turn to move!" << endl;
			return;
		}	
	}
	else
	{
		if (white_turn)
		{
			cout << "It is not Black's turn to move!" << endl;
			return;
		}
	}

	//Check if attempting to take
	
	bool is_taking = false;
	if (board[end] != NULL)
		is_taking = true;
	
	//Validate move (helper function)
	
	bool valid_move = true;
	valid_move = validate_move (start, end, is_taking);

	//Would move result in player's King being in check - invalid
	if(valid_move)
	{
		//"Update" board to result of move
		Piece* temp = board[end];
		board[end] = board[start];
		board[start] = NULL;
		
		//Find the King on the "updated" board
		king = find_king(white_turn).c_str();
		
		//If "updated" board puts king in check - Invalid move
		if (king_in_check(white_turn, king))
			valid_move = false;

		//Move board back
		board[start] = board[end];
		board[end] = temp;
	}

	//Ouput move or explain that it is not valid
	
	if (board[start]->get_white_color())
		cout << "White";
	else
		cout << "Black";
	cout << "'s " << board[start]->get_type();
	
	if (valid_move)
		cout << " moves from " << start << " to " << end;
	else
		cout << " cannot move to " << end;
		
	if (is_taking && valid_move)
	{
		cout << " taking ";
		if (board[end]->get_white_color())
			cout << "White";
		else
			cout << "Black";
		cout << "'s " << board[end]->get_type();
	}
	cout << endl;
	
	//If not a valid move, exit function here
	if (!valid_move)
		return;
	
	//Make move: if taking, delete Piece. Set start to NULL
	if (is_taking)
	{
		 delete board[end];
	}
	board[end] = board[start];
	board[start] = NULL;
	
	//If Piece's first move, change it (for Pawn 2 vs 1 squares)
	if (board[end]->check_first_move())
		board[end]->not_first_move();

	//change turn and reset is_taking to default false
	change_turn();
	is_taking = false;

	//check if other player in check or check/stale (-mate)
	//game_over = true if either (-mate) satisfied

	king = find_king(white_turn).c_str();

	//check?

	if (king_in_check(white_turn, king))
	{
		if (white_turn)
			cout << "White";
		else
			cout << "Black";
		cout << " is in check";
		
		//check + stalemate? = checkmate
		
		if (stalemate(white_turn, king))
		{
			cout << "mate";
			game_over = true;
		}
		cout << endl;
		
	//No check but stalemate?	
		
	} else if (stalemate(white_turn, king))
	{
		if (white_turn)
			cout << "White";
		else
			cout << "Black";
		cout << " is in stalemate" << endl;
		game_over = true;
	}
}

//Returns square location of king of colour white (true is white)

string ChessBoard::find_king (bool white)
{
	for (it_type iter2 = board.begin(); iter2 != board.end(); iter2++)
	{
		if (iter2->second != NULL && iter2->second->get_white_color() == white && iter2->second->get_type() == "King")
		{
			return iter2->first;
		}
	}
	return "error"; //Error, should never get here
}

//Checks if the king of colour white in position king is in check

bool ChessBoard::king_in_check (bool white, const char* king)
{
	const char* start;
	const char* end = king;
	bool is_taking = true;
	
	//Defensive error check
	if (end[0] == 'e')
		return false;

	//Cycle through board checking if any pieces of opposing colour
	//would be able to make a valid move to the king's square
	
	for (it_type iter3 = board.begin(); iter3 != board.end(); iter3++)
	{
		if (iter3->second != NULL)
		{
			if (iter3->second->get_white_color() != white)
			{
				start = iter3->first.c_str();
				if (start != NULL && end!= NULL)
					if (validate_move (start, end, is_taking))
						return true;
			}		
		}
	}
	
	//Default case, king not in check
	return false;
}

//Checks if any valid move that does not result in king (square k)
//of white colour being in check (irrelevant if king is in check)

bool ChessBoard::stalemate (bool white, const char* k)
{
	const char* start;
	const char* end;
	const char* king = k;
	bool is_taking = false;
	bool stalemate = true;
	Piece *temp2 = NULL;
	
	//Cycle through board
	
	for (it_type iter4 = board.begin(); iter4 != board.end(); iter4++)
	{ 
		
		//Is piece of opposite colour - set as start square
		
		if (iter4->second != NULL && iter4->second->get_white_color() == white)
		{
			start = iter4->first.c_str();
			
			//Cycle through board again - set square as end square
			
			for (it_type iter5=board.begin(); iter5 != board.end(); iter5++)
			{
				is_taking = false;
				end = iter5->first.c_str();
				
				//If end square isnt empty then piece is taking (incl. own)
				
				if (iter5->second != NULL)
				{
					is_taking = true;
				}
				
				//Check if start to end is valid move
				
				if (validate_move(start,end,is_taking))
				{

					//"Update" board to result of move
					
					temp2 = board[end];
					board[end] = board[start];
					board[start] = NULL;
					
					//If  piece that has moved was king, king location is end
					//Otherwise it is as passed as parameter
					
					if (board[end]->get_type() == "King")
						king = end;
					else
						king = k;
					
					//If king not in check in "updated" board
					//Valid move possible -> No stalemate
					
					if (!king_in_check(white, king))
					{
						stalemate = false;
					}
					
					//Move board back
					
					board[start] = board[end];
					board[end] = temp2;
				}
				
				//If a single valid move possible -> no stalemate, exit
				
				if (stalemate == false)
				{
					return false;
				}
				
			}
		}
	}
	
	//Default case: no valid move found -> stalemate
	return stalemate;
}

//Prints (cout) setup of board (for debugging only)

void ChessBoard::print ()
{
	for (it_type iter9 = board.begin(); iter9 != board.end(); iter9++)
	{
		if (iter9->second != NULL)
		{
			if (iter9->second->get_white_color())
				cout << "White ";
			else
				cout << "Black ";
			cout << iter9->second->get_type() << " at " << iter9->first << endl; 
		}
	}
}



