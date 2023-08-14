#include <iostream>
#include "lab2s-array.h"

using namespace std;

class Stack
{
public:
    ArrayList al;

    void pushElement()
    {
        al.insertElement();
    }

    void popElement()
    {
        al.deleteElement();
    }
};

int main()
{
    int choice;
    Stack s;

    while (true)
    {
        cout << "Which operation do you wanna perform?" << endl;
        cout << "1. Push an element" << endl;
        cout << "2. Pop an element" << endl;
        cout << "3. Quit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            s.pushElement();
            break;
        case 2:
            s.popElement();
            break;
        case 3:
            exit(0);
            break;
        default:
            cout << "This option is not valid" << endl;
        }
    }
    return 0;
}