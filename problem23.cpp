#include <iostream>
#include <math.h>

using namespace std;

bool is_abundant(int n) {
	//since n is added once too many for i=1
	int sum = -n;
	for (int i = 1;i<sqrt(n);i++) {
		if (n % i == 0) {
			sum += i;
			sum += n/i;
		}
	}
	if (sqrt(n) == (int)sqrt(n)) {
		sum += sqrt(n);
	}
	//cout << sum;
	if (sum > n) {
		return true;
	}
	return false;
}

int main() {
	int sum = 0;
	for (int i = 1; i<28123;i++) {
		bool found_sum = false;
		for (int j = 1; j<i;j++) {
			if (is_abundant(j) && is_abundant(i-j)) {
				found_sum = true;
				break;
			}
		}
		if (!found_sum) {
			
			sum += i;
			cout << sum << endl;
		}
	}
	cout << sum;
	return 0;
}