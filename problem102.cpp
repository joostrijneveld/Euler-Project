#include <iostream>
#include <fstream>
#include <string>
using namespace std;

double YforXis(int Ax, int Ay, int Bx, int By, double x) {
	double a = (By - Ay) / (Bx - Ax);
	double b = Ay - a * Ax;
	return a * x + b;
}

double XforYis(int Ax, int Ay, int Bx, int By, double y) {
	double a = (By - Ay) / (Bx - Ax);
	double b = Ay - a * Ax;
	return (y-b) / a;
}

double YforXonLine(int arr[], string line, double x) {
	if (line == "AC")
		return YforXis(arr[0],arr[1],arr[4],arr[5],x);
	else if (line == "AB")
		return YforXis(arr[0],arr[1],arr[2],arr[3],x);
	else
		return YforXis(arr[2],arr[3],arr[4],arr[5],x);
}

double XforYonLine(int arr[], string line, double y) {
	if (line == "AC")
		return XforYis(arr[0],arr[1],arr[4],arr[5],y);
	else if (line == "AB")
		return XforYis(arr[0],arr[1],arr[2],arr[3],y);
	else
		return XforYis(arr[2],arr[3],arr[4],arr[5],y);
}

bool containsOrigin(int arr[]) {
	//if A is the highest
	if (arr[0] > arr[2] && arr[0] > arr[4]) {

		
	}
	//if B is the highest
	if (arr[2] > arr[0] && arr[2] > arr[4]) {
		if (arr[0] == arr[4]) {

		}
	}
	//if C is the highest
	if (arr[4] > arr[2] && arr[4] > arr[0]) {
		if (arr[2] == arr[0]) {

		}
	}
	return false;
}

void swap(int array[],int a, int b) {
	int temp = array[b];
	array[b] = array[a];
	array[a] = temp;
}

void triswap(int array[],int a, int b) {
	swap(array,a,b);
	swap(array,a+1,b+1);
}

int main() {
	cout << XforYisZero(2,4,4,6);
	int amount = 0;
	ifstream triangles ("triangles.txt");
	int triangle[1000][6];
	for (int i = 0; i < 1000; i++) {
		int i = 0;
		string str;
		getline(triangles,str);
		for (int j = 0; j < 6; j++) {
			triangle[i][j] = atoi((str.substr(0,str.find(','))).c_str());
			str = str.substr(str.find(',')+1);
		}
		bool flag;
		do {
			flag = false;
			if (triangle[i][0] > triangle[i][2]) {
				triswap(triangle[i],0,2);
				flag = true;
			}
			if (triangle[i][2] > triangle[i][4]) {
				triswap(triangle[i],2,4);
				flag = true;
			}
		} while (flag);
		if (containsOrigin(triangle[i])) {
			amount++;
		}
	}
	cout << amount;
	return 0;
}