#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include "bigint/BigIntegerLibrary.hh"

using namespace std;

int main() {
	//for (int a = 3; a <= 1000; a++) {
	int a = 7;
	long long r;
	for (int n = 0; n < 100; n++) {
		r = (long long)(pow(a-1, n) + pow(a+1, n)) % (a*a);
		cout << r << endl;
	}
	//}
	return 0;
}