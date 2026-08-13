#same code with different loops
#while loop
print("This code below was made with while loop")
x = 4
i = 1
factorial = 1
while i <=x :
    factorial *= i
    i += 1
print(f'{x} factorial is {factorial}')

#for loop
print("This code below was made with for loop")
x = 4
factorial = 1
for i in range(1, x+1, 1):
    factorial *=i
print(f'{x} factorial is {factorial}')