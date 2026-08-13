"""
import math
a = int(input())
b = int(input())
print(math.gcd(a, b))
"""
a = int(input())
b = int(input())
#math definition ______gcd(a, b) = gcd(b, a (mod b))
def gcd_recursive(a, b):
    if b == 0:
        return a
    return gcd_recursive(b, a%b)

out = gcd_recursive(a, b)
print(out)