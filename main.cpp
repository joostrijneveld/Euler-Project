#include <iostream>
#include <math.h>
#include <sstream>
#include <string>

using namespace std;

int divisors (int n) {
	int r = 0;
	for (int i = 1;i<=sqrt(n);i++) {
		if (n%i == 0) {
			r++;
		}
	}
	return r*2;
}

int main ()
{
	int triangle;
	int inc;
	while (true) {
		inc++;
		triangle += inc;
		if (divisors(triangle) > 500) {
			cout << "500 divisors found for n = " << triangle;
			break;
		}
	}
	return 0;
}