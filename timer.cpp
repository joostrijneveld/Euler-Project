#include <sys/time.h>
#include <iostream>
#include <math.h>

using namespace std;

bool isprime(int no) {
	if (no == 2)
		return true;
	if (no % 2 == 0 || no == 1)
		return false;
	for (int i = 3; i*i <= no; i+=2)
		if (no % i == 0)
			return false;
	return true;
}

bool isprimeslow(int no) {
	if (no == 2)
		return true;
	if (no % 2 == 0 || no == 1)
		return false;
	for (int i = 3; i <= sqrt(no); i+=2) {
		if (no % i == 0) {
			return false;
		}
	}
	return true;
}


int main()
{
    struct timeval start, end;
    long mtime, seconds, useconds;    
    gettimeofday(&start, NULL);
	
	for (int a = 0; a < 10000000; a++) {
		isprime(a);
	}
	/*for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			backtrackarr[i][j] = -1;
		}
	}
		amountofoptions(99,100);
	}*/
	
    gettimeofday(&end, NULL);
    seconds  = end.tv_sec  - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + useconds/1000.0) + 0.5;
	
    cout << "Elapsed time: " << mtime;
	
    return 0;
}