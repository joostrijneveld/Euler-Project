#include <iostream>
#include <math.h>
#include "bigint/BigIntegerLibrary.hh"

using namespace std;

int digitlength(BigInteger a) {
	int r = 0;
	while (a > 0) {
		a /= 10;
		r++;
	}
	return r;
}

int main() {
	int count = 0;
	BigInteger n = 1, d = 0, temp;
	for (int i = 0; i <= 1000; i++) {
		temp = d;
		d = d+ d + n;
		n = temp;
		if (digitlength(n+d) > digitlength(d)) {
			count++;
		//	cout << i << " " << (n+d) << " / " << d << endl;
		}
		
		//
	}
	cout << count;
	return 0;
}