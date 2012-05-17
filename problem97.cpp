#include <iostream>
#include <math.h>
#include "bigint/BigIntegerLibrary.hh"
#include <sstream>
#include <string>

using namespace std;

string int2str (long n) {
	stringstream ss;
	ss << n;
	return ss.str();
}
long str2int (string str) {
	stringstream ss(str);
	long n;
	ss >> n;
	return n;
}

int main() {
	int count = 1;
	long n = 2;
	string str;
	while (count < 7830457) {
		count++;
		n *= 2;
		if (n >= 1000000000) {
			str = int2str(n);
			str = str.substr(str.length()-10,10);
			n = str2int(str);
		}
	}
	BigInteger a = n;
	cout << a * (BigInteger)28433 << " and add 1 ";
	
	return 0;
}