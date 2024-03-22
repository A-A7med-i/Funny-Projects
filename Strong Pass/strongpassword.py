import string
import random


def generate_password():

    LETTERS = list([*string.ascii_letters, *string.digits, *string.punctuation])

    try:
        number_letter = int(input("Enter the number of password : "))

        while number_letter < 8:
            print("Password should be at least 8 characters long ")
            number_letter = int(input("Enter the number of password : "))

        else:
            print("Password length is valid")

            random.shuffle(LETTERS)

            password = random.choices(LETTERS, k=number_letter)

            password = "".join(password[0:])

            print("Generated password : ", password)

    except:
        print("Invalid input")


generate_password()
