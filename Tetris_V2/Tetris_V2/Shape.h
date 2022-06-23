#pragma once
#include "Block.h"
#include <vector>

class Shape {

public:
     
	virtual void make_block() = 0;
	virtual void fall_down() = 0;
	virtual void move_left() = 0;
	virtual void move_right() = 0;
	virtual std::vector<Block> get_shape() = 0;
};