a = int(input())
b = int(input())

total_sum = 0
current = a
while current <= b:
    total_sum += current
    current += 1 
print(total_sum)