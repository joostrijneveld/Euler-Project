#include <iostream>
#include <math.h>
#include "bigint/BigIntegerLibrary.hh"

using namespace std;

BigInteger lookbackarr[500];

BigInteger s(int n) {
	if (lookbackarr[n] > -1)
		return lookbackarr[n];
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	if (n == 3)
		return 4;
	if (n == 4)
		return 8;
	lookbackarr[n] = s(n-1) + s(n-2) + s(n-3) + s(n-4);
	return lookbackarr[n];
}

int main() {
	for (int i = 0; i < 500; i++)
		lookbackarr[i] = -1;
	for (int i = 1; i < 51; i++)
		cout << s(i) << endl;
	return 0;
}