#include <iostream>
#include <math.h>
#include "bigint/BigIntegerLibrary.hh"
#include <sstream>
#include <string>

using namespace std;

int main() {
	int c, win;
	int solutions = 0, highest = 0;
	for (int p = 0;p <= 1000; p++) {
		solutions = 0;
		for (int a = 1;a<p;a++) {
			for (int b = 1;b<p;b++) {
				c = p-a-b;
				if (c == sqrt(a*a+b*b)) {
					solutions++;
				}
			}
		}
		if (solutions > highest) {
			highest = solutions;
			win = p;
		}
	}
	cout << win;
	return 0;
}

