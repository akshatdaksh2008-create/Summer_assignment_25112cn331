n = int(input("Enter number of rows: "))
for i in range(1, n + 1):
    ch = 'A'
    for j in range(i):
        print(ch, end=" ")
        ch = chr(ord(ch) + 1)
    print()
