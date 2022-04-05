#pragma once
#include"Character.h"
class Enemy
{
private:
	string name;
	int health;
	int attack;
	int defense;
public:
	Enemy();
	Enemy(string n, int h, int a, int d);

	inline const string& getName() const { return this->name; }
	inline const int& getHealth() const { return this->health; }
	inline const int& getAttack() const { return this->attack; }
	inline const int& getDefense() const { return this->defense; }

	void setName(string n) { this->name = n; }
	void setHealth(int h) { this->health = h; }
	void setAttack(int a) { this->attack = a; }
	void setDefense(int d) { this->defense = d; }
};

