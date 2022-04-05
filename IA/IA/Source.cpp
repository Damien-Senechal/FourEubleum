//IA QUE J'AVAIS CODER POUR LE PROJET MAIS JE N'AI PAS EU LE TEMPS DE L'IMPLEMENTER

#include"PathFinder.h"

int main() {

    const int xDir[4] = { 1, 0, -1, 0 };
    const int yDir[4] = { 0, 1, 0, -1 };

    PathFinder p = PathFinder(8, 6);

    vector<vector<int>> squares;
    for (int i = 0; i < p.getXSize(); i++) {
        squares.push_back(vector<int>(p.getYSize()));
    }

    // creation d'un grille vide
    for (int j = 0; j < p.getYSize(); j++) {
        for (int i = 0; i < p.getXSize(); i++) squares[i][j] = 0;
    }

    // ajout des murs
    squares[4][2] = 1;
    squares[4][3] = 1;
    squares[4][4] = 1;

    // position d'arrivé et de depart
    int iStart = 2, jStart = 3;
    int iEnd = 0, jEnd = 0;

    cout << "Grid Size (IDIM,JDIM): " << p.getXSize() << "," << p.getYSize() << endl;
    cout << "Start: " << iStart << "," << jStart << endl;
    cout << "Finish: " << iEnd << "," << jEnd << endl;

    clock_t start = clock();

    // recuperation du path
    string path = p.pathFind(Location(iStart, jStart), Location(iEnd, jEnd), squares);

    clock_t end = clock();
    double time = double(end - start);
    cout << "Time (ms): " << time << endl;
    cout << "path: " << path << endl;

    // follow the path on the squares and display it 
    if (path.length() > 0) {
        char c;
        int m, n;
        int i = iStart;
        int j = jStart;
        squares[i][j] = 2;
        for (m = 0; m < path.length(); m++) {
            c = path.at(m);
            n = atoi(&c);
            i = i + xDir[n];
            j = j + yDir[n];
            squares[i][j] = 3;
        }
        squares[i][j] = 4;

        // display the squares with the path
        for (j = p.getYSize() - 1; j >= 0; j--) {
            for (i = 0; i < p.getXSize(); i++) {
                if (squares[i][j] == 0)
                    cout << ".";
                else if (squares[i][j] == 1)
                    cout << "O"; //obstacle
                else if (squares[i][j] == 2)
                    cout << "I"; //Initial
                else if (squares[i][j] == 3)
                    cout << "P"; //path
                else if (squares[i][j] == 4)
                    cout << "F"; //final
            }
            cout << endl;
        }
    }
    return(0);
}