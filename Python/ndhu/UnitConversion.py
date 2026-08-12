"""meter1 = 100
meter2 = 0.001
m=int(input("Enter the number of meter(s) you want to convert: "))
conversion1 = m*meter1
conversion2 = m*meter2
print(m," m =", conversion1, " cm")
print(m," m =", conversion2, " km")"""

#Read the input meters first as an integer
m=int(input())
#convert meters to centimeters (1 m = 100 cm)
cm = m * 100
#convert meters to kilometers (1 m = 0.001 km)
km = m / 1000

#Print the results
print("{} m = {} cm" .format(m, cm))
print("{} m = {:.3f} km" .format(m, km))
