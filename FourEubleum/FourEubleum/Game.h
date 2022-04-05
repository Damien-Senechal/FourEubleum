#pragma once
#include "Lib.h"
#include "GameState.h"
#include "Grid.h"


class GameState;

class Game
{
private:
	GameState* currentState;
	int actualLevel;

public:
	Game();
	inline GameState* getCurrentState() const { return currentState; }
	void execute();
	void setState(GameState& newState);
	bool finish();
	void print();
	string getStateName();
	inline const int& getActualLevel() const { return this->actualLevel; }
	void setActualLevel(int x) { this->actualLevel = x; }
};
