def is1to9pandigital(x):
	for i in range(1,10):
		if not(str(i) in x):
			return False
	return True

def diglen(n):
	return len(str(n))

def main():
	oldest = 1
	old = 1
	n = 2
	i = 2
	while True:
		i += 1
		nstr = str(n)
		if len(nstr) >= 9:
			if is1to9pandigital(nstr[-9:]):
				if is1to9pandigital(nstr[:9]):
					print i
					break
		oldest = old
		old = n
		n = oldest + old
	print "Finished"
	
if __name__ == "__main__":
	main()