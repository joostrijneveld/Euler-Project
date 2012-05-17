def lastdigit(a):
	return a % 10;
	
def secondlastdigit(a):
	return (a / 10) % 10

def isascending(a):
	if a < 10:
		return True;
	if lastdigit(a) < secondlastdigit(a):
		return False
	return isascending(a/10);

def isdecending(a):
	if a < 10:
		return True;
	if lastdigit(a) > secondlastdigit(a):
		return False
	return isdecending(a/10);

def isbouncy(a):
	if not isdecending(a) and not isascending(a):
		return True;
	return False;

def main():
	bouncy = 0;
	total = 100;
	while bouncy*100 < total*99:
		total += 1;
		if isbouncy(total):
			bouncy += 1;
	print total;

if __name__ == "__main__":
	main()