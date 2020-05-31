#include <iostream>
#include <sstream>
#include "Monster.h"
#include "MagicStone.h"

//构造函数
Monster::Monster(int level, std::string category)
{
	this->level = level;
	this->category = category;
}

//获取不同等级妖兽价值的灵石数,返回一个灵石类对象
MagicStone Monster::getValue(int level)
{
	//定义一个数组表示不同等级的妖兽对应灵石价值
	int value[]{ 100,200,500,1000,2000,5000,10000,20000,100000 };
	int stoneValue = value[level - 1];
	//创建一个灵石类,调用构造函数生成相应数据
	MagicStone stone(stoneValue, MagicStone_Level::PRIMARY_LEVEL);
	return stone;
}

//运算符重载函数
std::ostream& operator<<(std::ostream& os, Monster& monster)
{
	os << monster.level << "级" << monster.category << "类妖兽价值" << monster.getValue(monster.level);
	return os;
}
