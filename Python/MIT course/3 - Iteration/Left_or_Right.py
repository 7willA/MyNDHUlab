n=0
where = input("Go left or right? ")
while where == "right":
    n = n + 1
    #print(n)
    if n > 2:
        print(":(")
    where = input("Go left or right? ")
print("You got out!")