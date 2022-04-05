#include "Enemy.h"

Enemy::Enemy()
{
	setName("None");
	setHealth(20);
	setAttack(2);
	setDefense(1);
}

Enemy::Enemy(string n, int h, int a, int d)
{
	setName(n);
	setHealth(h);
	setAttack(a);
	setDefense(d);
}
