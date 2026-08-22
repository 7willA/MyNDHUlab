where = input("Go left or right? ")
count = 0
while where == "right":
    count += 1
    where = input("Go left or right? ")
print("You got out!")

if count > 2:
    print(":(")
else:
    print(":)")