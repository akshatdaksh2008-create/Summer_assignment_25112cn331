n = int(input("Enter size of array: "))
arr = []
for i in range(n):
    num = int(input("Enter element: "))
    arr.append(num)
result = []
for i in arr:
    if i != 0:
        result.append(i)
zero_count = n - len(result)
for i in range(zero_count):
    result.append(0)
print("Array after moving zeroes to end:")
for i in result:
    print(i, end=" ")
