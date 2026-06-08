n = int(input("Enter size of array: "))
arr = []
for i in range(n):
    num = int(input("Enter element: "))
    arr.append(num)
arr.sort()

print("Second Largest Element =", arr[-2])
