#include <iostream>
#include "MagicStone.h"
#include "Monster.h"

void testMagicStone()
{
    MagicStone stone(100, MagicStone_Level::MIDDLE_LEVEL);
    std::cout << stone << std::endl;
}

void testMonster()
{
    Monster monster(3, "蜘蛛");
    std::cout << monster << std::endl;
}

int main()
{
    testMagicStone();
    testMonster();
}
