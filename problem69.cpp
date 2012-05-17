#include <iostream>
#include <math.h>

using namespace std;

int phi(unsigned long x) {
	unsigned int ret = 1,i,pow;
	for (i = 2; x != 1; i++) {
		pow = 1;
		while (!(x%i)) {
			x /= i;
			pow *= i;
		}
		ret *= (pow - (pow/i));
	}
	return ret;
}


int main() {
	int highn = 0;
	double f = 0;
	for (int i=2; i<=1000000; i++) {
		int q = phi(i);
		if ((double)i/q > f) {
			f = (double)i/q;
			highn = i;
			cout << i << endl;
		}
	}
	cout << highn;
	return 0;
}

