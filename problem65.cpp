#include <iostream>
#include <math.h>

using namespace std;

int sumofdigits(int a) {
	if (a < 10) {
		return a;
	}
	return a % 10 + sumofdigits(a/10);
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	for (int j = 3; j <= 10; j++) {
		const int x = j;
		int n = 1;
		int d = 0;
		if ((x-2) % 3 == 0 || (x-2) % 3 == 2)
			d = 1;
		else
			d = 2 * ((x-2)/3+1);
		int esum = 0;
		for (int e = x-3; e >= 0; e--) {
			esum += e;
			int f;
			if (e % 3 == 0 || e % 3 == 2)
				f = 1;
			else
				f = 2 * (e/3+1);
			n += f*d;
			swap(d, n);
		}
		cout << d<< endl;
		//cout << j;
		n += 2*d;
		//cout << n << '/' << d << endl;
	}
	return 0;
}