#include <iostream>
#include <math.h>
#include <sstream>
#include <string>

using namespace std;

int sqlen (long int n) {
	int len = 1;
	while (n > 1) {
		if (n%2 == 0) {
			n /= 2;
		}
		else {
			n = 3*n+1;
		}
		len++;
	}
	return len;
}

int main ()
{
	int highest = 0;
	int res;
	int len;
	for (int i=0;i<1000000;i++) {
		len = sqlen(i);
		if (len > highest) {
			cout << i << " gives: " << len << "\n";
			highest = len;
			res = i;
		}
	}
	cout << res;
	return 0;
}

