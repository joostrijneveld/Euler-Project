import fractions

def totient(n):
	 """
	 Compute the number of positives < n that are
	 relatively prime to n -- good solution!
	 """
	 tot, pos = 0, n-1
	 while pos>0:
		if fractions.gcd(pos,n)==1: tot += 1
		pos -= 1
	 return tot 

def diglen(n):
	return len(str(n))

def phi(x):
	ret = 1
	i = 2
	while x != 1:
		i = i+1
		pow = 1
		while not(x % i):
			x /= i
			pow *= i
		ret *= pow - pow/i
	return ret

def ispermutation(a,b):
	if diglen(a) != diglen(b):
		return False
	astring = str(a)
	bstring = str(b)
	for ch in astring:
		if ch not in bstring:
			return False
	return True

def main():
	minimum = 0
	n = 0
	for i in range(87000,88000):
		t = totient(i)
		if ispermutation(t,i):
			ratio = float(i) / t
			if minimum == 0 or ratio < minimum:
				minimum = ratio
				n = i
	print minimum
	
if __name__ == "__main__":
	main()