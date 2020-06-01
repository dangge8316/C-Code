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

//��ʯ��
class MagicStone
{
public:
	//��ʯ��Ĺ��캯��
	MagicStone(int count = 0, MagicStone_Level level = MagicStone_Level::PRIMARY_LEVEL);
	//��ȡ�ַ�����Ϣ
	std::string str() const;
	//����"<<"�����,���������Ϣ
	friend std::ostream& operator<<(std::ostream& os, const MagicStone& stone);
	MagicStone operator+(MagicStone other);
private:
	//��ʯ����
	int count;
	//��ʯ�ȼ�
	MagicStone_Level level;
};

std::ostream& operator<<(std::ostream& os, const MagicStone& stone);
