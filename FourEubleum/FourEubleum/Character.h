#pragma once
#include "Armor.h"
#include "Weapon.h"
#include "Potion.h"

class Character
{
private:
	string name;
	int health;
	int attack;
	int defense;
	vector<Item> inventory;
	Weapon weaponEquipped;
	Armor armorEquipped;

public:
	Character();
	Character(string n);

	inline const string& getName() const { return this->name; }
	inline const int& getHealth() const { return this->health; }
	inline const int& getAttack() const { return this->attack; }
	inline const int& getDefense() const { return this->defense; }
	inline const vector<Item>& getInventory() const { return this->inventory; }
	inline const Weapon& getWeaponEquipped() const { return this->weaponEquipped; }
	inline const Armor& getArmorEquipped() const { return this->armorEquipped; }
	
	void setName(string n) { this->name = n; }
	void setHealth(int h) { this->health = h; }
	void setAttack(int a) { this->attack = a; }
	void setDefense(int d) { this->defense = d; }
	void setInventory(vector<Item> i) { this->inventory = i; }
	void setWeaponEquipped(Weapon w) { this->weaponEquipped = w; }
	void setArmorEquipped(Armor a) { this->armorEquipped = a; }

	void addItem(Item a);
	void removeItem(Item a);
};

