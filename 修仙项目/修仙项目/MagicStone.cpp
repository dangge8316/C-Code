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

//"<<"���������
std::ostream& operator<<(std::ostream& os, const MagicStone& stone)
{
	os << stone.str();
	return os;
}
