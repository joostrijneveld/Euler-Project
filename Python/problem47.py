from math import sqrt

def factors(n, primes):
	# assumes non-exhaustive list of primes
	result = []
	i = iter(primes)
	p = i.next()
	while n > 1:
		if n % p == 0:
			n /= p
			result.append(p)
			if isPrime(n):
				result.append(n)
				break
		else:
			p = i.next()
	return result

def isPrime(n):
	if n == 2:
		return True;
	if n % 2 == 0 or n == 1:
		return False;
	for i in xrange(3,int(sqrt(n))+1,2):
		if n % i == 0:
			return False
	return True;
	
def countUniques(l):
	s = set()
	for x in l:
		s.add(x)
	return len(s)

def primeList(n):
	return [2] + [x for x in xrange(1,n,2) if isPrime(x) == True]

def main():
	primes = primeList(1000000)
	print "Done generating primes.."
	consec = 0
	req = 4
	for x in xrange(1,1000000):
		if countUniques(factors(x, primes)) == req:
			consec += 1
		else:
			consec = 0
		if consec == req:
			for i in xrange(x-req+1, x+1):
				print i
			break
			
if __name__ == "__main__":
	main()
	