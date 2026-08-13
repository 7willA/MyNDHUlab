year = int(input("please enter a year: "))

def _isLeapYear(year):
    if year % 400 == 0:
        print("LeapYear")
    elif year % 100 == 0:
        print("NormalYear")
    elif year % 4 == 0:
        print("LeapYear")
    else:
        print("Normal Year")
        
_isLeapYear(year)