#include <fstream>
#include <iostream>
#include <math.h>

using namespace std;

int main() {
	ifstream file ("base_exp.txt");
	int line = 0;
	double highest = 0;
	int a;
	int x;
	int i = 0;
	while (!file.eof()) {
		i++;
		file >> a;
		file >> x;
		double t = (double)x * log10(a);
		if (t > highest) {
			highest = t;
			line = i;
			cout << line << " " << t << " " << endl;
		}
	}
	cout << line;
	return 0;
}


