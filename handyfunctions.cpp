#include <iostream>
#include <math.h>
#include <sstream>
#include <string>

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

bool isprime(long int no) {
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