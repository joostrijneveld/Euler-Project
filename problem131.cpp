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

bool iscube(int n) {
	if ((int)pow(n,(double)1/3) * (int)pow(n,(double)1/3) * (int)pow(n,(double)1/3) == n) {
		return true;
	}
	return false;
}

int main() {
	int max = 100;
	int primes[78497];
	int count = 0;
	for (int i = 3; i < max; i += 2) {
		if (isprime(i)) {
			primes[count] = i;
			count++;
		}
	}
	int amount = 0;
	for (int i = 0; i < count; i++) {
		for (int n = 0; n < 100; n++) {
			if (iscube(n*n*(n+primes[i]))) {
				amount++;
				break;
			}
		}
	}
	cout << amount;
}