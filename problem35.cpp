#include <iostream>
#include <math.h>
#include <string>
#include <sstream>

using namespace std;
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
bool isprime(int no) {
	if (no == 2) {
		return true;
	}
	if (no % 2 == 0 || no == 1) {
		return false;
	}
	for (long int i = 3; i<=sqrt(no);i+=2) {
		if (no % i == 0) {
			return false;
		}
	}
	return true;
}
bool circularprime(int n) {
	string nstring = int2str(n);
	string temp = "";
	for (int i = 0;i<nstring.length();i++) {
		temp = "";
		for (int j = 0;j<nstring.length();j++) {
			temp += nstring[(j+i) % nstring.length()];
		}
		if (!isprime(str2int(temp))) {
			return false;
		}
	}
	return true;
}

int main() {
	int c = 0;
	for (int i=2;i<1000000;i++) {
		if (circularprime(i)) {
			c++;
		}
	}
	cout << c;
	return 0;
}