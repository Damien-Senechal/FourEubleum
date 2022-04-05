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

void Game::setExploration()
{
	currentState->exit(this);
	currentState = &Exploration::getInstance();
	currentState->enter(this);
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

void Game::Battle(Character& p)
{
	/*system("CLS");
	Enemy e;
	int number;
	int choice;
	number = rand() % 2 + 1;
	if (number == 1) {
		e = Soldier;
	}
	else if (number == 2) {
		e = Monster;
	}
	while (e.getHealth() > 0) {
		cout << "Battle against : " << e.getName() << endl;
		cout << "Enemy Health : " << e.getHealth() << endl;
		cout << "1-Attack" << endl;
		cout << "2-Defend" << endl;
		cout << "3-Potion" << endl;
		cin >> choice;
		if (choice == 1) {
			e.setHealth(e.getHealth() - (p.getAttack() + p.getWeaponEquipped().getAttack()));
			p.setHealth(p.getHealth() - e.getAttack());
			cout << "Vous avez attaqué" << endl;
		}
		else if (choice == 2) {
			int attack = e.getAttack() - p.getDefense();
			if (attack > 0) {
				p.setHealth(p.getHealth() - attack);
			}
			cout << "Vous vous etes defendu" << endl;
		}
		else if (choice == 3) {
			for (size_t i = 0; i < p.getInventory().size(); i++)
			{
				if (p.getInventory()[i].getName() == "Potion") {
					p.setHealth(p.getHealth() + 70);
				}
				else {
					cout << "Vous n'avez pas de potion" << endl;
				}
			}
		}
		else {
			cout << "Error" << endl;
		}
	}
	cout << "Vous avez gagné !" << endl;
	system("pause");*/
}

string Game::getStateName()
{
	if (currentState == &Start::getInstance()) {
		this->stateName = "Start";
	}
	else if (currentState == &Exploration::getInstance())
	{
		this->stateName = "Exploration";
	}
	else if (currentState == &Battlefield::getInstance())
	{
		this->stateName = "Battlefield";
	}
	else if (currentState == &Pause::getInstance())
	{
		this->stateName = "Pause";
	}
	else if (currentState == &Exit::getInstance())
	{
		this->stateName = "Exit";
	}
	else {
		this->stateName = "None";
	}

	return this->stateName;
}
