#This is the solution of bert's Triangle
"""
n = int(input())
i = 1
while i <= n:
    print("_" * (n-i) + "*"*i)
    i +=1
"""

n = int(input())
for i in range(1, n+1):
    print("-" * (n-i) + "*"*i)