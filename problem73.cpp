#include <iostream>

using namespace std;

bool lookbackArray[12000][12000];

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
	for (int d = 1; d <= 12000; d++) {
		for (int n = d / 3; n < (double)d / 2; n++) {
			if (n*3 > d) {
				int n1 = n;
				int d1 = d;
				simplify(n1, d1);
				if (!lookbackArray[n1][d1]) {
					lookbackArray[n1][d1] = true;
					count++;
				}
			}
		}
	}
	cout << count;
	return 0;
}