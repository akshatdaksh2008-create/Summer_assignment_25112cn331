arr = []
n = int(input("Enter number of elements: "))
for i in range(n):
    num = int(input("Enter element: "))
    arr.append(num)
target = int(input("Enter the required sum: "))
found = False
for i in range(n):
    for j in range(i + 1, n):
        if arr[i] + arr[j] == target:
            print("Pair found:", arr[i], "and", arr[j])
            found = True
if found == False:
    print("No pair found")
