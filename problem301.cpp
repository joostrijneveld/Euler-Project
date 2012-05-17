#include <iostream>
#include <math.h>

using namespace std;

int X(int a, int b, int c) {
	return a ^ b ^ c;
}

int main() {
	cout << X(1,2,3);
}