#include <iostream>

using namespace std;

bool lookbackArray[1000000][1000000];

int gcd(int a, int b) {
	if (a < b)
		return gcd(b,a);
	if (b == 0)
		return a;
	else
		return gcd(b,a % b);
}

void simplify(int& a, int& b) {
	int c = gcd(a,b);
	if (c > 1) {
		a /= c;
		b /= c;
	}
}

int main() {
	int count = 0;
	for (int d = 1; d <= 1000000; d++) {
		for (int n = 1; n < 1000000; n++) {
			int n1 = n;
			int d1 = d;
			simplify(n1, d1);
			if (!lookbackArray[n1][d1]) {
				lookbackArray[n1][d1] = true;
				count++;
			}
		}
	}
	cout << count;
	return 0;
}