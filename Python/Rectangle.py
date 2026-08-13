class Rectangle:
    def __init__(self, weight, height):
        self.weight = int (weight)
        self.height = int(height)
        
    def display(self):
        area = self.weight * self.height
        print(f"Area: {area}")
        
data = input().split()

s = Rectangle(data[0], data[1])

s.display()