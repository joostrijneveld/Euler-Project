#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include "bigint/BigIntegerLibrary.hh"

using namespace std;

bool isprime(long int no) {
	if (no < 0) {
		return false;
	}
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

int main () {
	int n, a, b, consec, highest, higha, highb;
	for (a = -999;a<1000;a++) {
		for (b = -999;b<1000;b++) {
			consec = 0;
			for (n = 0;n<10000;n++) {
				if (isprime(n*n+a*n+b)) {
					consec++;
				}
				else {
					if (consec > highest) {
						highest = consec;
						higha = a;
						highb = b;
					}
					break;
				}
			}
		}
	}
	cout << highest << " for a = " << higha << " and b = " << highb << " and product = " << higha*highb;
	return 0;
}
