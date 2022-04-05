#include "Armor.h"

Armor::Armor()
{
	setName("None");
	setDefense(0);
	setIsEquipped(false);
}

Armor::Armor(string name, int d, bool i)
{
	setName(name);
	setDefense(d);
	setIsEquipped(i);
}
