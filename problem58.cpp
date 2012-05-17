#include <iostream>
#include <math.h>
#include "bigint/BigIntegerLibrary.hh"

using namespace std;
bool isprime(long int no) {
	if (no == 2) {
		return true;
	}
	if (no % 2 == 0 || no == 1) {
		return false;
	}
	for (long int i = 3; i<=sqrt(no);i+=2) {
		if (no % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int diagcount = 1;
	int primecount = 0;
	int diag = 1;
	int size = 1;
	while (primecount*10 > diagcount || size == 1) {
		size += 2;
		for (int i = 1; i <= 4; i++) {
			if (isprime(diag+(size-1)*i))
				primecount++;
			diagcount++;
		}
		diag = diag+(size-1)*4;
	}	
	cout << size;
	return 0;
}