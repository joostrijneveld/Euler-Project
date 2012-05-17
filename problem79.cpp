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

int main () {
	string digits[] = { "319","680","180","690","129","620","762","689","762","318","368","710","720","710","629","168","160","689","716","731","736","729","316","729","729","710","769","290","719","680","318","389","162","289","162","718","729","319","790","680","890","362","319","760","316","729","380","319","728","716" };
	string temp;
	int a,b,c;
	bool flag;
	for (int i=100;i<1000000000;i++) {
		flag = true;
		for (int j=0;j<50;j++) {
			temp = int2str(i);
			a = temp.find(digits[j].substr(0,1));
			if (a + 1 > 0) {
				b = temp.find(digits[j].substr(1,1), a);
				if (b + 1 > 0) {
					c = temp.find(digits[j].substr(2,1), b);
					if (c + 1 == 0) {
						flag = false;
						break;
					}
				}
				else {
					flag = false;
					break;
				}
			}
			else {
				flag = false;
				break;
			}
		}
		if (flag == true) {
			cout << i;
			break;
		}
	}
	return 0;
}