#pragma once
#include "Shape.h"
#include "Shape_O.h"
#include "Shape_T.h"
#include <conio.h>
#include <iostream>
#include <vector>
#include <Windows.h>

class Board {

	std::vector<std::vector<int>> game_board;
	Shape* shape;

public:

	void fill_up_board() {
		for (int i = 0; i < 24; i++)
		{
			std::vector<int> v;
			for (int j = 0; j < 10; j++)
			{
				v.push_back(0);
			}
			game_board.push_back(v);
		}
	}

	void randomise_shape() {

	    shape = new Shape_T();

	}

	void display_board() {

		for (int i = 0; i < 24; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				std::cout << game_board[i][j];
			}
			std::cout << std::endl;
		}
	}

	void add_shape() {

		std::vector<Block> v = shape->get_shape();
		
		for (Block c : v) {
			
			int x = c.get_x();
			int y = c.get_y();
			game_board[y][x] = 1;
		}
	}

	void remove_shape() {

		std::vector<Block> v = shape->get_shape();

		for (Block c : v) {

			int x = c.get_x();
			int y = c.get_y();
			game_board[y][x] = 0;
		}

	}

	void game() {

		fill_up_board();
		randomise_shape();
		shape->make_block();

		while (1) {

			add_shape();
			display_board();
			remove_shape();
			if (_kbhit())
			{
				char sign = _getch();
				if (sign == 'a')
				{
					shape->move_left();
				}
				else if (sign == 'd')
				{
					shape->move_right();
				}
				else if (sign == 'q')
				{
					shape->rotate_left();
				}
				else if (sign == 'e')
				{
					shape->rotate_right();
				}

			}
			shape->fall_down();
			Sleep(200);
            system("CLS");
		}
	}

	bool validate_rot_left() {



	}

	bool validate_rot_right() {


	}

	bool validate_move_left() {


	}

	bool validate_move_right() {


	}
};