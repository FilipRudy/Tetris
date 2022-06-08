#include <vector>
//#include "Tetris_Pieces.h"
#pragma once


struct coordinates
{
	int x;
	int y;
	coordinates(int x, int y) : x(x), y(y) {

	}
};

class Single_Piece{

	public:
		void rotate_right() {


		};
		virtual void rotate_left() = 0;
		virtual void fall_down() = 0;
		virtual void can_be_rotated() = 0;
		virtual bool place_block() = 0;
		virtual vector<coordinates> get_shape() = 0;
};

