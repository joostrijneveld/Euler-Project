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
	squareofprime = [];
	lim = 51
	for i in xrange(lim):
		triangle.append([]);
		for j in xrange(i+1):
			if i == 0 or j == 0 or j == i:
				triangle[i].append(1);
			else:
				triangle[i].append(triangle[i-1][j] + triangle[i-1][j-1]);
		sumlist += triangle[i];
	sumset = set(sumlist)
	
	squareofprime.append(4)
	for i in xrange(1,int(sqrt(triangle[lim-1][lim/2])),2):
		if isprime(i):
			squareofprime.append(i*i);
	ignoreset = []
	for x in sumset:
		for y in squareofprime:
			if y > x:
				break
			if x % y == 0:
				ignoreset.append(x)
	total = 0
	for x in sumset:
		if x not in ignoreset:
			total += x
	print total;
	
if __name__ == "__main__":
	main()