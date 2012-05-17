#include <iostream>

using namespace std;

unsigned int precomputed_array[201];

int coins[8] = {200,100,50,20,10,5,2,1};

int formwithpence(int v, int index = 0) {
	if (precomputed_array[v] > -1)
		return precomputed_array[v];
	if (v == 0)
		return 1;
	if (v < 0)
		return 0;
	if (index == 7)
		return 1;
	int count = 0;
	int coin = coins[index];
	//anything that includes this coin
	if (v-coin >= 0)
		count += formwithpence(v-coin,index);
	//anything that doesn't include it
	count += formwithpence(v,index+1);
	precomputed_array[v] = count;
	return count;
}

void clearprecomputed() {
	for (int i = 0; i < 201; i++) {
		precomputed_array[i] = -1;
	}
}

int main() {
	clearprecomputed();
	cout << formwithpence(200);
}