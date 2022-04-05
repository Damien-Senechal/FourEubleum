#pragma once
#include "GameState.h"
#include "Game.h"

class Start : public GameState
{
private:
	Start() {}
	Start(const Start& other);
	Start& operator=(const Start& other);

public:
	void enter(Game* game){}
	void execute(Game* game);
	void exit(Game* game) {}
	static GameState& getInstance();
};

class Exploration : public GameState
{
private:
	Exploration() {}
	Exploration(const Exploration& other);
	Exploration& operator=(const Exploration& other);

public:
	void enter(Game* game) {}
	void execute(Game* game);
	void exit(Game* game) {}
	static GameState& getInstance();
};

class Battlefield : public GameState
{
private:
	Battlefield() {}
	Battlefield(const Battlefield& other);
	Battlefield& operator=(const Battlefield& other);

public:
	void enter(Game* game) {}
	void execute(Game* game);
	void exit(Game* game) {}
	static GameState& getInstance();
};

class Pause : public GameState
{
private:
	Pause() {}
	Pause(const Pause& other);
	Pause& operator=(const Pause& other);

public:
	void enter(Game* game) {}
	void execute(Game* game);
	void exit(Game* game) {}
	static GameState& getInstance();
};

class Exit : public GameState
{
private:
	Exit() {}
	Exit(const Exit& other);
	Exit& operator=(const Exit& other);

public:
	void enter(Game* game) {}
	void execute(Game* game);
	void exit(Game* game) {}
	static GameState& getInstance();
};

