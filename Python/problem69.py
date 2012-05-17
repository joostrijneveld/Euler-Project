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

def main():
	maximum = 0
	n = 0
	for i in range(2,1000):
		ratio = i / phi(i)
		if ratio > maximum:
			maximum = ratio
			n = i
			print n
	print n
	
if __name__ == "__main__":
	main()