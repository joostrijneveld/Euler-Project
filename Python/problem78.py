maxlim = 10001;
backtrackarr = [];

def amountofoptions(max, sum):
	if (backtrackarr[max][sum] > -1):
		return backtrackarr[max][sum];
	count = 0;
	for i in xrange(1,max+1):
		if (sum == i):
			count += 1;
		elif (sum > i):
			count += amountofoptions(i, sum-i);
		else:
			break;
	backtrackarr[max][sum] = count;
	return count;

def main():
	for i in xrange(maxlim):
		backtrackarr.append([])
		for j in xrange(maxlim):
			backtrackarr[i].append(-1);
	for i in xrange(maxlim):
		a = amountofoptions(i-1,i)+1;
		if (a / 1000000 * 1000000 == a):
			print i
			break;
	print "Done"
	
if __name__ == "__main__":
	main()
	
	