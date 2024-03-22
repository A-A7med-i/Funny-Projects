import random

someWords = """apple banana mango strawberry orange grape pineapple apricot lemon coconut watermelon cherry papaya berry peach lychee muskmelon"""

fruit = someWords.split(" ")

word = random.choice(fruit)

count = 0

correct_guess = []

mes = "Welcome to Guess the word! HINT: word is a name of a fruit"

print(mes.center(len(mes) + 10, "-"))


print("This is the lens of the word")


hidden_word = "-" * len(word)


print(hidden_word.center(len(word) + 20, " "))

count = 0


while True:

    count += 1

    guess = str(input("Enter the char : "))

    if len(guess) != 1:
        raise ValueError("Out of lens")

    else:
        updated_hidden_word = ""

        for i in range(len(word)):
            if (
                guess == word[i]
                and guess not in correct_guess
                and hidden_word[i] == "-"
            ):
                updated_hidden_word += word[i]
                correct_guess.append(guess)
            else:
                updated_hidden_word += hidden_word[i]

        hidden_word = updated_hidden_word

        correct_guess.clear()

        print(hidden_word.center(len(word) + 10, " "))

        if hidden_word == word:
            print(f"You guessed the word in {count} attempts!")
            break

        complete = input("Complete or no Y/N ").upper().strip()

        if complete == "N" or complete == "NO":
            print(f"The word was {word} .")
            break
