#include <iostream>
#include <fstream>
#include <cstring>
#include "bigint/BigIntegerLibrary.hh"

using namespace std;

void sort_alphabetical(string array[]) {
	for (int i = 1; i < 5163; i++)
	{
		//the new value to be inserted into a temporary location 
		string nTemp = array[i];
		// k is the index of the number to the left of the iCv.
		int k;
		for (k = i-1; k >= 0 && array[k] > nTemp; k--) {
			array[k+1] = array[k];
		}
		array[k+1] = nTemp;
	}
}

int char_value(char c) {
	return (int)(c-64);
}

int main() {
	ifstream file ("names.txt");
	bool writeflag = false;
	char c;
	string arrayofstrings[5163];
	int count = 0;
	BigInteger sum = 0;
	while (file) {
		file >> c;
		if (c == ',') {
			continue;
		}
		if (c == '"') {
			writeflag = !writeflag;
			if (!writeflag) {
				count++;
			}
			continue;
		}
		if (writeflag) {
			arrayofstrings[count] += c;
		}
	}
	sort_alphabetical(arrayofstrings);
	for (int i=0;i<count;i++) {
		int smallsum = 0;
		//cout << arrayofstrings[i];
		for (int j=0;j<arrayofstrings[i].length();j++) {
			smallsum += char_value(arrayofstrings[i][j]);
		}
		sum += smallsum * (i+1);
		//cout << " " << smallsum * i << endl;
	}
	cout << sum;
}