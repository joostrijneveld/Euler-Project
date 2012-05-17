from math import sqrt

maxlim = 1000000;

squares = [];

def issquare(n):
	a = int(sqrt(n));
	return (a * a == n);

def minimalx(D):
	for i in xrange(2,maxlim):
		if (squares[i] == D):
			return 0;
		if ((squares[i] - 1) % D == 0):
			if (issquare((squares[i] - 1) / D)):
				return i;
	return -1;

def main():
	for i in xrange(maxlim):
		squares.append(i * i);
		if not issquare(squares[i]):
			print i
	largest = 0;
	Dlarge = 0;
	for i in xrange(2,1000+1):
		t = minimalx(i);
		if (t == -1):
			print "TOOLOW"
			#break;
		if (t > largest):
			largest = t;
			Dlarge = i;
	print Dlarge	

if __name__ == "__main__":
	main()