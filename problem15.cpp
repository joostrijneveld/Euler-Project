#include <iostream>
#include <math.h>
#include <sstream>
#include <string>

using namespace std;

int main () {
	int size = 20;
	unsigned long field[size+1][size+1];
	field[0][0] = 0;
	for (int i = 1;i<size+1;i++) {
		field[0][i] = 1;
		field[i][0] = 1;
	}
	for (int i = 1;i<size+1;i++) {
		for (int j = 1;j<size+1;j++) {
			field[i][j] = field[i-1][j] + field[i][j-1];
			cout << field[i][j] << " ";
		}
		cout << "\n";
	}
	//cout << field[size][size];
	return 0;
}