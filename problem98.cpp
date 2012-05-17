#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "bigint/BigIntegerLibrary.hh"

using namespace std;

vector<string> words[15];
vector<string> anagramwords[15];

bool issquare(int n) {
	if ((int)sqrt(n) * (int)sqrt(n) == n) {
		return true;
	}
	return false;
}

BigInteger squareformed(string a) {
	
}

bool isanagram (string a, string b) {
	if (a == b || a.length() != b.length())
		return false;
	int arr[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int arr2[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	for (int i = 0; i < a.length(); i++) {
		arr[(int)a[i]-65]++;
		arr2[(int)b[i]-65]++;
	}
	for (int i = 0; i < 26; i++) {
		if (arr[i] != arr2[i]) {
			return false;
		}
	}
	return true;
}

bool hasanagram(string a) {
	vector<string> vec = words[a.length()];
	for (int j = 0; j < vec.size(); j++) {
		if (isanagram(vec[j],a))
			return true;
	}
	return false;
}

int main() {
	ifstream file ("words98.txt");
	if (file) {
		for (int i = 0; i < 2000; i++) {
			string a;
			file >> a;
			if (a.length() == 0)
				break;
			words[a.length()].push_back(a);
		}
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < words[i].size(); j++) {
				if (hasanagram(words[i][j]))
					anagramwords[i].push_back(words[i][j]);
			}
		}
		BigInteger max = 0;
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < anagramwords[i].size(); j++) {
				BigInteger a = squareformed(anagramwords[i][j]);
				if (a > max)
					max = a;
			}
		}
		cout << max;
	}
	else {
		cout << "failed opening file";
	}
	return 0;
}