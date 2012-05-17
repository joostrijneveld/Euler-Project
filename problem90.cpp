#include <iostream>

using namespace std;

bool cube1[10];
bool cube2[10];

bool canformallsquares(bool cube1[], bool cube2[]) {
	if (!((cube1[0] && cube2[1]) || (cube1[1] && cube2[0]))) {  
		return false;
	}
	if (!((cube1[0] && cube2[4]) || (cube1[4] && cube2[0]))) {  
		return false;
	}
	if (!((cube1[0] && (cube2[9] || cube2[6])) || ((cube1[9] || cube1[6]) && cube2[0]))) {  
		return false;
	}
	if (!((cube1[1] && (cube2[9] || cube2[6])) || ((cube1[9] || cube1[6]) && cube2[1]))) {  
		return false;
	}
	if (!((cube1[2] && cube2[5]) || (cube1[5] && cube2[2]))) {  
		return false;
	}
	if (!((cube1[3] && (cube2[9] || cube2[6])) || ((cube1[9] || cube1[6]) && cube2[3]))) {  
		return false;
	}
	//if this one's true, also 64 can be formed so no need to test that one
	if (!((cube1[4] && (cube2[9] || cube2[6])) || ((cube1[9] || cube1[6]) && cube2[4]))) {  
		return false;
	}
	if (!((cube1[8] && cube2[1]) || (cube1[1] && cube2[8]))) {  
		return false;
	}
	return true;
}

int main() {
	int count = 0;
	for (int a = 0; a < 10; a++) {
		for (int b = a+1; b < 10; b++) {
			for (int c = b+1; c < 10; c++) {
				for (int d = c+1; d < 10; d++) {
					for (int i = 0; i < 10; i++) {
						cube1[i] = true;
					}
					cube1[a] = false;
					cube1[b] = false;
					cube1[c] = false;
					cube1[d] = false;
					for (int e = 0; e < 10; e++) {
						for (int f = e+1; f < 10; f++) {
							for (int g = f+1; g < 10; g++) {
								for (int h = g+1; h < 10; h++) {
									for (int j = 0; j < 10; j++) {
										cube2[j] = true;
									}
									cube2[e] = false;
									cube2[f] = false;
									cube2[g] = false;
									cube2[h] = false;
									if (canformallsquares(cube1,cube2)) {
										count++;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout << count/2;
	return 0;
}