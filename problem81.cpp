#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

const int SIZE = 80;

int min(int a, int b) {
	if (a < b) 
		return a;
	return b;
}

int main() {
	ifstream file ("matrix.txt");
	if (file) {
		int matrix[SIZE][SIZE];
		int a;
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE ; j++) {
				file >> a;
				matrix[j][i] = a;
			}
		}
		for (int i = 1; i < SIZE; i++) {
			matrix[i][0] = matrix[i][0] + matrix[i-1][0];
			matrix[0][i] = matrix[0][i] + matrix[0][i-1];
		}
		for (int i = 1; i < SIZE; i++) {
			for (int j = 1; j < SIZE; j++) {
				matrix[i][j] = matrix[i][j]+min(matrix[i-1][j],matrix[i][j-1]);
			}
		}
		cout << matrix[SIZE-1][SIZE-1];
	}
	else {
		cout << "Failed opening file";
	}
	
	return 0;
}