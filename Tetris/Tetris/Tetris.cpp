#include <iostream>
#include <vector>
#include <fcntl.h>
#include <io.h>
#include <chrono>
#include <thread>
#include <windows.h>
#include "Menu.h"
#include "Board.h"
#include "Tetris_Pieces.h"

using namespace std;


int main()
{
	vector<vector<int>> mBoard;
	Single_Piece* klocek = new O_Block();
	Board plansza(mBoard, 1, 1);
	
	
	plansza.fill_up_vector();

	Single_Piece* klocekbb = plansza.spawn_block();

	cout << klocekbb->get_shape()[1].x;
	while (1)
	{
         plansza.draw_board();
		 plansza.spawn_block();
		 klocekbb->fall_down();
		 Sleep(1000);
		 system("cls");
	}
	
	



}
