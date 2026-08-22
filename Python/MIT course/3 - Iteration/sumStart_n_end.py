start = int(input("Enter a number as a starting point: "))
end = int(input("Enter a number as an ending point: "))

if start > end:
    temp = start
    start = end
    end = temp

total = 0
for i in range(start, end + 1):
    total += i
print(total)