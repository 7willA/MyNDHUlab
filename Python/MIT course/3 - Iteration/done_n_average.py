total = 0
count = 0
entry = input("Enter a number (or 'done' to finish): ")

while entry != "done":
    total += int(entry)
    count += 1
    entry = input("Enter a number (or 'done' to finish): ")

print(f"You entered {count} numbers.")
if count > 0:
    print(f"The average is {total / count}")
else:
    print("No numbers entered, so there is no average.")