#include "Character.h"

Character::Character()
{
	setName("None");
	setHealth(100);
	setAttack(10);
	setDefense(5);
	setInventory(vector<Item>());
}

Character::Character(string n)
{
	setName(n);
	setHealth(100);
	setAttack(10);
	setDefense(5);
	setInventory(vector<Item>());
	Potion p = Potion();
	addItem(p);
}

void Character::addItem(Item a)
{
	this->inventory.push_back(a);
}

void Character::removeItem(Item a)
{
	for (size_t i = 0; i < getInventory().size(); i++)
	{
		if (getInventory()[i].getName() == a.getName()) {
			this->inventory.erase(this->inventory.begin()+i);
		}
	}
}
