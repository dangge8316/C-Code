#include <iostream>
#include "Immortal.h"
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

void testImmortal()
{
    Immortal dangge("小天天", "黑兔", ImmortalLevel::DA_CHENG);
    std::cout << dangge << std::endl;
    for (int i = 0; i < 50; i++)
    {
        dangge.mining();
    }
    std::cout << dangge << std::endl;
}

int main()
{
    testMagicStone();
    testMonster();
    testImmortal();
}
