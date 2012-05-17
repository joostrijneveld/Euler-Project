#include <iostream>

using namespace std;

int main() {
	int smallN = 1;
	int smallD = 1000000;
	for (int d = 1; d <= 1000000; d++) {
		for (int n = smallN * (d / smallD); n < 3 * (double)d / 7; n++) {
			if (n*smallD > d*smallN) {
				smallN = n;
				smallD = d;
			}
		}
	}
	cout << smallN << '/' << smallD;
	return 0;
}