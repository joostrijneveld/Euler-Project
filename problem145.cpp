#include <iostream>
#include <math.h>
using namespace std;

int digitlength(int a) {
	return log10(a)+1;
}

int reverseF(int n) {
	int l = digitlength(n);
	int r = 0;
	for (int i = l-1; i >= 0; i--) {
		r += pow(10,i)*(n % 10);
		n /= 10;
	}
	return r;
}

int onlyOdd(int n) {
	while (n > 0) {
		if ((n % 10) % 2 == 0) {
			return false;
		}
		n /= 10;
	}
	return true;
}

int main() {
	int amount = 0;
	for (int i = 1; i < 1000000000; i++) {
		if (i % 10 > 0) {
			if (onlyOdd(i + reverseF(i))) {
				amount++;
			}
		}
	}
	cout << amount;
}