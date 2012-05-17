#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include "bigint/BigIntegerLibrary.hh"

using namespace std;

BigInteger factorial(BigInteger n) {
	return n <= 1 ? 1 : n * factorial(n-1);
}

int main() {
	BigInteger C;
	int count = 0;
	for (int n = 1;n<=100;n++) {
		for (int r = 0; r<=n;r++) {
			C = factorial(n)/(factorial(r) * factorial(n - r));
			if (C > 1000000) {
				count++;
			}
		}
	}
	cout << count;
	
	return 0;
}