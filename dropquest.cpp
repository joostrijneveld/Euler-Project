#include <iostream>
#include <math.h>
#include "bigint/BigIntegerLibrary.hh"

using namespace std;

bool isprime(int no) {
	if (no == 2)
		return true;
	if (no % 2 == 0 || no == 1)
		return false;
	for (int i = 3; i <= sqrt(no); i+=2) {
		if (no % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int count = 0;
	int n = 0;
	while (count < 3612) {
		n++;
		if (isprime(n))
			count++;
	}
	cout << n;
	return 0;
}