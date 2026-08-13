class Student:
    def __init__(self, name, student_id, age):
        self.name = name
        self.student_id = student_id
        self.age = age
        
    def display(self):
        print(f"Name: {self.name}")
        print(f"ID:   {self.student_id}")
        print(f"Age:  {self.age}")
        
#read the input then add space in between them
data = input().split()
#create the objects with data
s = Student(data[0], data[1], data[2])
#display the infos
s.display()