//IA QUE J'AVAIS CODER POUR LE PROJET MAIS JE N'AI PAS EU LE TEMPS DE L'IMPLEMENTER

#include "PathFinder.h"

PathFinder::PathFinder()
{
	setXSize(0);
	setYSize(0);
}

PathFinder::PathFinder(int x, int y)
{
	setXSize(x);
	setYSize(y);
}

string PathFinder::pathFind(const Location& locStart, const Location& locFinish, vector<vector<int>> squares)
{
	setXSize(squares.size());
	setYSize(squares[0].size());

	// liste des nodes fermés (vérifiés)
	vector<vector<int>> closedNodes;
	for (int i = 0; i < getXSize(); i++)
	{
		closedNodes.push_back(vector<int>(getYSize()));
	}

	// liste des nodes ouverts (pas encore vérifiés)
	vector<vector<int>> openNodes;
	for (int i = 0; i < getXSize(); i++)
	{
		openNodes.push_back(vector<int>(getYSize()));
	}

	// Map des directions (0 : Droite, 1 : Haut, 2 : Gauche, 3 : Bas) 
	vector<vector<int>> dirMap;
	for (int i = 0; i < getXSize(); i++)
	{
		dirMap.push_back(vector<int>(getYSize()));
	}

	// list of open (not-yet-checked-out) nodes
	static priority_queue<Node> q[2];

	// q index
	static int qi;

	static Node* pNode1;
	static Node* pNode2;
	static int i, j, row, col, iNext, jNext;
	static char c;
	qi = 0;

	// reset the Node lists (0 = ".")
	for (j = 0; j < getYSize(); j++) {
		for (i = 0; i < getXSize(); i++) {
			closedNodes[i][j] = 0;
			openNodes[i][j] = 0;
		}
	}

	// create the start node and push into list of open nodes
	pNode1 = new Node(locStart, 0, 0);
	pNode1->calculateFValue(locFinish);
	q[qi].push(*pNode1);

	// A* search
	while (!q[qi].empty()) {
		// get the current node w/ the lowest FValue
		// from the list of open nodes
		pNode1 = new Node(q[qi].top().getLocation(), q[qi].top().getGValue(), q[qi].top().getFValue());
		row = (pNode1->getLocation()).row;
		col = pNode1->getLocation().col;
		cout << "row, col=" << row << ',' << col << endl;

		q[qi].pop();
		openNodes[row][col] = 0;

		closedNodes[row][col] = 1;

		if (row == locFinish.row && col == locFinish.col) {
			cout << endl;
			for (j = getYSize() - 1; j >= 0; j--) {
				for (i = 0; i < getXSize(); i++) {
					cout << dirMap[i][j];
				}
				cout << endl;
			}
			cout << endl;

			string path = "";
			while (!(row == locStart.row && col == locStart.col)) {
				j = dirMap[row][col];
				c = '0' + (j + getNDir() / 2) % getNDir();
				path = c + path;
				row += this->xDir[j];
				col += this->yDir[j];
			}

			delete pNode1;

			while (!q[qi].empty()) q[qi].pop();
			return path;
		}

		for (i = 0; i < getNDir(); i++) {
			iNext = row + this->xDir[i];
			jNext = col + this->yDir[i];

			if (!(iNext<0 || iNext > getXSize() - 1 || jNext < 0 || jNext > getYSize() - 1 || squares[iNext][jNext] == 1 || closedNodes[iNext][jNext] == 1)) {
				pNode2 = new Node(Location(iNext, jNext), pNode1->getGValue(), pNode1->getFValue());
				pNode2->updateGValue(i);
				pNode2->calculateFValue(locFinish);

				if (openNodes[iNext][jNext] == 0) {
					openNodes[iNext][jNext] = pNode2->getFValue();
					q[qi].push(*pNode2);
					dirMap[iNext][jNext] = (i + getNDir() / 2) % getNDir();
				}
				else if (openNodes[iNext][jNext] > pNode2->getFValue()) {
					openNodes[iNext][jNext] = pNode2->getFValue();

					dirMap[iNext][jNext] = (i + getNDir() / 2) % getNDir();

					while (!(q[qi].top().getLocation().row == iNext && q[qi].top().getLocation().col == jNext)) {
						q[1 - qi].push(q[qi].top());
						q[qi].pop();
					}

					q[qi].pop();

					if (q[qi].size() > q[1 - qi].size()) qi = 1 - qi;
					while (!q[qi].empty()) {
						q[1 - qi].push(q[qi].top());
						q[qi].pop();
					}
					qi = 1 - qi;

					q[qi].push(*pNode2);
				}
				else delete pNode2;
			}
		}
		delete pNode1;
	}
	return "";
}
