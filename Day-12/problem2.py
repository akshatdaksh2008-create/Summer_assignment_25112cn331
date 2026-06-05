def check_armstrong(n):
    s = 0
    temp = n
    while temp > 0:
        d = temp % 10
        s = s + d ** len(str(n))
        temp = temp // 10
    return s == n
num = int(input("Enter a number: "))
if check_armstrong(num):
    print("Armstrong")
else:
    print("Not Armstrong")
