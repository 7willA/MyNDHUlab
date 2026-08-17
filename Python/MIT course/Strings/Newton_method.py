x = int(input('What x to find the cube root of? '))
g = int(input('What guess to start with? '))
print('Current estimate cubed = ', g**3)

next_g = g - ((g**3 - x)/(3*g**2))
print('Next guess to try = ', next_g)

old_error = abs(g**3 - x)
new_error = abs(next_g**3 - x)

if new_error < old_error:
    print("Closer!")
else:
    print("Not closer.")