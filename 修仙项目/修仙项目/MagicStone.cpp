#include <sstream>
#include "MagicStone.h"

//构造函数
MagicStone::MagicStone(int count, MagicStone_Level level)
{
	this->count = count;
	this->level = level;
}

//返回灵石信息字符串
std::string MagicStone::str() const
{
	std::stringstream ret;
	ret << count << "块";
	switch (level)
	{
	case MagicStone_Level::PRIMARY_LEVEL:
		ret << "初阶灵石";
		break;
	case MagicStone_Level::MIDDLE_LEVEL:
		ret << "中阶灵石";
		break;
	case MagicStone_Level::ADVANCED_LEVEL:
		ret << "高阶灵石";
		break;
	default:
		ret << "未知灵石";
	}
	return ret.str();
}

//"<<"运算符重载
std::ostream& operator<<(std::ostream& os, const MagicStone& stone)
{
	os << stone.str();
	return os;
}
