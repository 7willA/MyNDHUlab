height = float(input())
weight = float(input())
bmi= weight / ((height/100)**2)

if bmi < 18.5 :
    print("underweight")
elif 18.5 <= bmi < 24:
    print("normal")
else:
    print("overweight")