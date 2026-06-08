n = int(input("Enter the size of array: "))
arr = []
for i in range(n):
    x = int(input("Enter element: "))
    arr.append(x)
print("Array elements are:")
for i in arr:
    print(i, end=" ")
