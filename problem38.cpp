#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include "bigint/BigIntegerLibrary.hh"

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
bool ispandigital(int n) {
	int arr[9];
	string nstring;
	nstring = int2str(n);
	for (int i = 0;i<9;i++) {
		arr[i] = 0;
	}
	for (int i=0;i<nstring.length();i++) {
		if (++arr[str2int(nstring.substr(i,1))-1] > 1) {
			return false;
		}
	}
	for (int i=0;i<9;i++) {
		if (arr[i] != 1) {
			return false;
		}
	}
	return true;
}

int main() {
	for (int i=1;i<500000000;i++) {
		int arr[9];
		string concat = "";
		for (int j=1;j<10;j++) {
			concat += int2str(i*j);
			if (ispandigital(str2int(concat))) {
				cout << i << " " << j << " " << concat << "\n";
			}
		}
	}
	
	return 0;
}