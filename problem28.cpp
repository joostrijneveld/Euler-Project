#include <iostream>
#include <math.h>
#include "bigint/BigIntegerLibrary.hh"

using namespace std;

int main() {
	int size = 1001;
	int sum, field[size][size], x = (size-1)/2, y = (size-1)/2, n = 1, d = 0;
	// d = 0: right, d = 1: down, d = 2; left, d = 3; up
	for (int i=0;i<size;i++) {
		for (int j=0;j<size;j++) {
			field[i][j] = 0;
		}
	}
	while (n <= size*size) {
		field[y][x] = n;
		n++;
		if (d == 0) {
			x += 1;
			if (field[y+1][x] == 0) {
				d = 1;
			}
		}
		else if (d == 1) {
			y += 1;
			if (field[y][x-1] == 0) {
				d = 2;
			}
		}
		else if (d == 2) {
			x -= 1;
			if (field[y-1][x] == 0) {
				d = 3;
			}
		}
		else if (d == 3) {
			y -= 1;
			if (field[y][x+1] == 0) {
				d = 0;
			}
		}
	}
	//draw the square:
	/*for (int i=0;i<size;i++) {
		for (int j=0;j<size;j++) {
			cout << field[i][j] << " ";
		}
		cout << "\n";
	}*/
	for (int i=0;i<size;i++) {
		sum += field[i][i];
		sum += field[i][size-1-i];
	}
	sum -= field[(size-1)/2][(size-1)/2];
	cout << "sum of diags: " << sum;
	return 0;
}