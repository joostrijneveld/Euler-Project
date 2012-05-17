#include <iostream>
#include "BigIntegerLibrary.hh"
#include <math.h>

using namespace std;

double abs(double x) {
    if (x < 0) {
        return x*-1;
    }
    else {
        return x;
    }
}

BigInteger startvalue(BigInteger x) {
    int n = 0;
    while (n*n <= x) {
        n++;
    }
    return (n-1);
}

double f(double y, BigInteger x) {
    return y*y-x;
}

double df(double y) {
    return 2*y;
}

double bigSqrt(BigInteger x) {
    double xi = startvalue(x);
    while (!(abs(xi*xi-x) <= PRECISION)) {
        xi = xi - f(xi,x) / df(xi);
    }
	return xi;
}


bool istriangle(BigInteger t) {
	double n = (-1 + bigSqrt((BigInteger)1+ t * (BigInteger)8))/2;
	if (n == (int)n) {
		return true;
	}
	else {
		return false;
	}
}

bool ispentagonal(BigInteger t) {
	double n = (1 + bigSqrt((BigInteger)1+(BigInteger)24*t))/6;
	if (n == (BigInteger)n) {
		return true;
	}
	else {
		return false;
	}
}

bool ishexagonal(BigInteger t) {
	double n = (1 + bigSqrt((BigInteger)1+t * (BigInteger)8))/4;
	if (n == (unsigned long int)n) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	BigInteger arr [10000];
	unsigned int count = 0;
	BigInteger i = 1, dif = 5;
	while (count < 10000) {
		if (ishexagonal(i)) {
			arr[count] = i;
			count ++;
		}
		i += dif;
		dif += 4;
	}
	cout << "PART B" << endl;
	for (int a = 143; a < 10000; a++) {
		if (ispentagonal(arr[a])) {
			if (istriangle(arr[a])) {
				cout << arr[a];
				break;
			}
		}
	}
	return 0;
}