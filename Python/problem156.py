def amountofds(x,d):
	res = 0
	for ch in str(x):
		if ch == d:
			res += 1
	return res
	
def s(x):
	sum = 0
	amount = 0
	in_i = 0
	for i in range(0,100000000):
		in_i += amountofds(i,x)
		amount += in_i
		#print str(i) + " " + str(in_i)
		if i == in_i:
		#	print i
			sum += i
	return sum
			

def main():
	print s("1")
	
if __name__ == "__main__":
	main()