n = int(input("Enter size of array: "))
arr = []
for i in range(n):
    num = int(input("Enter element: "))
    arr.append(num)
key = int(input("Enter element to search: "))
found = False
for i in range(n):
    if arr[i] == key:
        print("Element found at position", i + 1)
        found = True
        break
if found == False:
    print("Element not found")
