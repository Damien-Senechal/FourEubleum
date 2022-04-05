#pragma once
#include "Lib.h"

using namespace std;
class Point
{
protected:
	int posX;
	int posY;
	char val;
	bool cursorOn;
	bool bomb;

public:
	//Constructeurs
	Point();
	Point(int x, int y, char v, bool c);

	//Getters
	inline const int& getPosX() const { return this->posX; }
	inline const int& getPosY() const { return this->posY; }
	inline const char& getVal() const { return this->val; }
	inline const bool& getCursorOn() const { return this->cursorOn; }
	inline const bool& getEnemy() const { return this->bomb; }

	//Setters
	void setPosX(int x) { this->posX = x; }
	void setPosY(int y) { this->posY = y; }
	void setVal(char v) { this->val = v; }
	void setCursorOn(bool c) { this->cursorOn = c; }
	void setEnemy(bool b) { this->bomb = b; }


	//Methods
	friend ostream& operator<<(ostream& os, Point const& p);
};

