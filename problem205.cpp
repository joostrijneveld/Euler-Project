#include <iostream>
#include <math.h>
#include "bigint/BigIntegerLibrary.hh"
#include <string>

#include <iomanip>

using namespace std;

int colinless(int n, int c[]) {
	int total = 0;
	for (int i=5;i<n;i++) {
		total += c[i];
	}
	return total;
}

int string2int(string str) {
	return atoi(str.c_str()); 	
}

int main() {
	int p[37], c[37];
	BigUnsigned total;
	for (int i=0;i<37;i++) {
		p[i] = 0;
		c[i] = 0;
	}
	for (int a = 1;a<5;a++) {
		for (int b = 1;b<5;b++) {
			for (int c = 1;c<5;c++) {
				for (int d = 1;d<5;d++) {
					for (int e = 1;e<5;e++) {
						for (int f = 1;f<5;f++) {
							for (int g = 1;g<5;g++) {
								for (int h = 1;h<5;h++) {
									for (int i = 1;i<5;i++) {
										p[a+b+c+d+e+f+g+h+i] ++;
									}						
								}
							}
						}						
					}
				}
			}
		}
	}
	for (int j = 1;j<7;j++) {
		for (int k = 1;k<7;k++) {
			for (int l = 1;l<7;l++) {
				for (int m = 1;m<7;m++) {
					for (int n = 1;n<7;n++) {
						for (int o = 1;o<7;o++) {
							c[j+k+l+m+n+o] ++;
						}						
					}
				}
			}						
		}
	}
	for (int i=6;i<37;i++) {
		cout << c[i] << "\n";
		cout << colinless(i,c) << "\n";
		total += p[i]*colinless(i,c);
	}
	BigUnsigned a = 262144;
	a = a * 46656;
	BigUnsigned b = gcd(a, total);
	total = total / b;
	a = a / b;
	cout << total << " " << a;
	int x = string2int(bigIntegerToString(a));
	int y = string2int(bigIntegerToString(total));
	cout << (double)y/x;
	return 0;
}