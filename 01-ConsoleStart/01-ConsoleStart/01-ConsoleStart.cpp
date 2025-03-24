// 01-ConsoleStart.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::map;

void Cookies() {
    system("cls");
    cout << "\nDo you want to accept our cookies?\n";
    cout << "1.Yes      2.No\n";
}

int Add(int a, int b) {
    return a + b;
}

int main()
{
    std::srand(time(NULL));

    cout << "What is your name?\n";
    string name;
    cin >> name;
    cout << "Hello " << name << ".\n";
    cout << "What is your favourite color?\n";
    string color;
    cin >> color;
    cout << color << " mmmmh.\n";
    cout << "What is the capital of the Zinbabwe?\n";
    string capital;
    cin >> capital;
    cout << capital << "?\n I'm pretty sure it's not that.\n";
    cout << "\n Random test time!\n";
    int dice;
    dice = (std::rand() % 6) + 1;
    cout << dice << " \n";
    if (dice == 6) cout << " The magic attract the monsters.\n";
    else cout << " The room is empty.\n";
    
    cout << "Your name, " << *&name << " is stored in " << &name << ".\n";

    cout << "\nHow many objects do you want to have in your bag?\n";
    int bagSize;
    cin >> bagSize;
    vector<string> bagItems(bagSize, "");
    for (int i = 0; i < bagSize; i++) {
        cout << "Item n°" << i + 1 << ":\n";
        cin >> bagItems[i];
    }

    cout << "\nHere are your items:\n";
    for(string object : bagItems) {
        cout << object << "\n";
    }
    
    map<int, string> objects{
        {1, "un"},
        {2, "deux"},
        {3, "trois"},
        {4, "quatre"},
        {5, "cinq"}
    };

    cout << "\nChoose a number between 1 & 5:\n";
    int choice;
    cin >> choice;
    cout << objects[choice] << "\n";
    
    cout << "\nChoose another number between 1 & 5:\n";
    cin >> choice;
    switch (choice) {
    case 1:
        cout << "one\n";
        break;
    case 2:
        cout << "two\n";
        break;
    case 3:
        cout << "three\n";
        break;
    case 4:
        cout << "four\n";
        break;
    case 5:
        cout << "five\n";
        break;
    default:
        cout << ">:(\n";
        break;
    }

    int cookies;
    do {
        Cookies();
        cin >> cookies;
    } while (cookies != 1);

    cout << "\nYou have been added to our mailing list\n";

    cout << Add(2, 2);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
