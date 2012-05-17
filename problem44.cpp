#include <iostream>
#include <math.h>

using namespace std;

bool ispentagonal(int P) {
	double n = (1 + sqrt(1+24*P)) / 6;
	if (n == (int)n)
		return true;
	return false;
}

int customabs(int a) {
	if (a >= 0)
		return a ;
	return - a;
}

int main() {
	unsigned int arr [5000];
	unsigned int count = 0, i = 1, dif = 4;
	while (count < 5000) {
		if (ispentagonal(i)) {
			arr[count] = i;
			count ++;
		}
		i += dif;
		dif += 3;
	}
	cout << "starting with part B";
	unsigned int mindif = NULL;
	for (int i = 1; i < 5000; i++) {
		for (int j = 1; j < 5000; j++) {
			if (ispentagonal(arr[i] + arr[j])) {
				if (ispentagonal(customabs(arr[i] - arr[j]))) {
					int tempdif = customabs(arr[i] - arr[j]);
					if (tempdif < mindif || mindif == NULL) {
						cout << tempdif << endl;
						mindif = tempdif;
						
					}
				}
			}
		}
	}
	cout << mindif;
	return 0;
}