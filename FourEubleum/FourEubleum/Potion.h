#pragma once
#include "Item.h"

class Potion : public Item
{
private:
	string name;
	int hp;
	bool isEquipped;
public:
	inline const string& getName() const { return this->name; }
	inline const int& getHp() const { return this->hp; }
	inline const bool& getIsEquipped() const { return this->isEquipped; }

	void setName(string n) { this->name = n; }
	void setHp(int h) { this->hp = h; }
	void setIsEquipped(bool i) { this->isEquipped = i; }
};

