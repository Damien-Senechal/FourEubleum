#pragma once
#include "Lib.h"

class Item
{
private:
	string name;
public:
	Item();
	Item(string n);
	~Item(){}

	virtual inline const string& getName() const { return this->name; }
	virtual void setName(string n) { this->name = n; }
};

