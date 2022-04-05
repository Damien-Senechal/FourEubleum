#include "Grid.h"

Grid::Grid()
{
	this->values = vector<vector<Point>>();
	setCursor(Point(0, 0, '.', true));
	this->numberEnemy = 5;
}

/*Grid::Grid(int x, int y, int px, int py)
{
	setNumberEnemy(5);
	int number;
	srand(time(NULL));
	for (size_t i = 0; i < x; i++)
	{
		this->values.push_back(vector<Point>(y));
		for (size_t j = 0; j < y; j++)
		{
			number = rand() % 100 + 1;
			if (i == px && j == py) {
				this->values[i][j] = Point(i, j, '.', true);
				this->cursor = this->values[i][j];
			}
			else if (i == 0 || j == 0 || i == x-1 || j == y-1) {
				this->values[i][j] = Point(i, j, 'W', false);
			}
			else {
				this->values[i][j] = Point(i, j, '.', false);
				if (number == 7) {
					if (getNumberEnemy() >= 0) {
						this->values[i][j].setEnemy(true);
						setNumberEnemy(getNumberEnemy() - 1);
					}
				}
			}
		}
	}
}*/

Grid::Grid(vector<vector<int>> data)
{
	setNumberEnemy(5);
	int number;
	srand(time(NULL));
	for (size_t i = 0; i < data.size(); i++)
	{
		this->values.push_back(vector<Point>(data[i].size()));
		for (size_t j = 0; j < data[i].size(); j++)
		{
			number = rand() % 20 + 1;
			if (data[j][i] == 2) {
				this->values[i][j] = Point(i, j, '.', true);
				this->cursor = this->values[i][j];
			}
			else if (data[j][i] == 1) {
				this->values[i][j] = Point(i, j, 'W', false);
			}
			else if (data[j][i] == 3) {
				this->values[i][j] = Point(i, j, 'D', false);
			}
			else {
				this->values[i][j] = Point(i, j, '.', false);
				if (number == 7) {
					if (getNumberEnemy() > 0) {
						this->values[i][j].setEnemy(true);
						setNumberEnemy(getNumberEnemy() - 1);
					}
				}
			}
		}
	}
}



bool Grid::Move(int direction)
{
	Point temp = getCursor();
	switch (direction)
	{
	case 0:
		if (getCursor().getPosY() - 1 >= 0 && this->values[getCursor().getPosX()][getCursor().getPosY()-1].getVal() != 'W') {
			this->values[temp.getPosX()][temp.getPosY()].setCursorOn(false);
			setCursor(getValues()[temp.getPosX()][temp.getPosY() - 1]);
			this->values[getCursor().getPosX()][getCursor().getPosY()].setCursorOn(true);
			this->cursor.setCursorOn(true);
			return true;
		}
		else {
			cout << "Vous ne pouvez pas monter" << endl;
			return false;
		}
		break;
	case 1:
		if (getCursor().getPosX() + 1 < getValues().size() && this->values[getCursor().getPosX()+1][getCursor().getPosY()].getVal() != 'W') {
			this->values[temp.getPosX()][temp.getPosY()].setCursorOn(false);
			setCursor(getValues()[temp.getPosX() + 1][temp.getPosY()]);
			this->values[getCursor().getPosX()][getCursor().getPosY()].setCursorOn(true);
			this->cursor.setCursorOn(true);
			return true;
		}
		else {
			cout << "Vous ne pouvez pas aller a droite" << endl;
			return false;
		}
		break;
	case 2:
		if (getCursor().getPosX() - 1 >= 0 && this->values[getCursor().getPosX()-1][getCursor().getPosY()].getVal() != 'W') {
			this->values[temp.getPosX()][temp.getPosY()].setCursorOn(false);
			setCursor(getValues()[temp.getPosX() - 1][temp.getPosY()]);
			this->values[getCursor().getPosX()][getCursor().getPosY()].setCursorOn(true);
			this->cursor.setCursorOn(true);
			return true;
		}
		else {
			cout << "Vous ne pouvez pas aller a gauche" << endl;
			return false;
		}
		break;
	case 3:
		if (getCursor().getPosY() + 1 < getValues()[0].size() && this->values[getCursor().getPosX()][getCursor().getPosY() + 1].getVal() != 'W') {
			this->values[temp.getPosX()][temp.getPosY()].setCursorOn(false);
			setCursor(getValues()[temp.getPosX()][temp.getPosY() + 1]);
			this->values[getCursor().getPosX()][getCursor().getPosY()].setCursorOn(true);
			this->cursor.setCursorOn(true);
			return true;
		}
		else {
			cout << "Vous ne pouvez pas aller en bas" << endl;
			return false;
		}
		break;
	default:
		break;
	}
}

void Grid::changeMap(vector<vector<int>> data)
{
	setNumberEnemy(5);
	this->values.clear();
	int number;
	srand(time(NULL));
	for (size_t i = 0; i < data.size(); i++)
	{
		this->values.push_back(vector<Point>(data[i].size()));
		for (size_t j = 0; j < data[i].size(); j++)
		{
			number = rand() % 20 + 1;
			if (data[j][i] == 2) {
				this->values[i][j] = Point(i, j, '.', true);
				this->cursor = this->values[i][j];
			}
			else if (data[j][i] == 1) {
				this->values[i][j] = Point(i, j, 'W', false);
			}
			else if (data[j][i] == 3) {
				this->values[i][j] = Point(i, j, 'D', false);
			}
			else {
				this->values[i][j] = Point(i, j, '.', false);
				if (number == 7) {
					if (getNumberEnemy() > 0) {
						this->values[i][j].setEnemy(true);
						setNumberEnemy(getNumberEnemy() - 1);
					}
				}
			}
		}
	}
}

void Grid::removeEnemy(int x, int y)
{
	this->values[x][y].setEnemy(false);
}

ostream& operator<<(ostream& os, Grid const& p) {
	for (size_t i = 0; i < p.getValues()[0].size(); i++)
	{
		for (size_t j = 0; j < p.getValues().size(); j++)
		{
			os << p.getValues()[j][i];
		}
		os << endl;
	}

	return os;
}
