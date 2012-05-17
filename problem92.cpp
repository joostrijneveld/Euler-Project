#include <iostream>

using namespace std;

int sumOfSquareOfDigits(int n) {
	int res = 0;
	while (n > 0) {
		int a = n % 10;
		n /= 10;
		res += a * a;
	}
	return res;
}

int main() {
	int count = 0;
	for (int i = 1; i < 10000000; i++) {
		int n = i;
		while (true) {
			n = sumOfSquareOfDigits(n);
			if (n == 1) {
				break;
			}
			if (n == 89) {
				count++;
				break;
			}
		}
	}
	cout << count;
}