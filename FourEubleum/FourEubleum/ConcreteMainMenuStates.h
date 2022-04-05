#pragma once
#include "MainMenuState.h"
#include "MainMenu.h"

class Intro : public MainMenuState
{
private:
	Intro() {}
	Intro(const Intro& other);
	Intro& operator=(const Intro& other);

public:
	void enter(MainMenu* mainMenu) {}
	void execute(MainMenu* mainMenu);
	void exit(MainMenu* mainMenu) {}
	static MainMenuState& getInstance();
};

class Menu : public MainMenuState
{
private:
	Menu() {}
	Menu(const Menu& other);
	Menu& operator=(const Menu& other);

public:
	void enter(MainMenu* mainMenu);
	void execute(MainMenu* mainMenu);
	void exit(MainMenu* mainMenu) {}
	static MainMenuState& getInstance();
};

class StartGame : public MainMenuState
{
private:
	StartGame() {}
	StartGame(const StartGame& other);
	StartGame& operator=(const StartGame& other);

public:
	void enter(MainMenu* mainMenu);
	void execute(MainMenu* mainMenu);
	void exit(MainMenu* mainMenu) { }
	static MainMenuState& getInstance();
};

class ExitGame : public MainMenuState
{
private:
	ExitGame() {}
	ExitGame(const ExitGame& other);
	ExitGame& operator=(const ExitGame& other);

public:
	void enter(MainMenu* mainMenu);
	void execute(MainMenu* mainMenu);
	void exit(MainMenu* mainMenu) {}
	static MainMenuState& getInstance();
};

