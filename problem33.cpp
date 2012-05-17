#include <iostream>
#include <math.h>

using namespace std;

bool samefraction(int a, int b, int c, int d) {
	if ((a == 0 && c != 0) || (c == 0 && a != 0))
		return false;
	if ((b == 0 && d != 0) || (b == 0 && d != 0))
		return false;
	if (a * d == b * c)
		return true;
	return false;
}

void simplify(int& n, int& d) {
	for (int i = 1; i < n; i++) {
		for (int j = i; j < d; j++) {
			if (samefraction(n, d, i, j)) {
				n = i;
				d = j;
			}
		}
	}
}

//a = 42 b = 2 gives true, a = 42 b = 9 gives false
bool contains(int a, int b) {
	if (a / 10 == b || a % 10 == b)
		return true;
	return false;
}

//a = 42 b = 4 gives 2, a = 53 b = 3 gives 5
int otherdigit(int a, int b) {
	if (a / 10 == b)
		return a % 10;
	if (a % 10 == b)
		return a / 10;
	return -1;
}

int main() {
	int arrN[4], arrD[4];
	int index = 0;
	for (int i = 10; i < 100; i++) {
		for (int j = i+1; j < 100; j++) {
			for (int k = 1; k < 10; k++) {
				int a = otherdigit(i, k);
				int b = otherdigit(j, k);
				if (a > 0 && b > 0) {
					if (samefraction(i,j,a,b)) {
						arrN[index] = a;
						arrD[index] = b;
						index++;
					}
				}
			}
		}
	}
	int nom = 1;
	int denom = 1;
	for (int i = 0; i < 4; i++) {
		nom *= arrN[i];
		denom *= arrD[i];
	}
	simplify(nom,denom);
	cout << denom;
	return 0;
}