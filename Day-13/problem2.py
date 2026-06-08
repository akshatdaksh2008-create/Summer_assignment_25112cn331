n = int(input("Enter size of array: "))
arr = []
sum = 0
for i in range(n):
    num = int(input("Enter element: "))
    arr.append(num)
    sum = sum + num
average = sum / n
print("Sum =", sum)
print("Average =", average)
