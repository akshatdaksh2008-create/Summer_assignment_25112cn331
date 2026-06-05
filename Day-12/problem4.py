def check_perfect(n):
    total = 0
    for i in range(1, n):
        if n % i == 0:
            total += i
    return total
num = int(input("Enter a number: "))
if check_perfect(num) == num:
    print("Perfect Number")
else:
    print("Not Perfect Number")
