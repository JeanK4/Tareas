from sys import stdin

def algorithm(n):
	ct = 1
	while n != 1:
		ct += 1
		if n%2 != 0:
			n = 3*n +1
		else: 
			n = n/2
	return ct

def problem100():
	a = stdin.readline()
	while a != '':
		mayor = float("-inf")
		a = a.split()
		for i in range(int(a[0]),int(a[1])):
			b = algorithm(i)
			if b > mayor:
				mayor = b
		print("%s %s %d" % (a[0],a[1],mayor))
		a = stdin.readline()

problem100()