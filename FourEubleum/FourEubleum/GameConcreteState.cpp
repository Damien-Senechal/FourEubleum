#include "GameConcreteState.h"

void Start::execute(Game* game)
{
	game->setState(Exploration::getInstance());
}

GameState& Start::getInstance()
{
	static Start singleton;
	return singleton;
}

void Exploration::execute(Game* game)
{
	game->setState(Exploration::getInstance());
}

GameState& Exploration::getInstance()
{
	static Exploration singleton;
	return singleton;
}

void Battlefield::execute(Game* game)
{
	game->setState(Exploration::getInstance());
}

GameState& Battlefield::getInstance()
{
	static Battlefield singleton;
	return singleton;
}

void Pause::execute(Game* game)
{
	game->setState(Exploration::getInstance());
}

GameState& Pause::getInstance()
{
	static Pause singleton;
	return singleton;
}

void Exit::execute(Game* game)
{
}

GameState& Exit::getInstance()
{
	static Exit singleton;
	return singleton;
}
