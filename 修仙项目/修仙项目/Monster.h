#pragma once
#include <string>
#include <iostream>
#include "MagicStone.h"

//妖兽类
class Monster
{
public:
	//构造函数
	Monster(int level = 1, std::string category = "未知种类");
	//获取妖兽价值(多少灵石)
	MagicStone getValue();
	//运算符重载
	friend std::ostream& operator<<(std::ostream& os, Monster& monster);
private:
	//妖兽等级
	int level;
	//妖兽种类
	std::string category;
};

std::ostream& operator<<(std::ostream& os, Monster& monster);