#include "Menu.h"
#include "Single_Piece.h"
#pragma once




class O_Block : public Single_Piece
{
	vector<coordinates> shape;


public:
	O_Block(){
		coordinates c(0, 0);
		shape.push_back(c);
		coordinates d(1, 0);
		shape.push_back(d);
		coordinates f(0, 1);
		shape.push_back(f);
		coordinates g(1, 1);
		shape.push_back(g);
	}

	vector<coordinates> get_shape() {
		return shape;
	};

    void fall_down() {

		
			for (int i = 0; i < 4; i++)
			{
				shape[0].y ++;
				shape[1].y ++;
				shape[2].y ++;
				shape[3].y ++;
			}
		
	}

	void rotate_left() {

	}

	void can_be_rotated() {

	}

	bool place_block() {


		return true;
	}
};
