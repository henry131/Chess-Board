/*---------------------------------------------------------
Last Edited: 26th November 2015
Author: Henry Williams, hw5115, 01141713
Description: ChessBoard Class
---------------------------------------------------------*/

#include <iostream>
#include <cstring>
#include <map>

#include "Piece.h"
#include "Pawn.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Castle.h"


using namespace std;

#include "ChessBoard.h"

//Constructor

ChessBoard::ChessBoard ()
{
	configure ();
}

//Destructor: default

ChessBoard::~ChessBoard ()
{
	delete_pieces();
}

//Delete Pieces

void ChessBoard::delete_pieces ()
{
	//delete memory and clear board
	for (it_type iter = board.begin(); iter != board.end(); iter++)
	{
				delete iter->second;
	}
}


//Reset Board

void ChessBoard::resetBoard ()
{
	//Delete the board contents 
	delete_pieces();
	//Remove all destroyed elements from map container
	board.clear();
	//Reconfigure board
	configure();
}

//Configure
void ChessBoard::configure ()
{
	char i[3];
	i[2] = '\0';

	//white pieces (true means white)
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

	//black pieces (false)
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

//Check Move

bool ChessBoard::validate_move (const char* start, const char* end, bool t)
{
	//Check square inputs are different
	if (start[0] == end[0] && start[1] == end[1])
		return false;

	//Check if attempting to take own piece
	if (t)
		if ((board[start]->get_white_color() && board[end]->get_white_color())
		 || (!board[start]->get_white_color() && !board[end]->get_white_color()))
			return false;
	
	//Validate movement type at Piece level
	if (!board[start]->valid_move(start,end,t))
		return false;
	
	//Check obstacle
	if (board[start]->get_type() != "Knight") 
		if (!check_obstacles(start,end))
			return false;
			
	//If passes checks, move is validated (for these checks)
	return true;
}

//Submit Move

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

	//Would move result in current player's King being in check - invalid
	if(valid_move)
	{
		Piece* temp = board[end];
		board[end] = board[start];
		board[start] = NULL;
		
		//Find the King on the "updated" board
		king = find_king(white_turn).c_str();
		
		//Does the "updated" board put the king in check
		if (king_in_check(white_turn, king))
			valid_move = false;
			
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
	
	//If not a valid move, exit here
	if (!valid_move)
		return;
	
	//Make move: if taking, delete 
	if (is_taking)
	{
		 delete board[end];
	}
	board[end] = board[start];
	board[start] = NULL;
	
	//If first move, change it (for Pawn 2 vs 1 squares)
	if (board[end]->check_first_move())
		board[end]->not_first_move();
	
	//change turn and reset is_taking to default
	change_turn();
	is_taking = false;

	//check if other player in check or check/stale mate (if so, end game)
	//if check

	king = find_king(white_turn).c_str();

	if (king_in_check(white_turn, king))
	{
		if (white_turn)
			cout << "White";
		else
			cout << "Black";
		cout << " is in check";
		if (stalemate(white_turn, king))
		{
			cout << "mate";
			game_over = true;
		}
		cout << endl;
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

string ChessBoard::find_king (bool white)
{
	for (it_type iter2 = board.begin(); iter2 != board.end(); iter2++)
	{
		if (iter2->second != NULL && iter2->second->get_white_color() == white && iter2->second->get_type() == "King")
		{
			return iter2->first;
		}
	}
	return "a"; //Error
}


bool ChessBoard::king_in_check (bool white, const char* king)
{
	const char* start;
	const char* end = king;
	bool is_taking = true;
	
	//Defensive error check
	if (end[0] == 'a')
		return false;

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
	
	return false;
}

bool ChessBoard::stalemate (bool white, const char* k)
{
	const char* start;
	const char* end;
	const char* king = k;
	bool is_taking = false;
	bool stalemate = true;
	Piece *temp2 = NULL;
	
	for (it_type iter4 = board.begin(); iter4 != board.end(); iter4++)
	{
		if (iter4->second != NULL && iter4->second->get_white_color() == white)
		{
			start = iter4->first.c_str();
			for (it_type iter5 = board.begin(); iter5 != board.end(); iter5++)
			{
				is_taking = false;
				end = iter5->first.c_str();
				if (iter5->second != NULL)
				{
					is_taking = true;
				}
				if (validate_move(start,end,is_taking))
				{
					temp2 = board[end];
					board[end] = board[start];
					board[start] = NULL;
					if (board[end]->get_type() == "King")
						king = end;
					else
						king = k;
					if (!king_in_check(white, king))
					{
						stalemate = false;
					}
					board[start] = board[end];
					board[end] = temp2;
				}
				if (stalemate == false)
				{
					return false;
				}
			}
		}
	}
	return stalemate;
}

void ChessBoard::change_turn ()
{
	(white_turn) ? white_turn = false : white_turn = true;
}


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



