#include <iostream>
#include <sstream>
#include <string>

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
bool comparechars(string a, string b) {
	int arrA[10];
	int arrB[10];
	for (int i = 0;i<10;i++) {
		arrA[i] = 0;
		arrB[i] = 0;
	}
	for (int i = 0;i<a.length();i++) {
		arrA[str2int(a.substr(i,1))] ++;
	}
	for (int i = 0;i<b.length();i++) {
		arrB[str2int(b.substr(i,1))] ++;
	}
	bool flag = true;
	for (int i=0;i<10;i++) {
		if (arrA[i] != arrB[i]) {
			flag = false;
		}
	}
	return flag;
}

int main() {
	bool flag;
	for (int i=100000;i<1000000;i++) {
		flag = false;
		for (int j=2;j<=6;j++) {
			if (comparechars(int2str(i),int2str(i*j))) {
				flag = true;
			}
			else {
				flag = false;
				break;
			}
		}
		if (flag == true) {
			cout << i << " WIN!";
			break;
		}
	}
	return 0;
}