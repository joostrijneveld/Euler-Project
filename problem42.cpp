#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

bool istriangle(int t) {
	double n = (-1 + sqrt(1+ 8 * t))/2;
	if (n == (int)n) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	ifstream words("words.txt");
	int count = 0;
	if (words) {
		char c;
		int wordvalue = 0;
		while (words.get(c)) {
			if (c == ' ') {
				if (istriangle(wordvalue)) {
					count++;
				}				
				wordvalue = 0;
			}
			else {
				wordvalue += (int)c-64;
			}
		}
	}
	else {
		cout << "FAIL";
	}
	cout << count;
	return 0;
}
