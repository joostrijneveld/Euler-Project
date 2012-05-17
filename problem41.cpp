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

int tenthpower(int n) {
	int prod = 1;
	while (n > 0) {
		prod *= 10;
		n--;
	}
	return prod;
}

bool ispandigital(long int no) {
	int len = log10(no) + 1;
	for (int i=1;i<=len;i++) {
		bool found = false;
		int tempno = no;
		for (int j=len-1;j>=0;j--) {
			if (tempno / tenthpower(j) == i) {
				found = true;
				break;
			}
			tempno -= (tempno / tenthpower(j)) * tenthpower(j);
		}
		if (!found) {
			return false;
		}
	}
	return true;
}

int main() {
	int i = 2;
	while (true) {
		if (ispandigital(i) && isprime(i)) {
			cout << i << endl;
		}
		i++;
	}
	return 0;
}
