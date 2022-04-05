#include "ConcreteMainMenuStates.h"
#include "GameConcreteState.h"

void Intro::execute(MainMenu* mainMenu)
{
	mainMenu->setState(Menu::getInstance());
}

MainMenuState& Intro::getInstance()
{
	static Intro singleton;
	return singleton;
}

void Menu::enter(MainMenu* mainMenu)
{
	cout << "----------" << "Main Menu " << "----------" << endl;
	cout << "Press Enter to Play" << endl;
	cout << "Press Echap to Exit" << endl;
}

void Menu::execute(MainMenu* mainMenu)
{
	if (mainMenu->getChoice() == 1) {
		mainMenu->setState(StartGame::getInstance());
	}
	else if (mainMenu->getChoice() == 2) {
		mainMenu->setState(ExitGame::getInstance());
	}
}

MainMenuState& Menu::getInstance()
{
	static Menu singleton;
	return singleton;
}

void StartGame::enter(MainMenu* mainMenu)
{
	cout << "We are in the Game !" << endl;
}

void StartGame::execute(MainMenu* mainMenu)
{
	mainMenu->setState(ExitGame::getInstance());
}

MainMenuState& StartGame::getInstance()
{
	static StartGame singleton;
	return singleton;
}

void ExitGame::enter(MainMenu* mainMenu)
{
	cout << "Exiting the game" << endl;
}

void ExitGame::execute(MainMenu* mainMenu)
{

}

MainMenuState& ExitGame::getInstance()
{
	static ExitGame singleton;
	return singleton;
}
