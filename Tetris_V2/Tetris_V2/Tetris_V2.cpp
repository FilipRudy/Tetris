#include <iostream>
#include "Board.h"

int main()
{
    Board p;

    p.game();

    std::cout <<std::endl<< "                                                Game ended, you lost!";
    return 0;
}
