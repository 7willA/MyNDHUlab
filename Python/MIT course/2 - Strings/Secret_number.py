secret = 50
guess = int(input("Guess a number: "))
print(guess == secret)
if guess < secret:
    print("too low")
elif guess > secret:
    print("too high")
else:
    print("correct")