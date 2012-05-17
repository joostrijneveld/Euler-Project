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

int main() {
	int count = 0;
	int arr[78498];
	for (int i = 2; i < 1000000; i++) {
		if (isprime(i)) {
			arr[count] = i;
			count++;
		}
	}
	int highest = 0;
	int most = 0;
	for (int i = 0; i < 78498; i++) {
		int conseq = 0;
		for (int j = 0; j < i; j++) {
			int tempsum = 0;
			int tempconseq = 0;
			while (tempsum < arr[i]) {
				tempsum += arr[j+tempconseq];
				tempconseq += 1;
			}
			if (tempconseq > conseq && tempsum == arr[i]) {
				conseq = tempconseq;
			}
		}
		if (conseq > most) {
			highest = arr[i];
			most = conseq;
			cout << arr[i] << " " << most << endl;
		}
	}
	return 0;
}