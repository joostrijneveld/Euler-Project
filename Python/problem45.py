from math import sqrt
 
def istriangle(n):
	a = (-1 + sqrt(1 + 8 * n))/2
	if a == int(a):
		return True
	return False
	
def ispentagonal(n):
	a = (1 + sqrt(1 + 24 * n))/6
	if a == int(a):
		return True
	return False

def ishexagonal(n):
	a = (1 + sqrt(1 + 8 * n))/4
	if a == int(a):
		return True
	return False

def generatehexagonal(n):
	return n*(2*n-1)

def main():
	hex = []
	for i in range(100000):
		hex.append(generatehexagonal(i))
		if ispentagonal(hex[i]) and istriangle(hex[i]):
			print hex[i]
	
if __name__ == "__main__":
	main()