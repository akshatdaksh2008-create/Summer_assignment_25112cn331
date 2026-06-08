arr = []
n = int(input("Enter number of elements: "))
for i in range(n):
    num = int(input("Enter element: "))
    arr.append(num)
new_arr = []
for i in arr:
    if i not in new_arr:
        new_arr.append(i)
print("Array after removing duplicates:")
print(new_arr)
