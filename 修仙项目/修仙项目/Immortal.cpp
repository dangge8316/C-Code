#include <vector>
#include "Immortal.h"
#include "MagicStone.h"
#include "Monster.h"

Immortal::Immortal(std::string name, std::string menpai, ImmortalLevel level)
{
	this->name = name;
	this->menPai = menpai;
	this->level = level;
	this->isAlive = true;
}

//挖矿
void Immortal::mining()
{
	//创建一个灵石类对象,添加到容器中
	stones.push_back(MagicStone(100, MagicStone_Level::PRIMARY_LEVEL));
}

////去市场售卖所有妖兽
bool Immortal::trade()
{
	//交易前先判断人物是否存活,如果否直接返回false
	if (!isAlive)
	{
		return false;
	}

	//循环遍历所有妖兽,并将折合的初阶灵石数相加
	MagicStone stone;
	for (int i = 0; i < monsters.size(); i++)
	{
		stone = stone + monsters[i].getValue();
	}
	//将结果存入灵石类容器
	stones.push_back(stone);

	//清空妖兽类容器
	monsters.erase(monsters.begin(), monsters.end());
	return true;
}

bool Immortal::trade(const Monster& monster)
{
	//交易前先判断人物是否存活,如果否直接返回false
	if (!isAlive)
	{
		return false;
	}
	//判断是否有指定妖兽
	if (!hadMonster(monster))
	{
		std::cout << "交易失败,未找到指定妖兽!" << std::endl;
		return false;
	}
	MagicStone stone = monster.getValue();
	stones.push_back(stone);
	delMonster(monster);
	return true;
}

bool Immortal::trade(Immortal& other, const Monster& monster)
{
	return false;
}

bool Immortal::trade(const Monster& monsterSource, Immortal& other, const Monster& monsterAim)
{
	return false;
}

bool Immortal::trade(const Monster& monsterSource, Immortal& other)
{
	return false;
}

int Immortal::getPower() const
{
	return 0;
}

bool Immortal::captureMonster()
{
	return false;
}

bool Immortal::hadMonster(const Monster& monster)
{
	for (int i = 0; i < monsters.size(); i++)
	{
		if (monsters[i] == monster)
		{
			return true;
		}
	}
	return false;
}

bool Immortal::delMonster(const Monster& monster)
{
	std::vector<Monster>::iterator it = monsters.begin();
	while (it != monsters.end())
	{
		if (*it == monster)
		{
			it = monsters.erase(it);
			return true;
		}
		else
		{
			it++;
		}
	}
	std::cout << "删除失败,未找到指定妖兽" << std::endl;
	return false;
}

std::ostream& operator<<(std::ostream& os, const Immortal& user)
{
	os << "修仙者:" << user.name << "\t" << (user.isAlive ? "在修" : "已亡") << "\t门派:" << user.menPai << "\t修仙等级:" << user.level; 
	MagicStone stone;
	for (int i = 0; i < user.stones.size(); i++)
	{
		stone = stone + user.stones[i];
	}
	os << "\t灵石资产:折合" << stone<<"\t妖兽资产:";
	if (user.monsters.size() == 0)
	{
		os << "无";
	}
	else
	{
		for (int i = 0; i < user.monsters.size(); i++)
		{
			os << &user.monsters[i] << "  ";
		}
	}
	
	return os;
}

// 级别（练气期， 筑基期, 结丹期，元婴期， 化神期，炼虚期，合体期，大乘期，渡劫期）
std::ostream& operator<<(std::ostream& os, const ImmortalLevel level)
{
	switch (level)
	{
	case ImmortalLevel::LIAN_QI:
		os << "炼气期";
		break;
	case ImmortalLevel::ZHU_JI:
		os << "筑基期";
		break;
	case ImmortalLevel::JIE_DAN:
		os << "结丹期";
		break;
	case ImmortalLevel::YUAN_YING:
		os << "元婴期";
		break;
	case ImmortalLevel::HUA_SHEN:
		os << "化神期";
		break;
	case ImmortalLevel::LIAN_XU:
		os << "炼虚期";
		break;
	case ImmortalLevel::HE_TI:
		os << "合体期";
		break;
	case ImmortalLevel::DA_CHENG:
		os << "大乘期";
		break;
	case ImmortalLevel::DU_JIE:
		os << "渡劫期";
		break;
	default:
		break;
	}
	return os;
}
