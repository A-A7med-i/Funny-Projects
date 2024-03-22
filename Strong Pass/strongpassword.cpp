#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> letters()
{

    vector<string> characters;

    for (size_t i = 33; i < 126; i++)
    {
        characters.push_back(string(1, static_cast<char>(i)));
    }

    return characters;
}

string randomChoices(vector<string> list, int k)
{

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, list.size() - 1);

    string password;

    for (size_t i = 0; i < k; i++)
    {
        int randomIndex = dist(gen);
        password += list[randomIndex];
    }

    return password;
}

int main()
{

    vector<string> l = letters();

    cout << "Enter the number of password : " << endl;

    int number_letter;
    cin >> number_letter;

    while (number_letter < 8)
    {
        cout << "Password should be at least 8 characters long " << endl;
        cout << "Enter the number of password : " << endl;
        cin >> number_letter;
    }

    cout << "Password length is valid " << endl;

    random_device rd;
    mt19937 gen(rd());
    shuffle(l.begin(), l.end(), gen);

    string pass = randomChoices(l, number_letter);

    cout << "Generated password : " << pass << endl;

    return 0;
}