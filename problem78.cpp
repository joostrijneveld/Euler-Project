#include <iostream>
#include "bigint/BigIntegerLibrary.hh"

using namespace std;

const int maxlim = 5001;

BigInteger backtrackarr[maxlim][maxlim];

BigInteger amountofoptions(int max, int sum) {
	if (backtrackarr[max][sum] > -1)
		return backtrackarr[max][sum];
	BigInteger count = 0;
	for (int i = 1; i <= max; i++) {
		if (sum == i) {
			count ++;
		}
		else if (sum > i) {
			count += amountofoptions(i, sum-i);
		}
		else {
			break;
		}
	}
	backtrackarr[max][sum] = count;
	return count;
}

int main() {
	for (int i = 0; i < maxlim; i++) {
		for (int j = 0; j < maxlim; j++) {
			backtrackarr[i][j] = -1;
		}
	}
	for (int i = 1001; i < maxlim; i++) {
		BigInteger a = amountofoptions(i-1,i)+1;
		if (a / 1000000 * 1000000 == a) {
			cout << i;
			break;
		}
	}
	return 0;
}