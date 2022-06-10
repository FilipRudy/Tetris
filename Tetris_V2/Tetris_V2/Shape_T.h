#pragma once
#include "Shape.h"
#include <iostream>
#include <vector>

class Shape_T : public Shape {

	std::vector<Block> block_shape;

public:

	void make_block() {

		Block block1(4, 0);
		Block block2(5, 0);
		Block block3(6, 0);
		Block block4(5, 1);

		block_shape.push_back(block1);
		block_shape.push_back(block2);
		block_shape.push_back(block3);
		block_shape.push_back(block4);
	}

	void fall_down() {

		for (Block& v : block_shape)
		{
			v.update_y(1);
		}
	}

	void rotate_left() {

		block_shape[0].update_y(2);
		block_shape[1].update_x(-1);
		block_shape[1].update_y(1);
		block_shape[2].update_x(-2);
	}

	void rotate_right() {


	}

	void move_left() {

		for (Block& v : block_shape)
		{
			v.update_x(-1);
		}

	}

	void move_right() {

		for (Block& v : block_shape)
		{
			v.update_x(1);
		}

	}

	std::vector<Block> get_shape() {

		return block_shape;
	}

};