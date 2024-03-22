#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

int main()
{

    string name;
    vector<string> validName;
    regex patternName("[A-z]+");

    while (true)
    {
        cout << "Enter the name : " << endl;
        cin >> name;

        if (regex_match(name, patternName))
        {
            validName.push_back(name);
            break;
        }

        else
        {
            cout << "Invalid name format. Please try again." << endl;
        }
    }

    string phone;
    vector<string> validPhone;
    regex patternPhone(R"([0-9]{3}\s?\-?[0-9]{4}\s?\-?[0-9]{4})");

    while (true)
    {
        cout << "Enter the Phone : " << endl;
        cin >> phone;

        if (regex_match(phone, patternPhone))
        {
            validPhone.push_back(phone);
            break;
        }

        else
        {
            cout << "Invalid Phone format. Please try again." << endl;
        }
    }

    string email;
    vector<string> validEmail;
    regex patternEmail(R"([A-z0-9\.]+\@[A-z0-9\.]+.[A-z0-9\.])");

    while (true)
    {
        cout << "Enter the Email : " << endl;
        cin >> email;

        if (regex_match(email, patternEmail))
        {
            validEmail.push_back(email);
            break;
        }

        else
        {
            cout << "Invalid email format. Please try again." << endl;
        }
    }

    cout << "Validation information : " << endl;

    cout << "Name : " << validName[0] << endl;

    cout << "Phone : " << validPhone[0] << endl;

    cout << "email : " << validEmail[0] << endl;

    return 0;
}