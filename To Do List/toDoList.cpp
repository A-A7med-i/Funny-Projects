#include <iostream>
#include <map>
#include <vector>
#include <limits>

using namespace std;

string message = "1- Added Tasks\n2- Remove Tasks\n3- View Tasks\n4- Complete Tasks\n5- Quit\n";

void details(string name, int age)
{
    cout << "Hello " << char(toupper(name[0])) << name.substr(1) << endl;
}

void option()
{
    cout << message;
}

int choice(int c)
{
    while (c < 1 || c > 5)
    {
        cout << "Invalid Option" << endl;
        cout << "Please Enter The Choice From 1 to 5" << endl;
        cin >> c;
    }
    return c;
}

bool completed()
{
    string complete;

    cout << "This Task Is Completed Or Not" << endl;

    cout << "Y | N" << endl;

    cin >> complete;

    return (complete[0] == 'y' || complete[0] == 'Y');
}

void addedTaskes(map<int, map<string, bool>> &tasks)
{
    static int i = 1;

    string task;

    cout << "Enter the Task" << endl;

    cin >> task;

    bool isCompleted = completed();

    map<string, bool> innerMap = {{task, isCompleted}};

    tasks[i] = innerMap;

    i++;
}

void completedTask(map<int, map<string, bool>> &tasks)
{

    vector<string> completedTasks;

    for (auto outerPair : tasks)
    {
        map<string, bool> &innerMap = outerPair.second;

        for (auto innerPair : innerMap)
        {
            string task = innerPair.first;

            bool isCompleted = innerPair.second;

            if (isCompleted)
                completedTasks.push_back(task);
        }
    }

    if (completedTasks.size() == 0)
    {
        cout << "No Completed Task" << endl;
    }

    else
    {
        cout << "The Tasks Is Completed Is : " << endl;
        for (size_t i = 0; i < completedTasks.size(); i++)
        {
            cout << completedTasks[i] << endl;
        }
    }
}

void viewTasks(map<int, map<string, bool>> &tasks)
{
    for (auto outerPair : tasks)
    {
        int id = outerPair.first;

        if ((tasks[id].begin()->first).size())
            cout << "ID(" << id << ")"
                 << " ";

        map<string, bool> &innerMap = outerPair.second;

        for (auto innerPair : innerMap)
        {

            bool isCompleted = innerPair.second;

            string task = innerPair.first;

            if (task.size())
            {
                cout << task << " ";
                if (isCompleted)
                    cout << "(Complete)" << endl;
                else
                    cout << "(Not Completed)" << endl;
            }
        }

        cout << endl;
    }
}

void removeTask(map<int, map<string, bool>> &tasks)
{

    cout << "Remove From Id : " << endl
         << "Y | N" << endl;

    string choice;
    cin >> choice;

    if (choice[0] == 'y' || choice[0] == 'Y')
    {

        cout << "Enter The Id" << endl;

        int id;
        cin >> id;

        auto it = tasks.find(id);

        if (it != tasks.end())
        {
            cout << "The Tasks " << tasks[id].begin()->first << " Is Removed" << endl;
            tasks.erase(it);
        }

        else
        {
            cout << "No tasks found with the provided ID." << endl;
        }
    }

    else
    {
        cout << "Please Enter The Name Of Task : " << endl;

        string name;
        cin >> name;

        bool found = false;

        for (auto &outerPair : tasks)
        {
            auto &innerMap = outerPair.second;

            auto it = innerMap.find(name);

            if (it != innerMap.end())
            {
                innerMap.erase(name);
                found = true;
                break;
            }
        }

        if (found)

            cout << "Task '" << name << "' removed." << endl;

        else

            cout << "Task '" << name << "' not found." << endl;
    }
}

bool quit(int q)
{
    int c = choice(q);

    return c == 5;
}

void loop()
{

    bool l = true;

    map<int, map<string, bool>> tasks;

    string name;

    cout << "Enter The Name" << endl;
    cin >> name;

    int age;

    cout << "Enter The Age" << endl;
    cin >> age;

    details(name, age);

    option();

    int c;

    while (l)
    {

        cout << "Please Enter The Choice From 1 to 5" << endl;
        cin >> c;

        c = choice(c);

        if (c == 1)
            addedTaskes(tasks);

        else if (c == 2)
            removeTask(tasks);

        else if (c == 3)
            viewTasks(tasks);

        else if (c == 4)
            completedTask(tasks);

        else if (quit(c))
            l = false;
    }
}

int main()
{

    loop();

    return 0;
}