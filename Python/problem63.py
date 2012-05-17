import math

def diglen(n):
	return len(str(n))

def main():
	count = 0
	for i in range(100):
		for j in range(100):
			n = pow(i,j)
			if diglen(n) == j:
				print "j = " + str(j) + " LEN= " + str(diglen(n)) + "Result: " + str(pow(i,j))
				count = count + 1
	print count
	
if __name__ == "__main__":
	main()