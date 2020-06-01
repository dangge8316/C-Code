#pragma once
#include <string>
#include <vector>
#include <iostream>

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
};

//修仙者类
class Immortal {
public:
	//构造函数
	Immortal(std::string name,std::string menpai,ImmortalLevel level);
	//挖矿
	void mining();

	//去市场售卖所有妖兽
	bool trade();
	
	//去市场售卖指定妖兽
	bool trade(const Monster& monster);
	
	//用灵石购买其他修仙者的妖兽
	bool trade(Immortal& other, const Monster& monster);
	
	//用自己指定的妖兽和其他修仙者交换指定妖兽
	bool trade(const Monster& monsterSource, Immortal& other, const Monster& monsterAim);
	
	//把自己的妖兽卖给其他修仙者换取灵石
	bool trade(const Monster& monsterSource, Immortal& other);
	
	//获取战斗力数值
	int getPower() const;
	
	//捕获妖兽
	bool captureMonster();

	friend std::ostream& operator<<(std::ostream& os, const Immortal& user);
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
	std::vector<Monster> monsters;
	//是否活着
	bool isAlive;

};

std::ostream& operator<<(std::ostream& os, const Immortal& user);
std::ostream& operator<<(std::ostream& os, const ImmortalLevel level);