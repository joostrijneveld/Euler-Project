#include <iostream>
#include <math.h>
#include <string>
#include <sstream>

using namespace std;

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
int factorialsumofdigits(int n) {
	string str = int2str(n);
	int sum = 0;
	for (int i=0;i<str.length();i++) {
		sum += factorial(str2int(str.substr(i,1)));
	}
	return sum;
}
int main() {
	int sum = 0;
	for (int i = 3;i<100000;i++) {
		if (factorialsumofdigits(i) == i) {
			sum += i;
		}
	}
	cout << sum;
	return 0;
}