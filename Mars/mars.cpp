#include <iostream>
using namespace std;

#define CMAX 16
#define RMAX 12

void find(int plus[CMAX][RMAX], int minus[CMAX][RMAX], int load[CMAX][RMAX], int r, int c, int Batt);
int main() {
	int plus[CMAX][RMAX] = { 0, };
	int minus[CMAX][RMAX] = { 0, };
	int i, j;
	int Batt, r, c;

	cin >> Batt >> c >> r;

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) cin >> plus[i][j];
	}
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) cin >> minus[i][j];
	}

	int load[CMAX][RMAX] = { Batt };

	find(plus, minus, load, r, c, Batt);

	return 0;
}

void find(int plus[CMAX][RMAX], int minus[CMAX][RMAX], int load[CMAX][RMAX], int r, int c, int Batt) {
	int i, j;
	i = 1; j = 1;
	for (i = 1; i < r; i++) {
		if (minus[i][0] <= Batt && load[i - 1][0] != -1) {
			load[i][0] = load[i - 1][0] - minus[i][0];
			if (load[i][0] > 0) load[i][0] += plus[i][0];
			if (load[i][0] > Batt) load[i][0] = Batt;
		}
		else load[i][0] = -1;
	}

	for (j = 1; j < c; j++) {
		if (minus[0][j] <= Batt && load[0][j - 1] != -1) {
			load[0][j] = load[0][j - 1] - minus[0][j];
			if (load[0][j] > 0) load[0][j] += plus[0][j];
			if (load[0][j] > Batt) load[0][j] = Batt;
		}
		else load[0][j] = -1;
	}

	int x, y, z;

	for (i = 1; i < r; i++) {
		for (int j = 1; j < c; j++) {
			x = load[i - 1][j - 1] - minus[i][j] * 1.4;
			y = load[i - 1][j] - minus[i][j];
			z = load[i][j - 1] - minus[i][j];

			if (x >= 0) x += plus[i][j];
			if (y >= 0) y += plus[i][j];
			if (z >= 0) z += plus[i][j];

			if (x >= y) {
				if (z >= x) load[i][j] = z;
				else load[i][j] = x;
			}
			else {
				if (z >= y) load[i][j] = z;
				else load[i][j] = y;
			}

			if (load[i][j] > Batt) load[i][j] = Batt;
			else if (load[i][j] <= 0) load[i][j] = -1;
		}
	}

	cout << load[i - 1][j - 1];
}