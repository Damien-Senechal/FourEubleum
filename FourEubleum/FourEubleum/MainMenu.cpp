#include "MainMenu.h"
#include "ConcreteMainMenuStates.h"

MainMenu::MainMenu()
{
	this->choice = 0;
	currentState = &Intro::getInstance();
}

void MainMenu::execute()
{
	if (currentState) {
		currentState->execute(this);
	}
}

void MainMenu::setState(MainMenuState& newState)
{
	currentState->exit(this);
	currentState = &newState;
	currentState->enter(this);
}

bool MainMenu::finish()
{
	if (currentState == &ExitGame::getInstance()) {
		return false;
	}
	else {
		return true;
	}
}

string MainMenu::getStateName()
{
	if (currentState == &Intro::getInstance()) {
		return "Intro";
	}
	else if (currentState == &Menu::getInstance()) 
	{
		return "Menu";
	}
	else if (currentState == &StartGame::getInstance())
	{
		return "Game";
	}
	else if (currentState == &ExitGame::getInstance())
	{
		return "Exit";
	}
}
