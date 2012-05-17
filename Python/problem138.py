from math import sqrt

def main():
	count = 1;
	Lsum = 0;
	h = 1;
	while (count < 12):
		if (h-1 > 0):
			b = h-1;
			L = sqrt(h*h + (b/2) * (b/2));
			if (int(L) == L):
				count += 1;
				Lsum += L;
				print L;
		b = h+1
		L = sqrt(h*h + (b/2) * (b/2));
		if (int(L) == L):
			count += 1;
			Lsum += L;
			print L;
		h += 2;
	print Lsum;
	
if __name__ == "__main__":
	main()
	
#h = W(L^22 - b/2 ^ 2)
#h^2 = L^2 - b/2 ^ 2
#L = W(h2 + b/2 ^ 2)
#b = h + 1
#b = h - 1
#L2 = h2 + (b/2) ^ 2

#L2 = h2 + (h/2 + 1/2) ^ 2
#L2 = 5/4(h^2) + 1/2(h) + 1/4

#L2 = h2 + (h/2 - 1/2) ^ 2
#L2 = 5/4(h^2) - 1/2(h) + 1/4

#4L^2 = 5h^2 +/- 2h + 1