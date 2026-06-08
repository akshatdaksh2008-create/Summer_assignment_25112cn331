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
union = []
for i in arr1:
    if i not in union:
        union.append(i)
for i in arr2:
    if i not in union:
        union.append(i)
print("Union of arrays:")
print(union)
