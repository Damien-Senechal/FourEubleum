#pragma once
#include "Point.h"

class Grid
{
protected:
	vector<vector<Point>> values;
	Point cursor;
	int numberEnemy;
public:
	Grid();
	Grid(int x, int y, int px, int py);
	Grid(vector<vector<int>> data);

	inline const vector<vector<Point>>& getValues() const { return this->values; }
	inline const Point& getCursor() const { return this->cursor; }
	inline const int& getNumberEnemy() const { return this->numberEnemy; }

	void setValues(vector<vector<Point>> v) { this->values = v; }
	void setCursor(Point c) { this->cursor = c; }
	void setNumberEnemy(int n) { this->numberEnemy = n; }

	bool Move(int direction);
	void changeMap(vector<vector<int>> data);

	friend ostream& operator<<(ostream& os, Grid const& p);
};

