#pragma once
#include <string>
#include <vector>
#include <iostream>

class MagicStone;
class Monster;

// ���������ڣ� ������, �ᵤ�ڣ�ԪӤ�ڣ� �����ڣ�
//       �����ڣ������ڣ�����ڣ��ɽ��ڣ�
enum class ImmortalLevel
{
	LIAN_QI,
	ZHU_JI,
	JIE_DAN,
	YUAN_YING,
	HUA_SHEN,
	LIAN_XU,
	HE_TI,
	DA_CHENG,
	DU_JIE,
	LEVEL_COUNT
};

//��������
class Immortal {
public:
	//���캯��
	Immortal(std::string name,std::string menpai,ImmortalLevel level);
	//�ڿ�
	void mining();

	//ȥ�г�������������
	bool trade();
	
	//ȥ�г�����ָ������
	bool trade(const Monster& monster);
	
	//����ʯ�������������ߵ�����
	bool trade(Immortal& other, const Monster& monster);
	
	//���Լ�ָ�������޺����������߽���ָ������
	bool trade(const Monster& monsterSource, Immortal& other, const Monster& monsterAim);
	
	//���Լ��������������������߻�ȡ��ʯ
	bool trade(const Monster& monsterSource, Immortal& other);
	
	//��ȡս������ֵ
	int getPower() const;
	
	//��������
	bool captureMonster();

	friend std::ostream& operator<<(std::ostream& os, const Immortal& user);
private:
	//����
	std::string name;
	//����
	std::string menPai;
	//�����ߵȼ�
	ImmortalLevel level;
	//��ʯ�ʲ�
	std::vector<MagicStone> stones;
	//�����ʲ�
	std::vector<Monster> monsters;
	//�Ƿ����
	bool isAlive;

};

std::ostream& operator<<(std::ostream& os, const Immortal& user);
std::ostream& operator<<(std::ostream& os, const ImmortalLevel level);