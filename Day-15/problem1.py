n = int(input("Enter size of array: "))
arr = []
for i in range(n):
    num = int(input("Enter element: "))
    arr.append(num)
print("Reversed array:")
for i in range(n - 1, -1, -1):
    print(arr[i], end=" ")
