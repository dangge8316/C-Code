#pragma once
#include <string>
#include <vectro>

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
}

//��������
class Immortal {
public:
	Immortal(std::string name,std::string menpai,ImmortalLevel level);
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
	std::vectro<Monster> monsters;
	//�Ƿ����
	bool isAlive;

};