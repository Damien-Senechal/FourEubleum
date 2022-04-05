#pragma once
#include "Item.h"

class Potion : public Item
{
private:
	int hp;
public:
	Potion();

	inline const int& getHp() const { return this->hp; }

	void setHp(int h) { this->hp = h; }
};

