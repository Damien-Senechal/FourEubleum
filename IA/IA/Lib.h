#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
#include <ctime>
#include <string>
#include <queue>

using namespace std;

struct Location {

	int row, col;

	Location() {
		row = col = 0;
	};

	Location(int r, int c) {
		row = r;
		col = c;
	};
};

