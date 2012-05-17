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

def main():
	n = 0
	#for i in xrange(2,1000000):
	#	if ((i - 1) ** (n+1) + (i + 1) ** (n+1)) / 
	print 4235235 ** 7037
	
if __name__ == "__main__":
	main()