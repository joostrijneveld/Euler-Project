#include <iostream>
#include "bigint/BigIntegerLibrary.hh"
#include <math.h>
#include <stdlib.h>

using namespace std;

int main() {
	BigInteger max = 19293949596979899;
	BigInteger i = 0;
	BigInteger a;
	char b [20];
	for (i = 100000000; i*i < max; i += 2) {
		a = i * i;
		if (a % 10 == 9) {
			a /= 100;
			if (a % 10 == 8) {
				a /= 100;
				if (a % 10 == 7) {
					a /= 100;
					if (a % 10 == 6) {
						a /= 100;
						if (a % 10 == 5) {
							a /= 100;
							if (a % 10 == 4) {
								a /= 100;
								if (a % 10 == 3) {
									a /= 100;
									if (a % 10 == 2) {
										a /= 100;
										if (a % 10 == 1) {
											cout << i;
											break;
										}
									}
								}
							}	
						}	
					}	
				}
			}
		}
	}
}

//1_2_3_4_5_6_7_8_9_0