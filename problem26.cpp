#include <iostream>
#include <math.h>
#include "bigint/BigIntegerLibrary.hh"

using namespace std;

string recurring(string str) {
	string cycle;
	for (int i=0;i<str.length();i++) {
		
	}
	return "aa";
}

bool ispattern(string haystack, string needle) {
	for (int i = 0;i<haystack.length();i+=needle.length()) {
		if (haystack.substr(i,needle.length()) == needle) {
			continue;
		}
		if (haystack.length() < i+needle.length()) {
			if (haystack.substr(i,haystack.length()-i) == needle.substr(0,haystack.length()-i)) {
				continue;
			}
		}
		return false;
	}
	return true;
}

int main() {
	BigInteger m = 1;
	for (int i=0;i<15;i++) {
		m *= 1000;
	}
	BigInteger dec;
	BigInteger check = 10;
	int highest, val;
	string temp;
	for (int d=2;d<10;d++) {
		dec = m/d;
		if ((dec / check) * check == dec) {
			continue;
		}
		temp = recurring(bigIntegerToString(dec));
		if (temp.length() > highest) {
			highest = temp.length();
			val = d;
		}
	}
	return 0;	
}


