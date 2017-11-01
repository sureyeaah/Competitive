num = 4000000
a = 1
b = 1
c = 2
sum = 0
while(c <= num):
    sum += c
    a = b+c
    b = a+c
    c = a+b
print sum