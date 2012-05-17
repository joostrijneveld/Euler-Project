#include <iostream>
#include <math.h>

using namespace std;

int divisors(int n) {
	int count = 1;
	for (int i = 2; i < sqrt(n); i++) {
		if (n % i == 0)
			count++;
	}
	count *= 2;
	if (sqrt(n) == (int)sqrt(n))
		count++;
	return count;
}

int main() {
	int num = 0;
	int prevdiv = 1;
	for (int i = 2; i < 1e7; i++) {
		int divi = divisors(i);
		if (prevdiv == divi)
			num++;
		prevdiv = divi;
	}
	cout << num;
	return 0;
}