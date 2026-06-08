arr = []
n = int(input("Enter number of elements: "))
for i in range(n):
    num = int(input("Enter element: "))
    arr.append(num)
for i in range(n):
    min_index = i
    for j in range(i + 1, n):
        if arr[j] < arr[min_index]:
            min_index = j
    temp = arr[i]
    arr[i] = arr[min_index]
    arr[min_index] = temp
print("Sorted array:")
print(arr)
