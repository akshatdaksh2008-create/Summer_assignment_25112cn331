n = int(input("Enter size of array: "))
arr = []
for i in range(n):
    num = int(input("Enter element: "))
    arr.append(num)
last = arr[n - 1]
for i in range(n - 1, 0, -1):
    arr[i] = arr[i - 1]
arr[0] = last
print("Array after right rotation:")
for i in arr:
    print(i, end=" ")
