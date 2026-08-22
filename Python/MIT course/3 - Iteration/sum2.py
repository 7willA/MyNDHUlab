n=int(input("Enter a non-negative integer: "))

total_sum = 0

for current in range(1, n+1):
    total_sum += current
print(f"The sum from 1 to {n} is: {total_sum}.")

"""for i in range (2, 9, 3):
    print(i)"""