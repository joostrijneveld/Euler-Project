#include <iostream>
#include <math.h>
#include <fstream>
#include "bigint/BigIntegerLibrary.hh"

using namespace std;

const int ROWCOUNT = 100;

int max(int a, int b) {
	if (a > b) 
		return a;
	return b;
}

int main() {
	ifstream trianglefile("triangle.txt");
	if (trianglefile) {
		BigInteger triangle[ROWCOUNT][ROWCOUNT];
		int a;
		for (int i = 0; i < ROWCOUNT; i++) {
			for (int j = 0; j <= i; j++) {
				trianglefile >> a;
				triangle[i][j] = a;
			}
		}
		for (int i = 0; i < ROWCOUNT; i++) {
			for (int j = 0 ; j <= i ; j++) {
				if (j == 0) {
					triangle[i][j] += triangle[i-1][j];
				}
				else if (j == i) {
					triangle[i][j] += triangle[i-1][j-1];
				}
				else {
					triangle[i][j] += max(triangle[i-1][j-1],triangle[i-1][j]);
				}
			}	
		}
		BigInteger highest = 0;
		for (int i = 0; i < ROWCOUNT; i++) {
			highest = max(triangle[ROWCOUNT-1][i],highest);
		}
		cout << highest;
	}
	else {
		cout << "Failed opening file";
	}
	
	return 0;
}