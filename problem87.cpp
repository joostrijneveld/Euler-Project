#include <iostream>
#include <math.h>
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

int main() {
	const int max = 50000;
	int count = 1;
	int amount = 0;
	int primes[908];
	primes[0] = 2;
	const int arrlim = 1000000;
	int used[arrlim];
	for (int i = 0; i < arrlim; i++) {
		used[i] = 0;
	}
	for (int i = 3; i < sqrt(max); i += 2) {
		if (isprime(i)) {
			primes[count] = i;
			count++;
		}
	}
	for (int i = 0; i < count; i++) {
		int a = primes[i]*primes[i]*primes[i]*primes[i];
		if (a > max) {
			break;
		}
		for (int j = 0; j < count; j++) {
			int b = a + primes[j]*primes[j]*primes[j];
			if (b > max) {
				break;
			}
			for (int k = 0; k< count; k++) {
				int c = b + primes[k]*primes[k];
				if (c > max) {
					break;
				}
				if (!array_int_search(used, c, arrlim)) {
					used[amount] = c;
					amount++;
					if (amount > arrlim) {
						cout << amount;
						return 0;
					}
				}
			}	
		}
	}
	cout << amount;
	return 0;
}