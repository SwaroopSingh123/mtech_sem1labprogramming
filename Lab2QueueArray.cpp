#include <iostream>
#include "lab2s-array.h"

using namespace std;

class Stack
{
public:
    ArrayList al;

    void enqueueElement()
    {
        al.insertElement();
    }

    void dequeueElement()
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
        cout << "1. Enqueue an element" << endl;
        cout << "2. Dequeue an element" << endl;
        cout << "3. Quit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            s.enqueueElement();
            break;
        case 2:
            s.dequeueElement();
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