#include <sstream>
#include "MagicStone.h"

//���캯��
MagicStone::MagicStone(int count, MagicStone_Level level)
{
	this->count = count;
	this->level = level;
}

//������ʯ��Ϣ�ַ���
std::string MagicStone::str() const
{
	std::stringstream ret;
	ret << count << "��";
	switch (level)
	{
	case MagicStone_Level::PRIMARY_LEVEL:
		ret << "������ʯ";
		break;
	case MagicStone_Level::MIDDLE_LEVEL:
		ret << "�н���ʯ";
		break;
	case MagicStone_Level::ADVANCED_LEVEL:
		ret << "�߽���ʯ";
		break;
	default:
		ret << "δ֪��ʯ";
	}
	return ret.str();
}

//��ʯ��"+"���������
MagicStone MagicStone::operator+(MagicStone other)
{
	//����num����ͳ���ܹ��ж��ٿ������ʯ
	int num{ };

	//�ȼ����Ҫ��ӵ���ʯ�����ۺ϶��ٳ�����ʯ
	if (other.level == MagicStone_Level::PRIMARY_LEVEL)
	{
		num += other.count;
	}
	else if (other.level==MagicStone_Level::MIDDLE_LEVEL)
	{
		num += other.count * 10;
	}
	else if(other.level==MagicStone_Level::ADVANCED_LEVEL)
	{
		num += other.count * 100;
	}
	
	//�����Լ�����ʯ�ۺ϶��ٳ�����ʯ
	if (this->level == MagicStone_Level::PRIMARY_LEVEL)
	{
		num += this->count;
	}
	else if (this->level == MagicStone_Level::MIDDLE_LEVEL)
	{
		num += this->count * 10;
	}
	else if (this->level == MagicStone_Level::ADVANCED_LEVEL)
	{
		num += this->count * 100;
	}
	
	return MagicStone(num, MagicStone_Level::PRIMARY_LEVEL);
}

//"<<"���������
std::ostream& operator<<(std::ostream& os, const MagicStone& stone)
{
	os << stone.str();
	return os;
}
