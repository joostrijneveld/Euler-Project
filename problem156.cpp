#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int number_of_d_in_n(int n, int d) {
	int r = 0;
	while (n > 0) {
		if (n % 10 == d) {
			r++;
		}
		n /= 10;
	}
	return r;
}

int f(int n,int d) {
	int a = 0;
	for (int i = 0; i <= n; i++) {
		a += number_of_d_in_n(i,d);
	}
	return a;
}

int main() {
	//for (int n = 0; n < 200000; n++) {
	//	if (n == f(n,1)) {
	//		cout << n << endl;
	//	}
	//}
}