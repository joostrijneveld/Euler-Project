#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include "bigint/BigIntegerLibrary.hh"

using namespace std;

bool isinarr(int n, int ar[60]) {
	for (int i = 0;i<60;i++) {
		if (n == ar[i]) {
			return true;
		}
	}
	return false;
}

int factorial(int n) {
	return n <= 1 ? 1 : n * factorial(n-1);
}
string int2str (int n) {
	stringstream ss;
	ss << n;
	return ss.str();
}
int str2int (string str) {
	stringstream ss(str);
	int n;
	ss >> n;
	return n;
}
int f(int n) {
	string str = int2str(n);
	int sum = 0;
	for (int i=0;i<str.length();i++) {
		sum += factorial(str2int(str.substr(i,1)));
	}
	return sum;
}
int sf(int n) {
	string str = int2str(f(n));
	int sum = 0;
	for (int i=0;i<str.length();i++) {
		sum += str2int(str.substr(i,1));
	}
	return sum;
}
int g(int i) {
	int n = 1;
	while (true) {
		if (sf(n) == i) {
			return n;
		}
		n++;
	}
}
int sg(int i) {
	string str = int2str(g(i));
	int sum = 0;
	for (int i=0;i<str.length();i++) {
		sum += str2int(str.substr(i,1));
	}
	return sum;
}

int main () {
	int sum = 0;
	/*for (int i=1;i<=150;i++) {
		sum += sg(i);
		cout << i << " " << sg(i) << " " << sum << "\n";
	}*/
	cout << g(42);
	//cout << sum;
	return 0;
}