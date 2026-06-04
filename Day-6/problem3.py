num = int(input("Enter a number: "))
count = 0
while num > 0:
    if num % 2 == 1:
        count = count + 1
    num = num // 2
print("Number of set bits =", count)
