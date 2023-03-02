
def fibonacci(n):     
	f1, f2, ct = 0, 1     
	for i in range(n):         
		print(f1)         
		ans = f1+f2         
		f1 = f2         
		f2 = ans

#print(fibonacci(100))

def fibonacci1(n):
	if n == 0:
		ans = 0
	elif n == 1:
		ans = 1
	else:
		ans = fibonacci1(n-1) + fibonacci1(n-2)
	return ans
#print(fibonacci1(100))
