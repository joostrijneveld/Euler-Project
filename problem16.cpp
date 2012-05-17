#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include "bigint/BigIntegerLibrary.hh"

using namespace std;

int str2int (string str) {
	stringstream ss(str);
	int n;
	ss >> n;
	return n;
}

int sumofdigits(BigInteger n) {
	string str = bigIntegerToString(n);
	int sum = 0;
	for (int i=0;i<str.length();i++) {
		sum += str2int(str.substr(i,1));
	}
	return sum;
}

int main(void) {
	BigInteger a = 2;
	for (int i=1;i<1000;i++) {
		a *= 2;
	}
	cout << sumofdigits(a);
    return 0;
}


