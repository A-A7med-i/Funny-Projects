import random


LOGIC = """
1 | 2 | 3
4 | 5 | 6
7 | 8 | 9
"""


class Game:

    def __init__(self):
        self.winning = [
            [1, 5, 9],
            [3, 5, 7],
            [1, 2, 3],
            [4, 5, 6],
            [7, 8, 9],
            [1, 4, 7],
            [2, 5, 8],
            [3, 6, 9],
        ]

    def set_name(self, name: str):
        """Set the name of the player."""
        self.name = name

    def get_name(self) -> str:
        """Get the name of the player."""
        return self.name

    def set_symbol_player(self, symbol_player: str):
        """Set the symbol chosen by the player."""
        self.symbol_player = symbol_player

    def get_symbol_player(self) -> str:
        """Get the symbol chosen by the player."""
        return self.symbol_player

    def show_details(self):
        """Display the player's name and symbol."""
        print(f"{self.get_name()} VS Computer")

    def menu(self):
        """Display the game menu and get the player's choice."""
        print("1- Start Game")
        print("2- Quit Game")
        print("Enter Your Choice 1 OR 2")

        self.choice = input()

    def get_choice(self):
        """Convert the player's choice to an integer."""
        try:
            return int(self.choice)

        except ValueError:
            return None

    def game_loop(self):
        """
        This method runs the main loop of the game until the user quits or wins
        """
        print("Welcome to X-O Game")
        print("Enter Your Name : ")
        self.name_input = input().capitalize().strip()

        # Set the name attribute of the game object
        self.set_name(self.name_input)

        while True:

            # Display the menu options
            self.menu()

            # Get the user's choice as an integer
            choice = self.get_choice()

            # Validate the user's choice
            while choice is None or (choice != 1 and choice != 2):
                print("Invalid Option")
                print("Enter Your Choice 1 OR 2")
                self.choice = input()
                choice = self.get_choice()

            # If the user chooses to quit, exit the loop
            if choice == 2:
                print("Thanks")
                break

            # If the user chooses to play, get their name and symbol
            else:

                print("Enter Your symbol O OR X : ")
                self.symbol_player_input = input().upper().strip()

                # Validate the user's symbol
                while (
                    self.symbol_player_input != "O" and self.symbol_player_input != "X"
                ):
                    print("Invalid Option")
                    print("Enter Your symbol O OR X : ")
                    self.symbol_player_input = input().upper().strip()

                # Set the symbol_player attribute of the game object
                self.set_symbol_player(self.symbol_player_input)

                # Assign the opposite symbol to the computer
                self.symbol_Computer = ""

                if self.get_symbol_player() == "O":
                    self.symbol_Computer = "X"
                else:
                    self.symbol_Computer = "O"

                # Show the details of the game
                self.show_details()

                print(LOGIC)

                # Initialize the logic attribute of the game object as a dictionary
                self.logic = {
                    1: "1",
                    2: "2",
                    3: "3",
                    4: "4",
                    5: "5",
                    6: "6",
                    7: "7",
                    8: "8",
                    9: "9",
                }

                # Initialize the number attribute of the game object as a list
                # that contains the available cell numbers
                self.number = list(range(1, 10))

                # Initialize the next attribute of the game object as a boolean
                # that indicates whose turn it is
                self.next = True

                # Initialize the loop attribute of the game object as a boolean
                # that indicates whether the game is still running
                self.loop = True

                # Start the game loop
                while self.loop:

                    # If it is the user's turn
                    if self.next:
                        print(f"{self.get_name()}'s turn ")
                        print("Choice A Cell (1-9) : ")

                        # Try to get the user's cell choice as an integer
                        try:
                            self.cell_player = int(input())

                        # If the input is not a valid integer, print an error message
                        except ValueError:
                            print("Invalid Value")
                            continue

                        # Validate the user's cell choice
                        while self.cell_player not in self.number:
                            print("Invaled Option : ")
                            print("Choice A Cell (1-9) : ")
                            self.cell_player = int(input())

                        # Remove the chosen cell from the available cells
                        self.number.remove(self.cell_player)

                        # Update the logic dictionary with the user's symbol
                        self.logic[self.cell_player] = self.get_symbol_player()

                        # Switch the turn to the computer
                        self.next = False

                    # If it is the computer's turn
                    elif not self.next:

                        print("Computer's turn ")

                        # Choose a random cell from the available cells
                        self.cell_computer = random.choice(self.number)

                        while self.cell_computer not in self.number:
                            self.cell_computer = random.choice(self.number)

                        print(f"Computer Choice cell {self.cell_computer}")

                        # Update the logic dictionary with the computer's symbol
                        self.logic[self.cell_computer] = self.symbol_Computer

                        # Remove the chosen cell from the available cells
                        self.number.remove(self.cell_computer)

                        # Switch the turn to the user
                        self.next = True

                    # Print the current state of the board
                    print(f"{self.logic[1]} | {self.logic[2]} | {self.logic[3]}")
                    print(f"{self.logic[4]} | {self.logic[5]} | {self.logic[6]}")
                    print(f"{self.logic[7]} | {self.logic[8]} | {self.logic[9]}")

                    # Check if the user has won the game
                    if self.win_player():
                        print("You Win, congratulation.")
                        # Exit the game loop
                        self.loop = False

                    # Check if the computer has won the game
                    elif self.win_computer():
                        print("You Lose, You Can Try Again")
                        # Exit the game loop
                        self.loop = False

                    # Check if the game is a draw
                    if self.draw():
                        print("Draw")
                        # Exit the game loop
                        self.loop = False

    def win_player(self) -> bool:
        """
        This method checks if the player has won the game by forming a line of their symbol
        It returns True if the player has won, False otherwise
        It loops through the possible winning combinations defined in the WINNING constant
        """
        for win in self.winning:
            if all(self.get_symbol_player() == self.logic[cell] for cell in win):
                return True

        return False

    def win_computer(self) -> bool:
        """
        This method checks if the computer has won the game by forming a line of their symbol
        It returns True if the computer has won, False otherwise
        It loops through the possible winning combinations defined in the WINNING constant
        """
        for win in self.winning:
            if all(self.symbol_Computer == self.logic[cell] for cell in win):
                return True

        return False

    def draw(self) -> bool:
        """
        This method checks if the game is a draw, meaning that all the cells are filled and no one has won
        It returns True if the game is a draw, False otherwise
        It uses the set function to check if the logic dictionary values contain only 'X' and 'O'
        """
        if (
            set(self.logic.values()) == {"X", "O"}
            and not self.win_computer()
            and not self.win_player()
        ):
            return True

        return False


if __name__ == "__main__":
    game = Game()
    game.game_loop()
