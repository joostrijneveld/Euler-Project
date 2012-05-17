import decimal as dc
from math import sqrt
 
dc.getcontext().prec = 101

def main():
	print (10 ** 100)*sqrt(2);

if __name__ == "__main__":
	main()