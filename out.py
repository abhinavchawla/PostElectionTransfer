import random
n =100000
l = random.randint(1,n)
k = random.randint(1,n)
lst = []
x=0
for i in range(l):
	x=random.randint(1,n)	
	while (1):
		x=random.randint(1,n)
		if x not in lst:
			lst.append(x)
			break
print n,l,k
lst.sort()
for i in lst:
	print i		
