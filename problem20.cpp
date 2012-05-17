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

string int2str (BigInteger n) {
	stringstream ss;
	ss << n;
	return ss.str();
}

int sumofdigits(BigInteger n) {
	string str = int2str(n);
	int sum = 0;
	for (int i=0;i<str.length();i++) {
		sum += str2int(str.substr(i,1));
	}
	return sum;
}

int main(void) {
	BigInteger a = 1;
	for (int i=2;i<=100;i++) {
		a *= i;
	}
	cout << sumofdigits(a);
    return 0;
}


