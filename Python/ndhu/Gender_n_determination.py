"""gender = input("Please enter your gender: ")
age = int(input("Please enter your age: "))
if gender == "F":
    if 0 <= age <=12:
        print("Little girl")
    elif 13 <=age <=18:
        print("girl")
    else:
        print("woman")
elif gender == "M":
    if 0 <= age <=12:
        print("Little boy")
    elif 13 <=age <=18:
        print("boy")
    else:
        print("man")"""
gender = input("Please enter your gender: ")
age = int(input("Please enter your age: "))
if gender == "F" and 0<= age <=12:
    print("Little girl")
elif gender == "F" and 13<= age <=18:
    print("girl")
elif gender == "F" and age >= 19:
    print("woman")
elif gender == "M" and 0<= age <=12:
    print("Little boy")
elif gender == "M" and 13<= age <=18:
    print("boy")
elif gender == "M" and age >= 19:
    print("man")