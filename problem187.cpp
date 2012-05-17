#include <iostream>
#include <math.h>

using namespace std;

bool isprime(int no) {
	if (no == 2)
		return true;
	if (no % 2 == 0 || no == 1)
		return false;
	for (int i = 3; i <= sqrt(no); i+=2) {
		if (no % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int count = 0;
	int primes[3001134];
	int max = 30;
	for (int i = 0; i < max/2; i++) {
		if (isprime(i)) {
			primes[count] = i;
			count++;
		}
	}
	int comps = 0;
	for (int i = 0; i < count; i++) {
		for (int j = i; j < count; j++) {
			if (primes[i] * primes[j] >= max)
				break;
			comps++;
		}
	}
	cout << comps;
	return 0;
}