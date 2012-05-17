#include <iostream>
#include <math.h>
#include "bigint/BigIntegerLibrary.hh"

using namespace std;

BigInteger Rlookbackarr[500];
BigInteger Glookbackarr[500];
BigInteger Blookbackarr[500];

BigInteger r(int n) {
	if (Rlookbackarr[n] > -1)
		return Rlookbackarr[n];
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	if (n == 3)
		return 2;
	if (n == 4)
		return 3;
	if (n == 5)
		return 7;
	Rlookbackarr[n] = r(n-1) + r(n-2);
	return Rlookbackarr[n];
}

BigInteger g(int n) {
	if (Glookbackarr[n] > -1)
		return Glookbackarr[n];
	if (n == 1)
		return 0;
	if (n == 2)
		return 0;
	if (n == 3)
		return 1;
	if (n == 4)
		return 2;
	if (n == 5)
		return 3;
	Glookbackarr[n] = g(n-1) + g(n-3);
	return Glookbackarr[n];
}

BigInteger b(int n) {
	if (Blookbackarr[n] > -1)
		return Blookbackarr[n];
	if (n == 1)
		return 0;
	if (n == 2)
		return 0;
	if (n == 3)
		return 0;
	if (n == 4)
		return 1;
	if (n == 5)
		return 2;
	if (n == 6)
		return 3;
	Blookbackarr[n] = b(n-1) + b(n-4);
	return Blookbackarr[n];
}


int main() {
	for (int i = 0; i < 500; i++) {
		Rlookbackarr[i] = -1;
		Glookbackarr[i] = -1;
		Blookbackarr[i] = -1;
	}
	cout << r(5)-1 << endl;
	cout << g(5)-1 << endl;
	cout << b(5)-1 << endl;
	//for (int i = 1; i < 51; i++)
	//	cout << r(i) + b(i) + g(i) << endl;
	return 0;
}