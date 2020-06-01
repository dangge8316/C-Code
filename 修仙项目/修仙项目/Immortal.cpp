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

//�ڿ�
void Immortal::mining()
{
	//����һ����ʯ�����,��ӵ�������
	stones.push_back(MagicStone(100, MagicStone_Level::PRIMARY_LEVEL));
}

////ȥ�г�������������
bool Immortal::trade()
{
	//����ǰ���ж������Ƿ���,�����ֱ�ӷ���false
	if (!isAlive)
	{
		return false;
	}

	//ѭ��������������,�����ۺϵĳ�����ʯ�����
	MagicStone stone;
	for (int i = 0; i < monsters.size(); i++)
	{
		stone = stone + monsters[i].getValue();
	}
	//�����������ʯ������
	stones.push_back(stone);

	//�������������
	monsters.erase(monsters.begin(), monsters.end());
	return true;
}

bool Immortal::trade(const Monster& monster)
{
	//����ǰ���ж������Ƿ���,�����ֱ�ӷ���false
	if (!isAlive)
	{
		return false;
	}
	//�ж��Ƿ���ָ������
	if (!hadMonster(monster))
	{
		std::cout << "����ʧ��,δ�ҵ�ָ������!" << std::endl;
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
	std::cout << "ɾ��ʧ��,δ�ҵ�ָ������" << std::endl;
	return false;
}

std::ostream& operator<<(std::ostream& os, const Immortal& user)
{
	os << "������:" << user.name << "\t" << (user.isAlive ? "����" : "����") << "\t����:" << user.menPai << "\t���ɵȼ�:" << user.level; 
	MagicStone stone;
	for (int i = 0; i < user.stones.size(); i++)
	{
		stone = stone + user.stones[i];
	}
	os << "\t��ʯ�ʲ�:�ۺ�" << stone<<"\t�����ʲ�:";
	if (user.monsters.size() == 0)
	{
		os << "��";
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

// ���������ڣ� ������, �ᵤ�ڣ�ԪӤ�ڣ� �����ڣ������ڣ������ڣ�����ڣ��ɽ��ڣ�
std::ostream& operator<<(std::ostream& os, const ImmortalLevel level)
{
	switch (level)
	{
	case ImmortalLevel::LIAN_QI:
		os << "������";
		break;
	case ImmortalLevel::ZHU_JI:
		os << "������";
		break;
	case ImmortalLevel::JIE_DAN:
		os << "�ᵤ��";
		break;
	case ImmortalLevel::YUAN_YING:
		os << "ԪӤ��";
		break;
	case ImmortalLevel::HUA_SHEN:
		os << "������";
		break;
	case ImmortalLevel::LIAN_XU:
		os << "������";
		break;
	case ImmortalLevel::HE_TI:
		os << "������";
		break;
	case ImmortalLevel::DA_CHENG:
		os << "�����";
		break;
	case ImmortalLevel::DU_JIE:
		os << "�ɽ���";
		break;
	default:
		break;
	}
	return os;
}
