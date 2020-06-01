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

//灵石类"+"运算符重载
MagicStone MagicStone::operator+(MagicStone other)
{
	//定义num变量统计总共有多少块初阶灵石
	int num{ };

	//先计算出要相加的灵石对象折合多少初阶灵石
	if (other.level == MagicStone_Level::PRIMARY_LEVEL)
	{
		num += other.count;
	}
	else if (other.level==MagicStone_Level::MIDDLE_LEVEL)
	{
		num += other.count * 10;
	}
	else if(other.level==MagicStone_Level::ADVANCED_LEVEL)
	{
		num += other.count * 100;
	}
	
	//计算自己的灵石折合多少初阶灵石
	if (this->level == MagicStone_Level::PRIMARY_LEVEL)
	{
		num += this->count;
	}
	else if (this->level == MagicStone_Level::MIDDLE_LEVEL)
	{
		num += this->count * 10;
	}
	else if (this->level == MagicStone_Level::ADVANCED_LEVEL)
	{
		num += this->count * 100;
	}
	
	return MagicStone(num, MagicStone_Level::PRIMARY_LEVEL);
}

//"<<"运算符重载
std::ostream& operator<<(std::ostream& os, const MagicStone& stone)
{
	os << stone.str();
	return os;
}
