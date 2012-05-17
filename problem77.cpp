#include <iostream>
#include <math.h>

using namespace std;

int primes[10000];
int backtrackarr[10001][10001];

int amountofoptions(int max, int sum) {
	if (backtrackarr[max][sum] > -1)
		return backtrackarr[max][sum];
	int count = 0;
	for (int i = 0; i <= max; i++) {
		if (sum == primes[i]) {
			count++;
		}
		else if (sum > primes[i]) {
			count += amountofoptions(i, sum-primes[i]);
		}
		else {
			break;
		}
	}
	backtrackarr[max][sum] = count;
	return count;
}

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

int main() {
	int total = 1;
	primes[0] = 2;
	const int max = 1000;
	for (int i = 3; i <= max; i += 2) {
		if (isprime(i)) {
			primes[total] = i;
			total++;
		}
	}
	for (int i = 0; i < 10001; i++) {
		for (int j = 0; j < 10001; j++) {
			backtrackarr[i][j] = -1;
		}
	}
	int a = 9;
	int highest = 2;
	int val = 0;
	while (highest < 5000) {
		int opt = amountofoptions(10000,a);
		if (opt > highest) {
			highest = opt;
			val = a;
		}
		a++;
	}
	cout << highest << " " << val;
}