#pragma once
#include <string>
#include <iostream>

enum class MagicStone_Level
{
	PRIMARY_LEVEL,
	MIDDLE_LEVEL,
	ADVANCED_LEVEL,
	MAGIC_STONE_COUNT
};

//灵石类
class MagicStone
{
public:
	//灵石类的构造函数
	MagicStone(int count = 0, MagicStone_Level level = MagicStone_Level::PRIMARY_LEVEL);
	//获取字符串信息
	std::string str() const;
	//重载"<<"运算符,方便输出信息
	friend std::ostream& operator<<(std::ostream& os, const MagicStone& stone);
	MagicStone operator+(MagicStone other);
private:
	//灵石数量
	int count;
	//灵石等级
	MagicStone_Level level;
};

std::ostream& operator<<(std::ostream& os, const MagicStone& stone);
