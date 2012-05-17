#include <iostream>
#include <math.h>
#include "bigint/BigIntegerLibrary.hh"

using namespace std;

int main() {
	int count = 0;
	BigInteger Lsum = 0;
	for (int h = 1; count < 12; h += 2) {
		int b = 0;
		double L = 0;
		if (h-1 > 0) {
			b = h-1;
			L = sqrt(h*h + (b/2) * (b/2));
			if ((int)L == L) {
				count++;
				Lsum += L;
				cout << "find1 :" << L << endl;
			}
		}
		b = h+1;
		L = sqrt(h*h + (b/2) * (b/2));
		if ((int)L == L) {
			count++;
			Lsum += L;
			cout << "find2 :" << L << endl;
		}
	}
	cout << Lsum;
	return 0;
}
/*
h = W(L^22 - b/2 ^ 2)
h^2 = L^2 - b/2 ^ 2
L2 = h2 + b2 ^ 2
L = W(h2 + b/2 ^ 2)*/