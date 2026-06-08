n = int(input("Enter size of array: "))
arr = []
for i in range(n):
    num = int(input("Enter element: "))
    arr.append(num)
max_count = 0
max_element = arr[0]
for i in arr:
    count = 0
    for j in arr:
        if i == j:
            count += 1
    if count > max_count:
        max_count = count
        max_element = i
print("Element with maximum frequency =", max_element)
print("Frequency =", max_count)
