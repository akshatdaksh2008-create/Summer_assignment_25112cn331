def check_prime(n):
    for i in range(2, n):
        if n % i == 0:
            return False
    return True
num = int(input("Enter a number: "))
if num > 1 and check_prime(num):
    print("Prime")
else:
    print("Not Prime")
