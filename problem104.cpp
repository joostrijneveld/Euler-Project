#include <iostream>
#include <math.h>
#include "bigint/BigIntegerLibrary.hh"
#include <string>

using namespace std;

int string2int(string str) {
	return atoi(str.c_str()); 	
}

bool is1to9pandigital(string str) {
	int concat = string2int(str);
	bool arr[] = {false,false,false,false,false,false,false,false,false};
	for (int i = 9; i >= 0; i--) {
		int f = pow(10,i);
		if (arr[concat / f - 1]) {
			return false;
		}
		arr[concat / f - 1] = true;
		concat -= f * (concat / f);
	}
	return true;
}

int main() {
	BigInteger oldest = 1;
	BigInteger old = 1;
	BigInteger n = 2;
	int k = 3;
	while (true) {
		string str = bigIntegerToString(n);
		int s = str.size();
		if (s >= 9) {
			if (is1to9pandigital(str.substr(s-9, 9))) {
				if (is1to9pandigital(str.substr(0, 9))) {
					cout << "k = " << k;
					break;
				};
				cout << k << endl;
			}
		}
		oldest = old;
		old = n;
		n = old + oldest;
		k++;
	}
	return 0;
}