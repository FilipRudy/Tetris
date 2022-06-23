#pragma once

class Block {
	int x;
	int y;
public:

	Block(int x, int y) : x(x), y(y) {

	}

	void update_y(int val) {
		y += val;
	}

	void update_x(int val) {
		x += val;
	}

	int get_x() {

		return x;
	}

	int get_y() {

		return y;
	}
};