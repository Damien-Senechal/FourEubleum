#include "Point.h"

Point::Point()
{
	setPosX(0);
	setPosY(0);
	setVal(0);
	setCursorOn(false);
	setEnemy(false);
}

Point::Point(int x, int y, char v, bool c)
{
	setPosX(x);
	setPosY(y);
	setVal(v);
	setCursorOn(c);
	setEnemy(false);
}

ostream& operator<<(ostream& os, Point const& p)
{
	HANDLE console;
	console = GetStdHandle(STD_OUTPUT_HANDLE);
	if (p.getCursorOn()) {
		SetConsoleTextAttribute(console, 17);
		return os << "XX";
		//return os << "[" << "O" << "]";
	}
	else if (p.getEnemy()) {
		SetConsoleTextAttribute(console, 204);
		return os << "XX";
		//return os << "[" << "." << "]";
	}
	else if (p.getVal() == 'W') {
		SetConsoleTextAttribute(console, 136);
		return os << "XX";
	}
	else if (p.getVal() == 'D') {
		SetConsoleTextAttribute(console, 170);
		return os << "  ";
	}
	SetConsoleTextAttribute(console, 119);
	return os << "XX";
	//return os << "[" << p.getVal() << "]";
}