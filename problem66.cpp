#include <iostream>
#include <math.h>
#include "bigint/BigIntegerLibrary.hh"

using namespace std;

const int maxlim = 20000;

BigInteger squares[maxlim];

bool issquare(BigInteger n) {
	int a = sqrt(n);
	return (a * a == n);
}

int minimalx(int D) {
	for (int i = 2; i < maxlim; i++) {
		if (squares[i] == D) {
			return 0;
		}
		if ((squares[i] - 1) % D == 0) {
			if (issquare((squares[i] - 1) / D)) {
				return i;
			}
		}
	}
	return -1;
}

int main() {
	for (int i = 0; i < maxlim; i++) {
		squares[i] = i * i;
		//cout << squares[i] << endl;
	}
	int largest = 0;
	int Dlarge = 0;
	for (int i = 2; i <= 1000; i++) {
		int t = minimalx(i);
		if (t == -1)
			cout << "TOO LOW";
		//cout << i << " " <<t << endl;
		if (t > largest) {
			largest = t;
			Dlarge = i;
			//cout << Dlarge << " " <<largest << endl;
		}
	}
	
	return 0;
}