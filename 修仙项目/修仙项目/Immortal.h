#pragma once
#include <string>
#include <vectro>

class MagicStone;
class Monster;

// 级别（练气期， 筑基期, 结丹期，元婴期， 化神期，
//       炼虚期，合体期，大成期，渡劫期）
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

//修仙者类
class Immortal {
public:
	Immortal(std::string name,std::string menpai,ImmortalLevel level);
private:
	//姓名
	std::string name;
	//门派
	std::string menPai;
	//修仙者等级
	ImmortalLevel level;
	//灵石资产
	std::vector<MagicStone> stones;
	//妖兽资产
	std::vectro<Monster> monsters;
	//是否活着
	bool isAlive;

};