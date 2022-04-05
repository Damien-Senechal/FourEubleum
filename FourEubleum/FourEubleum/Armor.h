#pragma once
#include "Item.h"

class Armor : public Item
{
private:
	string name;
	int defense;
	bool isEquipped;
public:
	Armor();
	Armor(string name, int d, bool i);

	inline const string& getName() const { return this->name; }
	inline const int& getDefense() const { return this->defense; }
	inline const bool& getIsEquipped() const { return this->isEquipped; }

	void setName(string n) { this->name = n; }
	void setDefense(int d) { this->defense = d; }
	void setIsEquipped(bool i) { this->isEquipped = i; }
};

