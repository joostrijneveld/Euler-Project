#include <iostream>
#include <math.h>
#include "bigint/BigIntegerLibrary.hh"

using namespace std;

int lookuparray[31][3][2];

int winners(int daystogo, int absent, int late) {
	if (absent >= 3 || late > 1)
		return 0;
	else if (daystogo == 0)
		return 1;
	else {
		if (lookuparray[daystogo][absent][late] == -1)
			lookuparray[daystogo][absent][late] = winners(daystogo - 1, absent + 1, late) + winners(daystogo - 1, 0, late) + winners(daystogo - 1, 0, late + 1);
		return lookuparray[daystogo][absent][late]; 
	}
}

int main() {
	for (int i = 0; i < 31; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 2; k++) {
				lookuparray[i][j][k] = -1;
			}
		}
	}
	cout << winners(30,0,0);
	return 0;
}