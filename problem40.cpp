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
int main() {
	string alltogether;
	for (int i = 0;i<1000000;i++) {
		alltogether += int2str(i);
	}
	cout <<
	str2int(alltogether.substr(1,1)) *
	str2int(alltogether.substr(10,1)) *
	str2int(alltogether.substr(100,1)) *
	str2int(alltogether.substr(1000,1)) *
	str2int(alltogether.substr(10000,1)) *
	str2int(alltogether.substr(100000,1)) *
	str2int(alltogether.substr(1000000,1));
}