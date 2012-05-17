#include <iostream>
#include <math.h>
#include "bigint/BigIntegerLibrary.hh"
#include <sstream>
#include <string>

using namespace std;

BigInteger bigpow(int x,int a) {
	BigInteger product = x;
	for (int i=1;i<a;i++) {
		product *= x;
	}
	return product;
}

string int2str (int n) {
	stringstream ss;
	ss << n;
	return ss.str();
}
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
int main() {
	int sum, highest;
	for (int a=0;a<100;a++) {
		for (int b=0;b<100;b++) {
			sum = sumofdigits(bigpow(a,b));
			if (sum > highest) {
				highest = sum;
			}
		}
	}
	cout << highest;
	return 0;
}