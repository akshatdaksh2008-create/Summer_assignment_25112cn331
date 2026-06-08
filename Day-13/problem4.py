n = int(input("Enter size of array: "))
arr = []
for i in range(n):
    num = int(input("Enter element: "))
    arr.append(num)
even = 0
odd = 0
for i in arr:
    if i % 2 == 0:
        even += 1
    else:
        odd += 1
print("Number of even elements =", even)
print("Number of odd elements =", odd)
