def mult_order(g, n):
	# http://mathworld.wolfram.com/MultiplicativeOrder.html
	for x in range(1, n):
		if g ** x % n == 1:
			return x

def main():
	maxOrder = 0
	result = 0
	for x in range(1,1000):
			if x % 5 != 0 and x % 2 != 0:
				order = mult_order(10, x) # http://mathworld.wolfram.com/DecimalExpansion.html
				if order > maxOrder:
					maxOrder = order
					result = x
	print result
	
if __name__ == "__main__":
	main()