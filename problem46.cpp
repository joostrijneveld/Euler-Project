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

bool issquare(int n) {
	if ((int)sqrt(n) * (int)sqrt(n) == n) {
		return true;
	}
	return false;
}

int main() {
	int max = 1000000;
	int primes[78497];
	int count = 0;
	for (int i = 3; i < max; i += 2) {
		if (isprime(i)) {
			primes[count] = i;
			count++;
		}
	}	
	int i = 9;
	while (true) {
		if (!isprime(i)) {
			bool flag = false;
			for (int j = 0; primes[j] < i; j++) {
				int n = i - primes[j];
				if (issquare(n/2)) {
					flag = true;
					break;
				}
			}
			if (!flag) {
				cout << i;
				return 0;
			}
		}
		i += 2;
	}
	return 0;
}