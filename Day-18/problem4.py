arr = []
n = int(input("Enter number of elements: "))
for i in range(n):
    num = int(input("Enter element: "))
    arr.append(num)
for i in range(n):
    for j in range(i + 1, n):
        if arr[i] < arr[j]:
            temp = arr[i]
            arr[i] = arr[j]
            arr[j] = temp
print("Array in descending order:")
print(arr)
