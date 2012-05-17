#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include "bigint/BigIntegerLibrary.hh"

using namespace std;

int T(int n, int p) {
	int s[n];
	s[0] = 290797;
	for (int i=1;i<=n;i++) {
		s[i] = (s[i-1]*s[i-1]) % 50515093;
	}
	return s[n] % p;
}

int N(int p, int q) {
	int sum = 0;
	for (int n = 0;n<=q;n++) {
		sum += T(n,p)*pow(p,n);
	}
	return sum;
}
int factorial(int n) {
	return n <= 1 ? 1 : n * factorial(n-1);
}
int NFac(int p, int q) {
	return factorial(N(p,q));
}
int NF (int p, int q) {
	int r = 0;
	int n = NFac(p,q);
	for (int i = 1;i<=sqrt(n);i++) {
		if (n%i == 0) {
			r++;
		}
	}
	return r*2;
}
int main() {
	int threepow20 = pow(3,20);
	cout << NF(3,10000) % threepow20;
	return 0;
}