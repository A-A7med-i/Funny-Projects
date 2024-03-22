import random

count = 0

print("Welcome".center(21, "-"))


START = int(input("Enter the start number : "))


END = int(input("Enter the end number : "))


number = random.randint(START, END)


print(f"the number is between {START} to {END} and it is integer number")

while True:

    guess = int(input("Guess a number:- "))

    count += 1

    if guess == number:
        print("Congratulations you did it in ", count, " try")
        break
    elif guess > number:
        print("You guessed high! ")
    elif guess < number:
        print("You guessed small! ")

    complete = input("Complete or no Y/N ").strip().upper()

    if complete == "N" or complete == "NO":
        print(f"The guess number is {number}")
        break
    else:
        continue

print(f"The number of tries is {count}")
