#include <iostream>

using namespace std;

/*
 * a = n2 - m2
 * b = 2nm
 * c = n2 + m2
*/ 

bool isDivider(int a, int b) {
	if (b % a == 0) {
		return true;
	}
	return false;
}

int main() {
	int n = 2, m = 1;
	int amount = 0;
	int maxp = 100000000;
	while ((n*n+n*m)*2 < maxp) {
		if (isDivider(2*n*m - n*n + m * m, n*n + m * m)) {
			amount += maxp/((n*n+n*m)*2);
		}
		m++;
		if (m >= n) {
			m = 1;
			n++;
		}
	}
	cout << amount;
}