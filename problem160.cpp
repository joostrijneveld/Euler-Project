#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include "bigint/BigIntegerLibrary.hh"
#include <stdio.h>
#include <time.h>

using namespace std;

BigInteger factoriala(BigInteger n) {
	return n <= 1 ? 1 : n * factoriala(n-1);
}

int factorial(int n) {
	return n <= 1 ? 1 : n * factorial(n-1);
}
int main() {
	clock_t start = clock();
	string str = bigIntegerToString(factoriala(2000));
	printf("Time elapsed: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
	start = clock();
	str = bigIntegerToString(factorial(2000));
	printf("Time elapsed: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
	/*int i = str.length();
	while (true) {
		i--;
		if (str.substr(i,1) != "0") {
			cout << str.substr(i-4,i-9);
			break;
		}
	}*/
	return 0;
}