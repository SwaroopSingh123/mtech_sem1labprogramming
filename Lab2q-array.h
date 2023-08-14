#include <iostream>

using namespace std;

template <class T>
class ArrayDef
{
public:
    T *array;
    int length;

    ArrayDef()
    {
        length = 0;
    }
};

class ArrayList
{
public:
    ArrayDef<int> ad;

    void insertElement()
    {
        int num;
        cout << "Enter a value to be inserted: ";
        cin >> num;

        ad.length++;
        ad.array[(ad.length - 1)] = num;
    }

    void deleteElement()
    {

        for (int j = 0; j < ad.length; j++)
        {
            ad.array[j] = ad.array[j + 1];
        }
        ad.length--;
    }
};
