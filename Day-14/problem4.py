n = int(input("Enter size of array: "))

arr = []

for i in range(n):
    num = int(input("Enter element: "))
    arr.append(num)

print("Duplicate elements are:")

for i in range(n):
    for j in range(i + 1, n):
        if arr[i] == arr[j]:
            print(arr[i])
            break
