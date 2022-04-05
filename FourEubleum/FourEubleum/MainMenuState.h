#pragma once
#include "MainMenu.h"

class MainMenu;

class MainMenuState
{
public:
	virtual void enter(MainMenu* mainMenu) = 0;
	virtual void execute(MainMenu* mainMenu) = 0;
	virtual void exit(MainMenu* mainMenu) = 0;
	virtual ~MainMenuState() {}
};

