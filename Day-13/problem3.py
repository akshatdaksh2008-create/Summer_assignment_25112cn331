n = int(input("Enter size of array: "))
arr = []

for i in range(n):
    num = int(input("Enter element: "))
    arr.append(num)
largest = arr[0]
smallest = arr[0]
for i in arr:
    if i > largest:
        largest = i
    if i < smallest:
        smallest = i
print("Largest element =", largest)
print("Smallest element =", smallest)
