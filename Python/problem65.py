def sumofdigits(a):
	if a < 10:
		return a;
	return a % 10 + sumofdigits(a/10);

def main():
	x = 100;
	n = 1;
	d = 0;
	if (x-2) % 3 == 0 or (x-2) % 3 == 2:
		d = 1;
	else:
		d = 2 * ((x-2)/3+1);
	for e in range(0,x-2):
		g = (x-3)-e
		if g % 3 == 0 or g % 3 == 2:
			f = 1;
		else:
			f = 2 * (g/3+1);
		n += f*d;
		temp = d;
		d = n;
		n = temp;
	n += 2*d;
	print sumofdigits(n);

if __name__ == "__main__":
	main()