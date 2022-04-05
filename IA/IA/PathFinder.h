//IA QUE J'AVAIS CODER POUR LE PROJET MAIS JE N'AI PAS EU LE TEMPS DE L'IMPLEMENTER

#pragma once
#include "Node.h"

class PathFinder
{
protected:
	int xSize; // Taille horizontal de la grille
	int ySize; // Taille vertical de la grille
	const int nDir = 4; // nombre de directions possibles pour chaque position

	const int xDir[4] = { 1, 0, -1, 0 };
	const int yDir[4] = { 0, 1, 0, -1 };

public:
	PathFinder();
	PathFinder(int x, int y);

	inline const int& getXSize() const { return this->xSize; }
	inline const int& getYSize() const { return this->ySize; }
	inline const int& getNDir() const { return this->nDir; }

	void setXSize(int x) { this->xSize = x; }
	void setYSize(int y) { this->ySize = y; }

	string pathFind(const Location& locStart, const Location& locFinish, vector<vector<int>> squares);


};

