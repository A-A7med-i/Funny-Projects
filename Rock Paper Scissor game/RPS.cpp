#include <iostream>
#include <random>

using namespace std;

int main()
{

    cout << "Winning rules of ROCK PAPER SCISSORS are:\n"
         << "Rock vs Paper -> Paper wins\n"
         << "Rock vs Scissors -> Rock wins\n"
         << "Paper vs Scissors -> Scissors wins\n";

    string available[] = {"Rock", "Paper", "Scissors"};

    while (true)
    {

        random_device rd;

        mt19937 gen(rd());

        uniform_int_distribution<int> dist(1, 3);

        int comp_index = dist(gen);

        string choice_comp = available[comp_index - 1];

        cout << "Enter your choice :\n 1 - Rock \n 2 - Paper \n 3 - Scissors \n";

        int index_choice;
        cin >> index_choice;

        if (index_choice > 3 or index_choice < 1)
        {
            cout << "Invalid choice! Please enter 1, 2, or 3." << endl;
            continue;
        }

        string choice = available[index_choice - 1];

        cout << choice << " VS " << choice_comp << endl;

        if (choice_comp == choice)
            cout << "Its a Draw \n"
                 << "<== Its a tie ==>" << endl;

        else if (choice == "Rock" && choice_comp == "Paper")
            cout << "paper wins => \n"
                 << "<== Computer wins ==>" << endl;

        else if (choice == "Rock" && choice_comp == "Scissors")
            cout << "Rock wins => \n"
                 << "<== User wins ==>" << endl;

        else if (choice == "Paper" && choice_comp == "Rock")
            cout << "paper wins => \n"
                 << "<== User wins ==>" << endl;

        else if (choice == "Paper" && choice_comp == "Scissors")
            cout << "Scissors wins => \n"
                 << "<== Computer wins ==>" << endl;

        else if (choice == "Scissors" && choice_comp == "Rock")
            cout << " Rock wins => \n"
                 << "<== Computer wins ==>" << endl;

        else if (choice == "Scissors" && choice_comp == "Paper")
            cout << "Scissors wins => \n"
                 << "<== User wins ==>" << endl;

        cout << "Do you want to play again? (Y/N) " << endl;

        string complete;
        cin >> complete;

        if (toupper(complete[0]) != 'Y')
        {
            break;
        }
    }

    cout << "thanks for playing" << endl;

    return 0;
}
