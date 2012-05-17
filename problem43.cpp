#include <iostream>
#include <math.h>
#include "bigint/BigIntegerLibrary.hh"

using namespace std;

int combineddigit(int arr [],int a, int b, int c) {
	return arr[a]*100 + arr[b]*10 + arr[c];
}

int tenthpower(int n) {
	int prod = 1;
	while (n > 0) {
		prod *= 10;
		n--;
	}
	return prod;
}

int arr2int(int arr[]) {
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		sum += arr[9-i]*tenthpower(i);
	}
	return sum;
}

int main() {
	int arr[10] = {0,1,2,3,4,5,6,7,8,9};
	cout << arr2int(arr) << endl;
	BigInteger sum = 0;
	do {
		if (arr[0] > 0) {
			if (combineddigit(arr,1,2,3) % 2 != 0) continue;
			if (combineddigit(arr,2,3,4) % 3 != 0) continue;
			if (combineddigit(arr,3,4,5) % 5 != 0) continue;
			if (combineddigit(arr,4,5,6) % 7 != 0) continue;
			if (combineddigit(arr,5,6,7) % 11 != 0) continue;
			if (combineddigit(arr,6,7,8) % 13 != 0) continue;
			if (combineddigit(arr,7,8,9) % 17 != 0) continue;
			cout << arr[0] << " " << arr2int(arr) << endl;
			sum += arr2int(arr);
		}
	} while ( next_permutation( arr, arr + 10 ) );
	cout << sum;
	return 0;
}
