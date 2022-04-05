#pragma once
#include "Item.h"

class Weapon : public Item
{
private:
	string name;
	int attack;
	bool isEquipped;
public:
	inline const string& getName() const { return this->name; }
	inline const int& getAttack() const { return this->attack; }
	inline const bool& getIsEquipped() const { return this->isEquipped; }

	void setName(string n) { this->name = n; }
	void setAttack(int a) { this->attack = a; }
	void setIsEquipped(bool i) { this->isEquipped = i; }
};

