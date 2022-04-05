#include "MapData.h"

int MyGetch()
{
#ifdef _WIN32
	return _getch();
#endif
}

int main() 
{
	HANDLE console;
	console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, 15);
	MainMenu menu = MainMenu();
	Game game = Game();
	Grid Level = Grid(Level1Data);
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
			game.execute();
			if (game.getStateName() == "Exploration") {
				cout << Level << endl;
				SetConsoleTextAttribute(console, 15);
				int touche = 0;
				while (game.getStateName() == "Exploration") // ECHAP
				{
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
						game.setActualLevel(game.getActualLevel()+1);
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
					cout << Level << endl;
					SetConsoleTextAttribute(console, 15);
				}
			}
			system("pause");
			menu.execute();
		}
		else if (menu.getStateName() == "Exit") {
			system("pause");
			menu.execute();
		}
	}
		
	return 0;
}