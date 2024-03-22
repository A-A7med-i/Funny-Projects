"""
A simple To-Do list application that allows users to add, remove, view, and mark tasks as completed.

This program utilizes a nested dictionary to store tasks with their completion status. Users interact
with the program through a menu-driven interface.
"""

MESSAGE = "1- Added Tasks\n2- Remove Tasks\n3- View Tasks\n4- Complete Tasks\n5- Quit\n"


class ToDo:

    def __init__(self, name: str, age: int):
        """
        Initializes a new TaskManager instance with the provided name and age.

        Args:
            name (str): The user's name.
            age (int): The user's age (optional, could be removed if not used).
        """
        self.name = name
        self.age = age
        self.id = 1
        self.number = [i for i in range(1, 6)]
        self.tasks = {}

    def details(self):
        """
        Prints a friendly greeting to the user with their capitalized name.
        """
        print(f"Hello {self.name.capitalize().strip()}")

    def option(self):
        """
        Prints a provided message, potentially displaying a menu or options.

        Args:
            message (str): The message to be displayed to the user.
        """
        print(MESSAGE)

    def quit(self):
        """
        Checks if the user's choice (obtained from self.choice) indicates quitting (choice == 5).

        Returns:
            bool: True if the user wants to quit, False otherwise.
        """
        return self.choice == 5

    def choice(self):
        """
        Prompts the user to enter a choice within a specific range (1 to 5 in this case).
        Ensures valid input by repeatedly asking for input until a valid choice is entered.

        Returns:
            int: The user's chosen option (validated to be within the allowed range).
        """
        try:
            c = int(input("Please Enter The Choice From 1 to 5\n"))

            if c in range(1, 6):
                return c
            else:
                print("Invalid Option. Please choose between 1 and 5.")

        except ValueError:
            print("Invalid input. Please enter a number.")

    def is_completed(self) -> bool:
        """
        Prompts the user to determine whether a task is completed ("Y" or "y") or not ("N" or "n").
        Returns True if the task is completed, False otherwise.

        Returns:
            bool: True if the task is completed, False otherwise.
        """
        self.complete = input("This Task Is Completed Or Not\nY | N\n")
        return "Y" == self.complete[0] or "y" == self.complete[0]

    def added_task(self):
        """
        Prompts the user to enter a new task, determines its completion status,
        and adds it to the internal tasks dictionary.

        Updates the task ID for the next task entry.

        Handles potential exceptions during user input for task names.
        """
        try:
            self.task = input("Enter the Task\n")
            self.complete = "Completed" if self.is_completed() else "Not Completed"
            self.tasks[self.id] = {self.task: self.complete}
            self.id += 1
            print("Task added successfully!")

        except Exception as e:
            print(f"Error adding task: {e}")

    def completed_task(self):
        """
        Prints a list of completed tasks from a nested dictionary of tasks.

        Args:
            tasks: A nested dictionary of tasks, where the outer keys are integers,
                   the inner keys are task names (strings), and the values are booleans
                   indicating whether the task is completed.
        """
        completed_tasks = [
            task
            for outer_key, inner_dict in self.tasks.items()
            for task, is_completed in inner_dict.items()
            if is_completed
        ]

        if not completed_tasks:
            print("No Completed Task")
        else:
            print("The Tasks Is Completed Are:")
            for task in completed_tasks:
                print(task)

    def view_tasks(self):
        """
        Prints a list of tasks with their completion status for each task ID.

        Args:
            tasks: A nested dictionary of tasks, where the outer keys are integers,
                   the inner keys are task names (strings), and the values are booleans
                   indicating whether the task is completed.
        """
        for task_id, inner_dict in self.tasks.items():
            if inner_dict:
                print(f"ID({task_id}):", end=" ")
            for task_name, is_completed in inner_dict.items():
                if task_name:
                    completion_status = "Complete" if is_completed else "Not Completed"
                    print(f"{task_name} ({completion_status})")
            print()

    def remove_task(self):
        """
        Removes a task from the nested dictionary by ID.

        Args:
            tasks: A nested dictionary of tasks, where the outer keys are integers,
                   the inner keys are task names (strings), and the values are booleans
                   indicating whether the task is completed.
        """
        while True:
            print("Remove Task:")
            print(" Y | N (to exit)")
            choice = input().lower()
            if choice not in ("y", "n"):
                print("Invalid choice. Please enter 'Y' or 'N'.")
                continue

            if choice == "n":
                return

            if choice == "y":
                print("Enter the ID of the task to remove:")
                try:
                    task_id = int(input())
                    if task_id in self.tasks:
                        task_name = self.tasks.pop(task_id).popitem()[0]
                        print(f"Task '{task_name}' (ID: {task_id}) removed.")
                    else:
                        print(f"No task found with ID: {task_id}")
                except ValueError:
                    print("Invalid input. Please enter an integer ID.")
                break

    def loop(self):
        """
        The main loop of the program that presents options to the user and executes
        corresponding actions until the user chooses to quit.
        """
        running = True

        self.details()
        self.option()

        while running:
            choice = self.choice()

            if choice == 1:
                self.added_task()
            elif choice == 2:
                self.remove_task()
            elif choice == 3:
                self.view_tasks()
            elif choice == 4:
                self.completed_task()
            elif self.quit():
                running = False

        print("Exiting program...")


name = input("Enter The Name\n")
age = int(input("Enter The Age\n"))

if __name__ == "__main__":
    todo = ToDo(name, age)
    todo.loop()
