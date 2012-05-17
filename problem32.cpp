#include <iostream>
#include <math.h>
#include <time.h>
#include "bigint/BigIntegerLibrary.hh"

using namespace std;

//Deze functie vult een array met -1, het teken wat we als leeg beschouwen
void clean_array(int array[], int length) {
    //PRE: length is de lengte van de array frontier
    for (int i = 0; i < length; i++) {
        array[i] = -1;
    }
    //POST: de array bevat nu enkel -1
}

//Deze functie zoekt of een needle voorkomt in de haystack
bool array_int_search(int haystack[], int needle, int length) {
    //PRE: true
    for (int i = 0; i < length; i++) {
        if (haystack[i] == needle) {
            return true;
        }
    }
    return false;
    //POST: true als de needle voorkomt in de haystack, anders false
}

int digitlength(int a) {
	/*int l = 0;
	while (a > 0) {
		a /= 10;
		l++;
	}
	return l;*/
	return log10(a)+1;
}

bool is1to9pandigital(int a, int b, int c) {
	int concat = a + pow(10,digitlength(a))*b + pow(10,digitlength(b)+digitlength(a))*c;
	if (digitlength(concat) != 9)
		return false;
	bool arr[] = {false,false,false,false,false,false,false,false,false};
	for (int i = 9; i >= 0; i--) {
		int f = pow(10,i);
		if (arr[concat / f - 1])
			return false;
		arr[concat / f - 1] = true;
		concat -= f * (concat / f);
	}
	return true;
}

int main() {
	int productarray[10000];
	int index = 0;
	BigInteger sum = 0;
	clean_array(productarray,10000);
	for (int i = 0 ; i < 100; i++) {
		int di = digitlength(i);
		for (int j = 0 ; j < 10000; j++) {
			int p = i * j;
			if (di + digitlength(j) + digitlength(p) > 9) {
				break;
			}
			else {
				if (is1to9pandigital(i,j,p)) {
					if (!array_int_search(productarray,p,10000)) {
						productarray[index] = p;
						index++;
						sum += p;
					}
				}
			}
		}
	}
	cout << sum;
	return 0;
}