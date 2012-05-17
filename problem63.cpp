#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include "bigint/BigIntegerLibrary.hh"

using namespace std;

BigInteger bigpow(int x,int a) {
	BigInteger product = 1;
	for (int i=0;i<a;i++) {
		product *= x;
	}
	return product;
}
int bigIntlen(int n) {
	return BigInteger.Log10(n)+1;
}
int intlen(int n) {
	return (int)log10(n)+1;
}

int main() {

	int amount = 0;
	for (int i = 1; i < 21; i++) {
		for (int j=1;j<10;j++) {
			string str = (string)bigpow(j,i);
			if (str.length() == i) {
				cout << str << "\n";
				amount++;
				break;
			}
			if (str.length() > i) {
				break;
			}
		}
	}
	cout << bigIntlen(100);
	cout << amount;
	return 0;
}