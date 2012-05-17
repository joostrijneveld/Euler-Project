#include <iostream>
#include <math.h>
using namespace std;

bool issquare(int n) {
	if ((int)sqrt(n) * (int)sqrt(n) == n) {
		return true;
	}
	return false;
}

bool iscube(int n) {
	if ((int)pow(n,(double)1/3) * (int)pow(n,(double)1/3) * (int)pow(n,(double)1/3) == n) {
		return true;
	}
	return false;
}

int main() {
	int l = 10000;
	int smallest = l*3;
	for (int z = 1; z < l; z++) {
		for (int y = z+1; y < l; y++) {
			for (int x = y+1; x < l; x++) {
				if (x+y+z < smallest) {
					if (issquare(x+y)) {
						if (issquare(x-y)) {
							if (issquare(x+z)) {
								if (issquare(x-z)) {
									if (issquare(y+z)) {
										if (issquare(y-z)) {
											smallest = x+y+z;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout << smallest;
	return 0;
}