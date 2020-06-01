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
	MagicStone getValue() const;
	//���������
	friend std::ostream& operator<<(std::ostream& os, Monster& monster);
	friend bool operator==(const Monster& one, const Monster& another);
private:
	//���޵ȼ�
	int level;
	//��������
	std::string category;

};

std::ostream& operator<<(std::ostream& os, Monster& monster);
bool operator==(const Monster& one, const Monster& another);