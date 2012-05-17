#include <iostream>
#include <math.h>
#include <string>
#include <sstream>

using namespace std;

int sumofdivisors(int n) { //proper divisors, exclude n
	int sum = 0;
	for (int i=1;i<n;i++) {
		if (n % i == 0) {
			sum += i;
		}
	}
	return sum;
}

int main(void) {
	int sum,a,b,c;
	for  (a = 1;a<10000;a++) {
		b = sumofdivisors(a);
		if (a != b && a == sumofdivisors(b)) {
			sum += a;
			sum += b;
		}
	}
	cout << sum/2;
    return 0;
}


