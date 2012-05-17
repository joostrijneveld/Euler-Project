from sets import Set

def list2int(numList):         # [1,2,3]
    s = map(str, numList)   # ['1','2','3']
    s = ''.join(s)          # '123'
    s = int(s)              # 123
    return s

def int2list(n):         
	return list(map(int,str(n)))

def permutations(topermutate, currlist, listofpermutes):
	if len(topermutate) > 1:
		for i in xrange(len(topermutate)):
			newcurrlist = currlist + [topermutate[i]]
			newtopermutate = topermutate[:]
			newtopermutate.remove(topermutate[i])
			permutations(newtopermutate, newcurrlist, listofpermutes)
	elif len(topermutate) == 1:
		listofpermutes.add(list2int(currlist + [topermutate[0]]))

def iscube(a):
	if a == 1:
		return False
	root = round(pow(a,1.0/3))
	return root * root * root == a;

def main():
	for i in xrange(406,1000):
		n = int2list(i ** 3)
		perm = Set([])
		permutations(n,[],perm)
		count = 0;
		b = 0
		for a in perm:
			b += 1;
			if iscube(a) and a >= 10 ** (len(n)-1) :
				count += 1;
		if count >= 3:
			print i
			print count
			break
	
if __name__ == "__main__":
	main()