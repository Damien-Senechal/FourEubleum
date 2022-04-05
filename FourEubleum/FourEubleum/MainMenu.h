#pragma once
#include "Lib.h"
#include "MainMenuState.h"

class MainMenuState;

class MainMenu
{
private:
	MainMenuState* currentState;
	int choice;

public:
	MainMenu();
	inline MainMenuState* getCurrentState() const { return currentState; }
	void execute();
	void setState(MainMenuState& newState);
	bool finish();
	string getStateName();

	inline const int& getChoice() const { return this->choice; }

	void setChoice(int c) { this->choice = c; }
};

