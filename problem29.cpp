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

bool isinbigarr(BigInteger n, BigInteger ar[10000]) {
	for (int i = 0;i<10000;i++) {
		if (n == ar[i]) {
			return true;
		}
	}
	return false;
}

int main() {
	int alow = 2, ahigh = 100, blow = 2, bhigh = 100;
	BigInteger arr[10000];
	BigInteger temp;
	int terms = 0;
	int counter = 0;
	for (int i = 0;i<10000;i++) {
		arr[i] = 0;
	}
	for (int i = alow;i<=ahigh;i++) {
		for (int j = blow;j<=bhigh;j++) {
			temp = bigpow(i,j);
			if (!isinbigarr(temp,arr)) {
				arr[counter] = temp;
			}
			counter++;
		}
	}
	for (int i=0;i<10000;i++) {
		//cout << arr[i];
		if (arr[i] != 0) {
			terms++;
		}
	}
	cout << terms;
	return 0;
}