n = int(input("Enter a non-negative integer: "))
total_sum = 0
current = 1

while current <= n:
    total_sum += current
    current +=1
print(f"The sum from 1 to {n} is: {total_sum}.")

