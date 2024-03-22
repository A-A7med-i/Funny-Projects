#include <iostream>
#include <random>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const string Logic = "1 | 2 | 3\n4 | 5 | 6\n7 | 8 | 9\n";

vector<vector<int>> winning = {
    {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {1, 4, 7}, {2, 5, 8}, {3, 6, 9}, {1, 5, 9}, {3, 5, 7}};

int menu()
{

    int choice;

    cout << "1- Start Game" << endl;
    cout << "2- Quit Game" << endl;
    cout << "Enter Your Choice 1 OR 2" << endl;

    cin >> choice;

    return choice;
}

bool winPlayer(map<int, char> &logic, vector<vector<int>> &winning, char &playerSymbol)
{

    for (auto &win : winning)
    {

        bool allMatch = true;

        for (auto &cell : win)
        {
            if (logic[cell] != playerSymbol)
            {
                allMatch = false;
                break;
            }
        }

        if (allMatch)
        {
            return true;
        }
    }

    return false;
}

bool winComputer(map<int, char> &logic, vector<vector<int>> &winning, char &symbolComputer)
{

    for (auto &win : winning)
    {
        bool allMathc = true;

        for (auto &cell : win)
        {
            if (logic[cell] != symbolComputer)
            {
                allMathc = false;
                break;
            }
        }

        if (allMathc)
        {
            return true;
        }
    }

    return false;
}

bool draw(map<int, char> &logic, vector<vector<int>> &winning, char &symbolComputer, char &symbolPlayer)
{

    bool allEmpty = true;

    for (auto &l : logic)
    {
        if (l.second != 'X' && l.second != 'O')
        {
            allEmpty = false;
            break;
        }
    }

    if (allEmpty && !winComputer(logic, winning, symbolComputer) && !winPlayer(logic, winning, symbolPlayer))
    {
        return true;
    }

    return false;
}

void gameLoop()
{

    string name;

    cout << "Welcome to X-O Game" << endl;
    cout << "Enter Your Name : " << endl;

    cin >> name;

    while (true)
    {

        int choice = menu();

        if (choice == 2)
        {
            cout << "Thanks" << endl;
            break;
        }

        else
        {

            char symbolPlayer;
            cout << "Enter Your symbol O OR X : " << endl;
            cin >> symbolPlayer;
            symbolPlayer = toupper(symbolPlayer);

            while (symbolPlayer != 'O' && symbolPlayer != 'X')
            {
                cout << "Invalid Option" << endl;
                cout << "Enter Your symbol O OR X : " << endl;
                cin >> symbolPlayer;
                symbolPlayer = toupper(symbolPlayer);
            }

            char symbolComputer;

            if (symbolPlayer == 'O')
                symbolComputer = 'X';

            else
                symbolComputer = 'O';

            name[0] = toupper(name[0]);

            cout << name << " VS Computer" << endl;

            cout << Logic;

            map<int, char> logic;

            logic = {
                {1, '1'}, {2, '2'}, {3, '3'}, {4, '4'}, {5, '5'}, {6, '6'}, {7, '7'}, {8, '8'}, {9, '9'}};

            vector<int> number = {1, 2, 3, 4, 5, 6, 7, 8, 9};

            bool next = true;

            bool loop = true;

            while (loop)
            {

                int cell_player;
                int cell_computer;

                if (next)
                {
                    cout << name << "'s turn " << endl;

                    bool founded = false;

                    while (!founded)
                    {

                        cout << "Choice A Cell (1-9) : " << endl;

                        cin >> cell_player;

                        for (size_t i = 0; i < 10; i++)
                        {
                            if (cell_player == number[i])
                            {
                                founded = true;
                                break;
                            }
                        }

                        if (!founded)
                            cout << "Invalid Option" << endl;
                    }

                    auto it = find(number.begin(), number.end(), cell_player);

                    number.erase(it);

                    logic[cell_player] = symbolPlayer;

                    next = false;
                }

                else if (!next)
                {

                    cout << "Computer's turn " << endl;

                    bool founded = false;

                    while (!founded)
                    {

                        random_device rd;
                        mt19937 gen(rd());
                        uniform_int_distribution dist(1, 9);

                        int index = dist(gen);

                        cell_computer = number[index - 1];

                        for (size_t i = 0; i < 10; i++)
                        {
                            if (cell_computer == number[i])
                            {
                                founded = true;
                                break;
                            }
                        }
                    }

                    cout << "Computer Choice cell " << cell_computer << endl;

                    auto it = find(number.begin(), number.end(), cell_computer);

                    number.erase(it);

                    logic[cell_computer] = symbolComputer;

                    next = true;
                }

                cout << logic[1] << " | " << logic[2] << " | " << logic[3] << endl;
                cout << logic[4] << " | " << logic[5] << " | " << logic[6] << endl;
                cout << logic[7] << " | " << logic[8] << " | " << logic[9] << endl;

                if (winPlayer(logic, winning, symbolPlayer))
                {
                    cout << "You Win, congratulation." << endl;
                    loop = false;
                }

                else if (winComputer(logic, winning, symbolComputer))
                {
                    cout << "You Lose, You Can Try Again" << endl;
                    loop = false;
                }

                if (draw(logic, winning, symbolComputer, symbolPlayer))
                {
                    cout << "Draw" << endl;
                    loop = false;
                }
            }
        }
    }
}

int main()
{

    gameLoop();

    return 0;
}