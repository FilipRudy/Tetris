#pragma once
#include "Shape.h"
#include <iostream>
#include <vector>

class Shape_S : public Shape {

	std::vector<Block> block_shape;

public:

	void make_block() {

		Block block1(3, 1);
		Block block2(4, 1);
		Block block3(4, 0);
		Block block4(5, 0);

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
