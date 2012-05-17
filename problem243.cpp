#include <iostream>
#include <math.h>

using namespace std;

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

int R(int n) {
	int count = 0;
	for (int i = 1; i < n; i++) {
		int a = i;
		int b = n;
		simplify(a, b);
		if (a == i)
			count++;
	}
	return count;
}

int main() {
	int i = 1;
	while (R(i) * 94744 >= (i-1) * 15499)
		i++;
	cout << i;
	return 0;
}