#include "Game.h"
#include "GameConcreteState.h"
#include "MapData.h"

Game::Game()
{
	currentState = &Start::getInstance();
	this->actualLevel = 1;
}

void Game::execute()
{
	if (currentState) {
		currentState->execute(this);
	}
}

void Game::setState(GameState& newState)
{
	currentState->exit(this);
	currentState = &newState;
	currentState->enter(this);
}

bool Game::finish()
{
	if (currentState == &Exit::getInstance()) {
		return false;
	}
	else {
		return true;
	}
}

void Game::print()
{
}

string Game::getStateName()
{
	if (currentState == &Start::getInstance()) {
		return "Start";
	}
	else if (currentState == &Exploration::getInstance())
	{
		return "Exploration";
	}
	else if (currentState == &Battlefield::getInstance())
	{
		return "Battlefield";
	}
	else if (currentState == &Pause::getInstance())
	{
		return "Pause";
	}
	else if (currentState == &Exit::getInstance())
	{
		return "Exit";
	}
}
