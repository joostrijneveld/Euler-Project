#include <iostream>
#include <math.h>
#include "bigint/BigIntegerLibrary.hh"

using namespace std;

BigInteger bigpow(int x,int a) {
	BigInteger product = x;
	for (int i=1;i<a;i++) {
		product *= x;
	}
	return product;
}

int main() {
	BigInteger sum;
	string str;
	for (int i=1;i<=1000;i++) {
		sum += bigpow(i,i);
	}
	str = bigIntegerToString(sum);
	cout << "last 10: " << str.substr(str.length()-10,10);
	return 0;
}
