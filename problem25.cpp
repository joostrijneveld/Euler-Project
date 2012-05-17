#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include "bigint/BigIntegerLibrary.hh"

using namespace std;

int main() {
	BigInteger n = 1, prev = 0, temp = 0, i = 1;
	string str;
	while (true) {
		i++;
		temp = prev;
		prev = n;
		n = temp + n;
		str = bigIntegerToString(n);
		if (str.length() == 1000) {
			cout << "term: " << i;
			break;
		}
	}
	return 0;
}

