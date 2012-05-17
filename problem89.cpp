#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include <fstream>
#include "bigint/BigIntegerLibrary.hh"

using namespace std;
string romanizebelow10(int n,string a,string b,string c) {
	if (n == 0) {
		return "";
	}
	if (n <= 3) {
		return string(n, a[0]);
	}
	if (n == 4) {
		return a+b;
	}
	if (n == 5) {
		return b;
	}
	if (n <= 8) {
		return b+string(n-5, a[0]);
	}
	if (n == 9) {
		return a+c;
	}
	return c;
}
string romanize(int n) {
	return string(n/1000,'M') + romanizebelow10(n%1000 / 100,"C","D","M") + romanizebelow10(n%100 / 10,"X","L","C") + romanizebelow10(n%10,"I","V","X");
}
int roman2int(string roman) {
	int n = 0;
	while (roman.substr(0,1) == "M") {
		n += 1000;
		roman = roman.substr(1,roman.length());
	}
	while (roman.substr(0,1) == "D") {
		n += 500;
		roman = roman.substr(1,roman.length());
	}
	while (roman.substr(0,1) == "C") {
		n += 100;
		roman = roman.substr(1,roman.length());
	}
	while (roman.substr(0,1) == "L") {
		n += 50;
		roman = roman.substr(1,roman.length());
	}
	while (roman.substr(0,1) == "X") {
		n += 10;
		roman = roman.substr(1,roman.length());
	}
	while (roman.substr(0,1) == "V") {
		n += 5;
		roman = roman.substr(1,roman.length());
	}
	while (roman.substr(0,1) == "I") {
		n += 1;
		roman = roman.substr(1,roman.length());
	}
	return n;
}
int main() {
	int sumfirst, sumlast;
	string line, roman;
	ifstream myfile ("roman.txt");
	if (myfile.is_open()) {
		while (!myfile.eof()) {
			getline(myfile,line);
			roman = romanize(roman2int(line));
			//cout << line << " " << line.length()-1 << " " << roman << " "<< roman.length() << "\n";
			sumfirst += line.length()-1;
			sumlast += roman.length();
		}
		myfile.close();
	}
	else {
		cout << "Unable to open file";
	}
	sumfirst++;
	cout << sumfirst << "-" << sumlast << "=" << sumfirst-sumlast;
	return 0;
}