factorial = [1]
for i in range(1,1001):
	factorial.append(factorial[i-1]*i)
while True:
	try:
		n = int(input())
		print("{}!".format(n))
		print("{}".format(factorial[n]))
	except:
		break;
