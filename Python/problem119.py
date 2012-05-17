def sumofdigits(a):
	if a < 10:
		return a;
	return a % 10 + sumofdigits(a/10);

def main():
	list = [];
	for i in range(100):
		for j in range(100):
			a = i ** j;
			if a > 9 and sumofdigits(a) == i:
				list.append(a);
	list.sort()
	print list[29];
	
if __name__ == "__main__":
	main()