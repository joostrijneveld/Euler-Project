#include <iostream>
#include <math.h>
#include <string>
#include <sstream>

using namespace std;

bool ispalindrome(int no) {
	string nstring;
	stringstream stream;
	stream << no;
	nstring = stream.str();
	for (int i=0;i<nstring.length() / 2;i++) {
		if (nstring[i] != nstring[nstring.length()-i-1]) {
			return false;
		}
	}
	return true;
}
bool isstrpalindrome(string nstring) {
	for (int i=0;i<nstring.length() / 2;i++) {
		if (nstring[i] != nstring[nstring.length()-i-1]) {
			return false;
		}
	}
	return true;
}
string int2bin(int n) {
	string bin = "";
	int highexp = 0;
	while (true) {
		highexp++;
		if (pow(2,highexp) > n) {
			break;
		}
	}
	highexp--;
	while (highexp >= 0) {
		if (n - pow(2,highexp) >= 0) {
			n -= pow(2,highexp);
			bin += "1";
		}
		else {
			bin += "0";
		}
		highexp--;
	}
	return bin;
}

int main() {
	int sum = 0;
	cout <<int2bin(100) << "\n";
	for (int i = 0;i<1000000;i++) {
		if (ispalindrome(i) && isstrpalindrome(int2bin(i))) {
			sum += i;
		}
	}
	cout << sum;
	return 0;
}


