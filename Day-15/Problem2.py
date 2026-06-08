n = int(input("Enter size of array: "))
arr = []
for i in range(n):
    num = int(input("Enter element: "))
    arr.append(num)
first = arr[0]
for i in range(n - 1):
    arr[i] = arr[i + 1]
arr[n - 1] = first
print("Array after left rotation:")
for i in arr:
    print(i, end=" ")
