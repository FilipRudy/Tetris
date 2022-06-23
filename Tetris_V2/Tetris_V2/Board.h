#pragma once
#include "Shape.h"
#include "Shape_O.h"
#include "Shape_T.h"
#include "Shape_I.h"
#include "Shape_J.h"
#include "Shape_S.h"
#include "Shape_Z.h"
#include "Shape_L.h"
#include <conio.h>
#include <iostream>
#include <vector>
#include <Windows.h>
#include <cstdlib>


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


	void clear_row() {

		std::vector<int> v;
		for (int c = 0; c < 10; c++)
		{
			v.push_back(0);
		}

		for (int i = 0; i < 24; i++)
		{
			int checking = 0;
			for (int j = 0; j < 10; j++)
			{
				
				if (game_board[i][j] == 2)
				{

					checking++;
				}
			}
			if (checking == 10)
			{
				game_board.erase(game_board.begin() + i);
				game_board.insert(game_board.begin(), v);
				

			}
		}
	}

	void randomise_shape() {

        srand(time(NULL));
		int shape_type = rand() % 7 + 1;

		switch (shape_type) {

		case 1:
		{
			shape = new Shape_J();
		}
		break;
		case 2:
		{
			shape = new Shape_L();
		}
		break;
		case 3:
		{
			shape = new Shape_Z();
		}
		break;
		case 4:
		{
			shape = new Shape_S();
		}
		break;
		case 5:
		{
			shape = new Shape_O();
		}
		break;
		case 6:
		{
			shape = new Shape_I();
		}
		break;
		case 7:
		{
			shape = new Shape_T();
		}
		break;

		}
	    

	}

	void display_board() {

		for (int i = 0; i < 24; i++)
		{
			std::cout << "                                                     ";
			for (int j = 0; j < 10; j++)
			{
				std::cout <<game_board[i][j];
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

	void set_shape() {

		std::vector<Block> v = shape->get_shape();

		for (Block c : v) {
			int x = c.get_x();
			int y = c.get_y();
			game_board[y][x] = 2;
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
					
					if (validate_move_left() == true) {
                       shape->move_left();
					}
					
				}
				else if (sign == 'd')
				{
					if (validate_move_right() == true) {
						shape->move_right();
					}

				}

			}
			if (validate_fall_down())
			{
				shape->fall_down();
			}
			else
			{
			  set_shape();
			  if (validate_game_end() == false)
			  {
				  break;
				  
			  }
			  clear_row();
			  randomise_shape();
			  shape->make_block();
			}
				
			
			Sleep(200);
            system("CLS");
		}
	}


	bool validate_game_end() {

		for (int i = 0; i < 10; i++)
		{
			if (game_board[0][i] == 2)
			{
				return false;
			}
		}

		return true;
	}

	bool validate_fall_down() {

		std::vector<Block> v = shape->get_shape();
		for (Block c : v) {
			
			if (c.get_y() >= 23 || game_board[c.get_y()+1][c.get_x()] == 2)
			{
				return false;
			}
		}
		return true;

	}

	bool validate_move_left() {
		
		std::vector<Block> v = shape->get_shape();

		for (Block c : v) {

			if (c.get_x() <= 0 || game_board[c.get_y() ][c.get_x()- 1] == 2)
			{
				return false;
			}
		}
		return true;

	}

	bool validate_move_right() {

		std::vector<Block> v = shape->get_shape();

		for (Block c : v) {

			if (c.get_x() >= 9 || game_board[c.get_y()][c.get_x() + 1] == 2)
			{
				return false;
			}
		}
		return true;

	}
};