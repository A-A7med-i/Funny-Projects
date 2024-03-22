import re


def validation():

    name = input("Enter the name : ")
    nameValid = re.findall("[A-z]+", name)

    while not nameValid:
        print("Please enter a valid name")
        name = input("Enter the name : ")
        nameValid = re.findall("[A-z]+", name)

    phone = input("Enter the phone : ")
    phoneValid = re.findall(r"[0-9]{3}\s?\-?[0-9]{4}\s?\-?[0-9]{4}", phone)

    while not phoneValid:
        print("Please enter a valid phone")
        phone = input("Enter the phone : ")
        phoneValid = re.findall(r"[0-9]{3}\s?\-?[0-9]{4}\s?\-?[0-9]{4}", phone)

    email = input("Enter the email : ")
    emailValid = re.findall(r"[A-z0-9\.]+\@[A-z0-9\.]+.[A-z0-9\.]", email)

    while not emailValid:
        print("Please enter a valid email")
        phone = input("Enter the email : ")
        emailValid = re.findall(r"[A-z0-9\.]+\@[A-z0-9\.]+.[A-z0-9\.]+", email)

    name = "".join(nameValid)
    phone = "".join(phoneValid)
    email = "".join(emailValid)

    print("Validation information : ")
    print(f"Name : {name.capitalize()}")
    print(f"Phone : {phone}")
    print(f"email : {email}")


if __name__ == "__main__":
    validation()
