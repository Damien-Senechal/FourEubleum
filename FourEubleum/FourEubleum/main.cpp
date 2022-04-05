#include "MapData.h"
#include "EnemyData.h"

int MyGetch()
{
#ifdef _WIN32
	return _getch();
#endif
}

void Battle(Character& p)
{
	system("CLS");
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
	system("pause");
}

int main() 
{
	HANDLE console;
	console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, 15);
	MainMenu menu = MainMenu();
	Game game = Game();
	Grid Level = Grid(Level1Data);
	Character player = Character("Timothée");
	while (menu.finish()) {
		if (menu.getStateName() == "Intro") {
			cout << "Welcome !" << endl;
			system("pause");
			menu.execute();
		}
		else if (menu.getStateName() == "Menu") {
			int touche = 0;
			touche = MyGetch();
			switch (touche)
			{
			case 13:
				menu.setChoice(1);
				break;
			case 27:
				menu.setChoice(2);
				break;
			default:
				break;
			}
			menu.execute();
		}
		else if (menu.getStateName() == "Game") {
			if (game.getStateName() == "Start") {
				game.execute();
			}
			else if (game.getStateName() == "Battlefield") {
				system("CLS");
				cout << "FIGHT" << endl;
				Enemy e;
				int number;
				int choice = 1;
				number = rand() % 2 + 1;
				if (number == 1) {
					e = Soldier;
				}
				else if (number == 2) {
					e = Monster;
				}
				while (e.getHealth() > 0) {
					int touche = 0;
					touche = MyGetch();
					switch (touche)
					{
					case 'z':
						if (choice > 1) {
							choice--;
						}
						break;
					case 's':
						if (choice < 3) {
							choice++;
						}
						break;
					case 13:
						if (choice == 1) {
							e.setHealth(e.getHealth() - (player.getAttack() + player.getWeaponEquipped().getAttack()));
							player.setHealth(player.getHealth() - e.getAttack());
							cout << "Vous avez attaqué" << endl;
						}
						else {
							cout << "Error" << endl;
						}
						break;
					default:
						break;
					}
					system("CLS");
					cout << choice << endl;
					if (choice == 3) {
						cout << "Battle against : " << e.getName() << endl;
						cout << "Enemy Health : " << e.getHealth() << endl;
						cout << "1 - Attack" << endl;
						cout << "2 - Defend" << endl;
						cout << "3 - Potion <-" << endl;
					}
					else if (choice == 2) {
						cout << "Battle against : " << e.getName() << endl;
						cout << "Enemy Health : " << e.getHealth() << endl;
						cout << "1 - Attack" << endl;
						cout << "2 - Defend <-" << endl;
						cout << "3 - Potion" << endl;
					}
					else if (choice == 1) {
						cout << "Battle against : " << e.getName() << endl;
						cout << "Enemy Health : " << e.getHealth() << endl;
						cout << "1 - Attack <-" << endl;
						cout << "2 - Defend" << endl;
						cout << "3 - Potion" << endl;
					}

				}
				//Battle(player);
				system("pause");
				game.execute();
			}
			else if(game.getStateName() == "Exploration")
			{
				int number;
				number = rand() % 10 + 1;
				system("CLS");
				cout << Level << endl;
				SetConsoleTextAttribute(console, 15);
				int touche = 0;
				touche = MyGetch();
				switch (touche)
				{
				case 'q':
					Level.Move(2);
					break;
				case 'd':
					Level.Move(1);
					break;
				case 'z':
					Level.Move(0);
					break;
				case 's':
					Level.Move(3);
				default:
					break;
				}
				system("CLS");
				if (Level.getCursor().getVal() == 'D' && game.getActualLevel() == 1)
				{
					game.setActualLevel(game.getActualLevel() + 1);
					Level.changeMap(Level2Data);
				}
				else if (Level.getCursor().getVal() == 'D' && game.getActualLevel() == 2)
				{
					game.setActualLevel(game.getActualLevel() + 1);
					Level.changeMap(Level3Data);
				}
				else if (Level.getCursor().getVal() == 'D' && game.getActualLevel() == 3)
				{
					game.setActualLevel(game.getActualLevel() + 1);
					Level.changeMap(Level4Data);
				}
				else if (number == 1)
				{
					number = 0;
					game.execute();
				}
				//cout << Level << endl;
				SetConsoleTextAttribute(console, 15);
			}
		}
		else if (menu.getStateName() == "Exit") {
			system("pause");
			menu.execute();
		}
	}
		
	return 0;
}