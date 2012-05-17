#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include "bigint/BigIntegerLibrary.hh"

using namespace std;

bool isinarr(int n, int ar[60]) {
	for (int i = 0;i<60;i++) {
		if (n == ar[i]) {
			return true;
		}
	}
	return false;
}

int factorial(int n) {
	return n <= 1 ? 1 : n * factorial(n-1);
}
string int2str (int n) {
	stringstream ss;
	ss << n;
	return ss.str();
}
int str2int (string str) {
	stringstream ss(str);
	int n;
	ss >> n;
	return n;
}
int factorialsumofdigits(int n) {
	string str = int2str(n);
	int sum = 0;
	for (int i=0;i<str.length();i++) {
		sum += factorial(str2int(str.substr(i,1)));
	}
	return sum;
}
int main() {
	int arr[60], i2, chains;
	for (int i=0;i<1000000;i++) {
		for (int j=0;j<60;j++) {
			arr[j] = 0;
		}
		arr[0] = i;
		i2 = factorialsumofdigits(i);
		for (int j=1;j<=60;j++) {
			if (!isinarr(i2,arr)) {
				arr[j] = i2;
				i2 = factorialsumofdigits(i2);
			}
			else {
				if (j == 60) {
					chains += 1;
				}
				break;
			}
		}
	}
	cout << chains;
	return 0;
}