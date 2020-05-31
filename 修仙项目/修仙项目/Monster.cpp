#include <iostream>
#include <sstream>
#include "Monster.h"
#include "MagicStone.h"

//���캯��
Monster::Monster(int level, std::string category)
{
	this->level = level;
	this->category = category;
}

//��ȡ��ͬ�ȼ����޼�ֵ����ʯ��,����һ����ʯ�����
MagicStone Monster::getValue(int level)
{
	//����һ�������ʾ��ͬ�ȼ������޶�Ӧ��ʯ��ֵ
	int value[]{ 100,200,500,1000,2000,5000,10000,20000,100000 };
	int stoneValue = value[level - 1];
	//����һ����ʯ��,���ù��캯��������Ӧ����
	MagicStone stone(stoneValue, MagicStone_Level::PRIMARY_LEVEL);
	return stone;
}

//��������غ���
std::ostream& operator<<(std::ostream& os, Monster& monster)
{
	os << monster.level << "��" << monster.category << "�����޼�ֵ" << monster.getValue(monster.level);
	return os;
}
