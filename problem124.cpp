#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int primes[10000];
int narr[100000];

typedef int typevar;

void swap(int arr[], int a, int b) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
	temp = narr[a];
	narr[a] = narr[b];
	narr[b] = temp;
}

void push_up(int heap[], int i) {
    while (heap[(i-1)/2] < heap[i]) {
        swap(heap,(i-1)/2,i);
        i = (i-1)/2;
    }
    //POST: het element i zit nu op de correcte plaats in de heap
}

//Deze functie berekent de index van het linker kind van i
int leftchild(int i) {
    return 2*(i+1)-1;
}

//Deze functie berekent de index van het rechter kind van i
int rightchild(int i) {
    return 2*(i+1);
}

void push_down(int heap[], int length) {
    int i = 0;
    while ((leftchild(i) < length && heap[i] < heap[leftchild(i)]) || (rightchild(i) < length && heap[i] < heap[rightchild(i)])) {
        if (heap[leftchild(i)] < heap[rightchild(i)] && rightchild(i) < length) {
            swap(heap,i,rightchild(i));
            i = rightchild(i);
        }
        else {
            swap(heap,i,leftchild(i));
            i = leftchild(i);
        }
    }
    //POST: het eerste element van de heap is nu naar de goede plaats gezakt
}

void build_heap(int heap[], int size) {
    //PRE: true
    for (int i = 1; i < size; i++) {
        push_up(heap, i);
    }
    //POST: de heap voldoet nu aan de voorwaarde dat elke vader groter is dan zijn kinderen
}

void heapsort(int heap[], int size) {
    //PRE: true
    build_heap(heap, size);
    for (int i = 0; i < size; i++) {
        swap(heap,0,size-(i+1));
        push_down(heap,size-(i+1));
    }
    //POST: de vector heap is nu gesorteerd
}

int rad(int n) {
	int product = 1;
	int last = 0;
	while (n > 1) {
		for (int i = 0; i < 10000; i++) {
			if (n % primes[i] == 0) {
				if (last != primes[i]) {
					last = primes[i];
					product *= primes[i];
				}
				n /= primes[i];
				break;
			}
		}
	}
	return product;
}

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

int main() {
	int total = 1;
	primes[0] = 2;
	const int max = 100000;
	for (int i = 3; i <= max; i += 2) {
		if (isprime(i)) {
			primes[total] = i;
			total++;
		}
	}
	
	int radarr[max];
	
	for (int n = 1; n <= max; n++) {
		narr[n-1] = n;
		radarr[n-1] = rad(n);
	}
	cout << "Hi";
	
	heapsort(radarr,max);
	for (int k = 1; k <= max; k++) {
		cout << narr[k-1] << " " << radarr[k-1] << " " << k << endl;
	}
	//cout << narr[10000-2];
	return 0;
}