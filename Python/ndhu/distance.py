coord1 = input().split(",")  
coord2 = input().split(",")  

x1, y1 = float(coord1[0]), float(coord1[1])
x2, y2 = float(coord2[0]), float(coord2[1])

dist = ((x2 - x1)**2 + (y2 - y1)**2)**0.5

print("{:.2f}".format(dist))