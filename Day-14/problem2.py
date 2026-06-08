n = int(input("Enter size of array: "))
arr = []
for i in range(n):
    num = int(input("Enter element: "))
    arr.append(num)
x = int(input("Enter element to find frequency: "))
count = 0
for i in arr:
    if i == x:
        count += 1
print("Frequency of", x, "=", count)
