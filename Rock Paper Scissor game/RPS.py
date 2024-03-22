import random

print(
    "Winning rules of the game ROCK PAPER SCISSORS are :\n"
    + "Rock vs Paper -> Paper wins \n"
    + "Rock vs Scissors -> Rock wins \n"
    + "Paper vs Scissors -> Scissor wins \n"
)


available = ["Rock", "Paper", "Scissors"]


while True:

    choice_comp = random.choice(available)

    print("Enter your choice \n 1 - Rock \n 2 - Paper \n 3 - Scissors \n")

    index_choice = int(input("Enter your choice : "))

    if index_choice > 3 or index_choice < 1:
        print("Invalid choice! Please enter 1, 2, or 3.")
        continue

    choice = available[index_choice - 1]

    print(choice, " VS ", choice_comp)

    if choice_comp == choice:
        print("Its a Draw ", end="\n")
        print("<== Its a tie ==>")

    elif choice == "Rock" and choice_comp == "Paper":
        print("paper wins => ", end="\n")
        print("<== Computer wins ==>")

    elif choice == "Rock" and choice_comp == "Scissors":
        print("Rock wins => ", end="\n")
        print("<== User wins ==>")

    elif choice == "Paper" and choice_comp == "Rock":
        print("paper wins => ", end="\n")
        print("<== User wins ==>")

    elif choice == "Paper" and choice_comp == "Scissors":
        print("Scissors wins =>", end="\n")
        print("<== Computer wins ==>")

    elif choice == "Scissors" and choice_comp == "Rock":
        print("Rock wins => ", end="\n")
        print("<== Computer wins ==>")

    elif choice == "Scissors" and choice_comp == "Paper":
        print("Scissors wins =>", end="\n")
        print("<== User wins ==>")

    print("Do you want to play again? (Y/N)")

    complete = input().upper().strip()

    if complete != "Y" or complete != "YES":
        break


print("thanks for playing")
