#include <math.h>
#include <iostream>

using namespace std;


bool istriangle(int t) {
	double n = (-1 + sqrt((int)1+ t * (int)8))/2;
	if (n == (int)n) {
		return true;
	}
	else {
		return false;
	}
}

bool ispentagonal(int t) {
	double n = (1 + sqrt((int)1+(int)24*t))/6;
	if (n == (int)n) {
		return true;
	}
	else {
		return false;
	}
}

bool ishexagonal(int t) {
	double n = (1 + sqrt((int)1+t * (int)8))/4;
	if (n == (unsigned long int)n) {
		return true;
	}
	else {
		return false;
	}
}