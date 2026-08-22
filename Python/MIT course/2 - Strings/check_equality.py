x = int(input())
y = int(input())

if x == y:
    print("x and y are equal")
    if y != 0:                            
        print("therefore, x / y is", x/y)
elif x < y:
    print("x is smaller")
else:
    print("y is smaller")
print("thanks!")