from math import sqrt

def digitatindex(n,i):
	return (n % 10 ** (19-i)) / (10 ** (19-i-1));

def main():
	a = 1010101010;
	print 1389019170*1389019170
	while False: #a < 1414213564:
		b = a * a;
		for i in range(11):
			if i == 0 and not digitatindex(b,18) == 0:
				break;
			elif not digitatindex(b,2*(i-1)) == i:
				break;
		if i == 10:
			break;
		a += 1;
	print a;
	
if __name__ == "__main__":
	main()