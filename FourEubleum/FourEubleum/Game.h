#pragma once
#include "Lib.h"
#include "GameState.h"
#include "Grid.h"
#include "Enemy.h"


class GameState;

class Game
{
private:
	GameState* currentState;
	int actualLevel;
	Character player;
	Enemy enemy;
	string stateName;

public:
	Game();
	
	void execute();
	void setExploration();
	void setState(GameState& newState);
	bool finish();

	void Battle(Character& p);

	inline GameState* getCurrentState() const { return currentState; }
	string getStateName();
	inline const int& getActualLevel() const { return this->actualLevel; }

	void setActualLevel(int x) { this->actualLevel = x; }
};
