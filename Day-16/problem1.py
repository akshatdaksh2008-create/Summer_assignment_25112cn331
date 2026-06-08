arr = [1, 2, 4, 5]
n = len(arr)
total = (n + 1) * (n + 2) // 2
print("Missing number =", total - sum(arr))
