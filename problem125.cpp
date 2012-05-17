#include <iostream>
#include <math.h>
#include "bigint/BigIntegerLibrary.hh"

using namespace std;

int diglen(int a) {
	return log10(a)+1;
}

int digitatindex(int n, int i, int l) {
	return (n % (int)pow(10,(l-i))) / pow(10,l-i-1);
}
bool ispalindrome(int n) {
	int l = diglen(n);
	for (int i = 0; i < l/2; i++) {
		if (digitatindex(n,i,l) != digitatindex(n,l-i-1,l))
			return false;
	}
	return true;
}

bool conseqsquaresum(int n) {
	int a = sqrt(n);
	for (int i = a; i > 1; i--) {
		int togo = n-i*i;
		for (int j = i-1; j > 0; j--) {
			togo -= j*j;
			if (togo == 0)
				return true;
			if (togo < 0)
				break;
		}
	}
	return false;
}

int main() {
	int palindromes[19998];
	int count = 0;
	for (int i = 1; i < 100000000; i++) {
		if (ispalindrome(i)) {
			palindromes[count] = i;
			count++;
		}
	}
	BigInteger sum = 0;
	for (int i = 0; i < count; i++) {
		if (conseqsquaresum(palindromes[i])) {
			sum += palindromes[i];
			cout << palindromes[i] << endl;
		}
	}
	cout << sum;
	return 0;
}