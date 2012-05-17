#include <iostream>
#include <math.h>
#include <sstream>
#include <string>

using namespace std;
int str2int (string str) {
	stringstream ss(str);
	int n;
	ss >> n;
	return n;
}

string int2str (int n) {
	stringstream ss;
	ss << n;
	return ss.str();
}

int fifthpowersumofdigits(int n) {
	string str = int2str(n);
	int sum = 0;
	for (int i=0;i<str.length();i++) {
		sum += pow(str2int(str.substr(i,1)),5);
	}
	return sum;
}

int main() {
	int sum = 0;
	for (int i=2;i<1000000;i++) {
		if (i == fifthpowersumofdigits(i)) {
			sum += i;
		}
	}
	cout << sum;
	return 0;
}