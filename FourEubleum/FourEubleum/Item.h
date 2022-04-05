#pragma once
#include "Lib.h"

class Item
{
private:
	string name;
public:
	Item();
	Item(string n);

	virtual inline const string& getName() const { return name; }
	virtual void setName(string n) { this->name = n; }
};

