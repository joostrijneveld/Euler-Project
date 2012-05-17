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
	for (int n = 1; n <= 1000000; n++) {
		count += laminae(n);
	}
	cout << count;
	return 0;
}