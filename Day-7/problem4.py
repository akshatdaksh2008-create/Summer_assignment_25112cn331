def reverse_num(n, rev):
    if n == 0:
        return rev
    else:
        rev = rev * 10 + (n % 10)
        return reverse_num(n // 10, rev)
num = int(input("Enter a number: "))
result = reverse_num(num, 0)
print("Reversed number =", result)
