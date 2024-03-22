#include <iostream>
#include <random>

using namespace std;

int main()
{

    string fruits[] = {
        "apple", "apricot", "avocado", "banana", "blackberry", "blueberry", "cherry",
        "coconut", "cranberry", "dragonfruit", "durian", "fig", "grape", "grapefruit",
        "guava", "jackfruit", "kiwi", "kumquat", "lemon", "lime", "litchi", "longan",
        "mango", "melon", "nectarine", "orange", "papaya", "passion fruit", "peach",
        "pear", "persimmon", "pineapple", "plantain", "plum", "pomegranate", "prune",
        "raspberry", "starfruit", "strawberry", "tangerine", "tomato", "watermelon",
        "yuzu"};

    random_device rd;

    mt19937 gen(rd());

    uniform_int_distribution<int> dist(0, fruits->size() - 1);

    int random_index = dist(gen);

    string word = fruits[random_index];

    int count = 0;

    cout << "Welcome to Guess the word! HINT: word is a name of a fruit " << endl;

    string hidden_word = "";

    for (size_t i = 0; i < word.size(); i++)
    {
        hidden_word += '-';
    }

    cout << "This is the lens of the word " << endl
         << hidden_word << endl;

    while (true)
    {

        count++;

        cout << "Enter the char : " << endl;

        char guess;
        cin >> guess;

        string updated_hidden_word;

        bool flag = false;

        for (size_t i = 0; i < word.size(); i++)
        {

            if (guess == word[i] && hidden_word[i] == '-' && !flag)
            {
                updated_hidden_word += word[i];
                flag = true;
            }

            else
                updated_hidden_word += hidden_word[i];
        }

        hidden_word = updated_hidden_word;

        cout << hidden_word << endl;

        if (hidden_word == word)
        {
            cout << "You guessed the word in " << count << " attempts!" << endl;
            break;
        }

        cout << "Complete or no Y/N " << endl;

        string complete;
        cin >> complete;

        if (complete == "N" || complete == "NO")
        {
            cout << "The word was " << word << " ." << endl;
            break;
        }
    }

    return 0;
}