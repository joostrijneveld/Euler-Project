/*
 *  problem37.cpp
 *  Euler Project
 *
 *  Created by Joost on 31-07-10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include "bigint/BigIntegerLibrary.hh"

using namespace std;

bool isprime(long int no) {
	if (no == 2) {
		return true;
	}
	if (no % 2 == 0 || no == 1) {
		return false;
	}
	for (long int i = 3; i<=sqrt(no);i+=2) {
		if (no % i == 0) {
			return false;
		}
	}
	return true;
}
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

int main () {
	int n;
	int a;
	string nstring;
	string orinstring;
	int sum = 0;
	bool flag;
	int count;
	for (int n=10;n<1000000000;n++) {
		//n = 3797;
		if (isprime(n)) {
			flag = true;
			orinstring = int2str(n);
			a = orinstring.length();
			//left to right
			for (int j = 1;j<a;j++) {
				nstring = orinstring.substr(j,a-j);
				if (!isprime(str2int(nstring))) {
					flag = false;
					break;
				}
			}
			if (flag == false) {
				continue;
			}
			//right to left
			for (int j = 1;j<a;j++) {
				nstring = orinstring.substr(0,a-j);
				if (!isprime(str2int(nstring))) {
					flag = false;
					break;
				}
			}
			if (flag == true) {
				cout << n << "\n";
				sum += n;
				count++;
				if (count == 11) {
					break;
				}
			}
		}
	}
	cout << "sum: " << sum;
	return 0;
}