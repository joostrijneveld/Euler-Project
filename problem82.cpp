#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

const int SIZE = 80;

int min(int a, int b, int c) {
	if (a < c && a < b)
		return a;
	if (b < c && b < a)
		return b;
	return c;
}

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
			for (int j = 0; j < SIZE; j++) {
				//when coming from the bottom
				int smallestfromdown = 0;
				int smallb = 0;
				for (int b = 1; b < SIZE-j; b++) {
					int vertsum = 0;
					for (int a = 1; a <= b; a++) {
						vertsum += matrix[i][j+a];
					}
					vertsum += matrix[i-1][j+b];
					if (vertsum < smallestfromdown || smallestfromdown == 0) {
						smallb = b;
						smallestfromdown = vertsum;
					}
				}
				//when there's one above it
				if (j - 1 >= 0) {
					if (smallestfromdown > 0) {
						matrix[i][j] = matrix[i][j] + min(matrix[i-1][j], matrix[i][j-1], smallestfromdown);
					}
					else {
						matrix[i][j] = matrix[i][j] + min(matrix[i-1][j], matrix[i][j-1]);
					}
				}
				else if (smallestfromdown > 0) {
					matrix[i][j] = matrix[i][j] + min(matrix[i-1][j], smallestfromdown);
				}
				else {
					matrix[i][j] = matrix[i][j] + matrix[i-1][j];
				}
			}
		}
		int minpath = 0;
		for (int j = 0; j < SIZE; j++) {
			if (minpath > matrix[SIZE-1][j] || minpath == 0) {
				minpath = matrix[SIZE-1][j];
			}
		}
		cout << minpath;
	}
	else {
		cout << "Failed opening file";
	}
	
	return 0;
}