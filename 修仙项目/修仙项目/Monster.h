#pragma once
#include <string>
#include <iostream>
#include "MagicStone.h"

//������
class Monster
{
public:
	//���캯��
	Monster(int level = 1, std::string category = "δ֪����");
	//��ȡ���޼�ֵ(������ʯ)
	MagicStone getValue();
	//���������
	friend std::ostream& operator<<(std::ostream& os, Monster& monster);
private:
	//���޵ȼ�
	int level;
	//��������
	std::string category;
};

std::ostream& operator<<(std::ostream& os, Monster& monster);