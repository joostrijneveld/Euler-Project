#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include "bigint/BigIntegerLibrary.hh"

using namespace std;

BigInteger biginvert(BigInteger n) {
	string str = bigIntegerToString(n), str2 = "";
	for (int i=str.length()-1;i>-1;i--) {
		str2 += str.substr(i,1);
	}
	return stringToBigInteger(str2);
}

bool ispalindrome(BigInteger no) {
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

int main () {
	int n = 0;
	BigInteger tempsum;
	for (int i=0;i<10000;i++) {
		tempsum = i;
		for (int j=0;j<50;j++) {
			tempsum = tempsum + biginvert(tempsum);
			//cout << tempsum << "\n";
			if (ispalindrome(tempsum)) {
				n++;
				break;
			}
		}
	}
	cout << n << "palindromes found, so " << 10000-n << " lychrels";
	return 0;
}