from math import sqrt

def isprime(n):
	if n == 2:
		return True;
	if n % 2 == 0 or n == 1:
		return False;
	for i in xrange(3,int(sqrt(n))+1,2):
		if n % i == 0:
			return False
	return True;

def f3(seq):
    # Not order preserving
    keys = {}
    for e in seq:
        keys[e] = 1
    return keys.keys()

def main():
	triangle = [];
	sumlist = [];
	lim = 1e9
	total = 0;
	divi = 0;
	for i in xrange(lim):
		triangle.append([]);
		for j in xrange(i+1):
			if i == 0 or j == 0 or j == i:
				triangle[i].append(1);
			else:
				triangle[i].append(triangle[i-1][j] + triangle[i-1][j-1]);
			if triangle[i][j] % 7 != 0:
				divi += 1;
			total += 1
	print divi;
	print total;
	
	
if __name__ == "__main__":
	main()