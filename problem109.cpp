#include <iostream>
#include <math.h>
#include "bigint/BigIntegerLibrary.hh"
#include <string>
#include <sstream>

using namespace std;

string int2str (int n) {
	stringstream ss;
	ss << n;
	return ss.str();
}

int checkout(int amount, int darts, string prevdarts[]) {
	if (amount == 0) {
		cout << prevdarts[2] << " " << prevdarts[1] << " " << prevdarts[0] << endl;
		return 1;
	}
	else if (darts == 0)
		return 0;
	else {
		if (darts == 1) {
			int count = 0;
			if (amount % 3 == 0 && amount <= 60)
				count += checkout(0,0,{prevdarts[0], prevdarts[1], "T"+amount/3});
			if ((amount % 2 == 0 && amount <= 40) || amount == 50) {
				if (amount == 50)
					count += checkout(0,0,{prevdarts[0], prevdarts[1], "D25"});
				else
					count += checkout(0,0,{prevdarts[0], prevdarts[1], "D"+amount/2});
			}
			if (amount <= 20 || amount == 25) {
				if (amount == 25)
					count += checkout(0,0,{prevdarts[0], prevdarts[1], "S25"});
				else
					count += checkout(0,0,{prevdarts[0], prevdarts[1], "S"+amount});
			}				
			if (count == 0)
				return 0;
			else {
				return count;
			}
		}
		else if (darts == 2) {
			int count = 0;
			//in case of miss
			count += checkout(amount,darts-1,{prevdarts[0], "  "})
			for (int i = 1; i <= amount && (i <= 20 || i == 25); i++) {
				count += checkout(amount-i,darts-1,{prevdarts[0], "S"+int2str(i)});
				if (amount >= i*2)
					count += checkout(amount-i*2,darts-1,{prevdarts[0], "D"+int2str(i)});
				if (amount >= i*3 && i != 25)
					count += checkout(amount-i*3,darts-1,{prevdarts[0], "T"+int2str(i)});
			}
		}
	}
}

int main() {
	
	return 0;
}