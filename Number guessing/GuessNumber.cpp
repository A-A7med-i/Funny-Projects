#include <iostream>
#include <random>

using namespace std;

int main()
{

    int count = 0;

    cout << "Welcome" << endl;

    cout << "Enter The Start Number Of Guessing" << endl;

    int start;
    cin >> start;

    cout << "Enter The End Number Of Guessing" << endl;

    int end;
    cin >> end;

    cout << "The number is between  " << start << " to " << end << " and it is integer number" << endl;

    random_device rd;

    mt19937 gen(rd());

    uniform_int_distribution<int> distribution(start, end);

    int number = distribution(gen);

    while (true)
    {

        count++;

        cout << "Guess a number:- " << endl;

        int guess;
        cin >> guess;

        if (guess == number)
            cout << "Congratulations you did it in " << count << endl;

        else if (guess > number)
            cout << "You guessed high! " << endl;

        else if (guess < number)
            cout << "You guessed small! " << endl;

        cout << "Complete or no Y/N " << endl;

        string complete;
        cin >> complete;

        if (complete == "N" || complete == "NO")
        {
            cout << "The number of guessing is " << number << endl;
            break;
        }

        else
            continue;
    }

    cout << "The number of tries is " << count << endl;

    return 0;
}