#include <iostream>
#include <math.h>

using namespace std;

int divisors(int n) {
	int count = 1;
	for (int i = 2; i < sqrt(n); i++) {
		if (n % i == 0)
			count++;
	}
	return count;
}

int laminae(int n) {
	if (n % 4 == 0 && n != 4)
		return divisors(n/4);
	return 0;
}

int main() {
	int count = 0;
	for (int t = 1; t <= 1000000; t++) {
		int l = laminae(t);
		if (l >= 1 && l <= 10)
			count++;
	}
	cout << count;
	return 0;
}