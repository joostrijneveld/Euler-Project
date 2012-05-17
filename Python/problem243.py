def gcd(a, b):
	if (a < b):
		return gcd(b,a);
	if (b == 0):
		return a;
	else:
		return gcd(b,a % b);

def R(n):
	count = 0;
	for i in xrange(n):
		if gcd(i,n) == 1:
			count += 1;
	return count;

def main():
	i = 12;
	while (R(i) * 94744 >= (i-1) * 15499):
		i += 1;
	#print R(i);
	print i

main()