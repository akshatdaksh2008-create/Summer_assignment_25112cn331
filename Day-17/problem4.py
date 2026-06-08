arr1 = []
arr2 = []
n1 = int(input("Enter number of elements in first array: "))
for i in range(n1):
    num = int(input("Enter element: "))
    arr1.append(num)
n2 = int(input("Enter number of elements in second array: "))
for i in range(n2):
    num = int(input("Enter element: "))
    arr2.append(num)
print("Common elements are:")
for i in arr1:
    if i in arr2:
        print(i)
