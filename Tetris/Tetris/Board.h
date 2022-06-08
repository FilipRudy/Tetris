#pragma once
#include "Menu.h"
#include "Tetris_Pieces.h"
class Board {

	int width = 10;
	int height = 24;
    vector<vector<int>> game_board;

public:
	Board(vector<vector<int>> game_board, int width, int height) : game_board(game_board), width(width), height(height) {

	}

	void fill_up_vector()
	{
		for (int i = 0; i < 24; i++)
		{
			vector<int> v;
			for (int j = 0; j < 10; j++)
			{
				v.push_back(0);
			}
			game_board.push_back(v);
		}
	}

    void draw_board()
	{
		for (int i = 0; i < 24; i++)
		{
			for (int j = 0; j < 10; j++)
			{
                cout << game_board[i][j]<<" ";
			}
			cout << endl;
		}
		cout << endl;
	}
	

	Single_Piece* spawn_block()
	{

		Single_Piece* kloceki = new O_Block();

		
			return kloceki;
	}

	void clear_row()
	{

	}

	void pause_game()
	{

	}

	void increase_score()
	{

	}

    void end_game()
	{

	}

	vector<vector<int>> get_gameboard() {
		return game_board;
	};
	
};