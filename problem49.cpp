#include <iostream>
#include <math.h>

using namespace std;

bool isprime(long int no) {
	if (no == 2) {
		return true;
	}
	if (no % 2 == 0 || no == 1) {
		return false;
	}
	for (long int i = 3; i<=sqrt(no);i+=2) {
		if (no % i == 0) {
			return false;
		}
	}
	return true;
}

bool containssamedigits(int a, int b) {
	bool arrA[] = {0,0,0,0,0,0,0,0,0};
	bool arrB[] = {0,0,0,0,0,0,0,0,0};
	for (int i = 9; i >= 0; i--) {
		int f = pow(10,i);
		if (a / f - 1 >= 0) {
			arrA[a / f - 1] += 1;
			a -= f * (a / f);
		}
		if (b / f - 1 >= 0) {
			arrB[b / f - 1] += 1;
			b -= f * (b / f);
		}
	}
	for (int i = 0; i < 9; i++) {
		if (arrA[i] != arrB[i])
			return false;
	}
	return true;
}

int main() {
	for (int i = 1; i < 3339; i++) {
		int a = i + 3330;
		int b = i + 6660;
		if (containssamedigits(i,a) && containssamedigits(i,b)) {
			if (isprime(i) && isprime(a) && isprime(b)) {
				cout << i << a << b << endl;
			}
		}
	}
	return 0;
}

