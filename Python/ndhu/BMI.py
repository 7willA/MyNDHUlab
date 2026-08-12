height = float(input("Please enter your height: "))
weight = float(input("Please enter your weiht: "))
bmi= weight / (height)**2
#print(bmi) #this gonna print the all digits after the dot
#print(f"{bmi:.2f}") # this for 2 digits after the dot, same for the formats below
#print("{:.2f}".format(bmi))
print(round(bmi, 2))