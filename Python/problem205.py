def pete_wins(n, collinslist):
	total = 0;
	for i in xrange(n):
		total += collinslist[i];
	return total;

def main():
	pete = [];
	coll = [];
	total = 0;
	for i in xrange(37):
		pete.append(0);
		coll.append(0);
	for a in xrange(1,5):
		for b in xrange(1,5):
			for c in xrange(1,5):
				for d in xrange(1,5):
					for e in xrange(1,5):
						for f in xrange(1,5):
							for g in xrange(1,5):
								for h in xrange(1,5):
									for i in xrange(1,5):
										pete[a+b+c+d+e+f+g+h+i] += 1
	for a in xrange(1,7):
		for b in xrange(1,7):
			for c in xrange(1,7):
				for d in xrange(1,7):
					for e in xrange(1,7):
						for f in xrange(1,7):
							coll[a+b+c+d+e+f] += 1
	print pete_wins(11,coll);
	for i in xrange(1,37):
		#print coll[i];
		total += pete[i]*pete_wins(i,coll);
	colltotal = 6 ** 6;
	petetotal = 4 ** 9;
	combinations = colltotal * petetotal;
	print float(total)/combinations;
	

if __name__ == "__main__":
	main()