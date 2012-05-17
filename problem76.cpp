#include <iostream>

using namespace std;

int backtrackarr[101][101];

int amountofoptions(int max, int sum) {
	if (backtrackarr[max][sum] > -1)
		return backtrackarr[max][sum];
	int count = 0;
	for (int i = 1; i <= max; i++) {
		if (sum == i) {
			count++;
		}
		else if (sum > i) {
			count += amountofoptions(i, sum-i);
		}
		else {
			break;
		}
	}
	backtrackarr[max][sum] = count;
	return count;
}

int main() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			backtrackarr[i][j] = -1;
		}
	}
	cout << amountofoptions(99,100) << endl;	
}