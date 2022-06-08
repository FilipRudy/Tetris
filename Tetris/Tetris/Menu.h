#pragma once
#include <vector>
#include <iostream>
#include <chrono>
#include <fstream>   
#include <sstream>
#include <random>
#include <string>

using namespace std;

class Menu {

	string highscores;

public:

	void show_highscores();
	void start_game();
	void exit_program();

};
