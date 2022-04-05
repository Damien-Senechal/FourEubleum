#pragma once
#include "Game.h"

class Game;

class GameState
{
public:
	virtual void enter(Game* game) = 0;
	virtual void execute(Game* game) = 0;
	virtual void exit(Game* game) = 0;
	virtual ~GameState() {}
};