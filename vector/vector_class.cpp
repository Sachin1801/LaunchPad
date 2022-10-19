#include <iostream>
using namespace std;

class Vector
{
    // private
    int *arr; // array pointer
    int cs;   // current size
    int ms;   // capacity /maximum size of the vector

public:
    // vector default constructor
    Vector(int max_size = 1)
    {
        cs = 0;
        ms = max_size;
        arr = new int[ms]; // we make arr point to a dynamic allocation with size ms;
    }

    void push_back(int d)
    {
        // two cases
        // case 1- if the size is already full and we need to double the old array and transfer all the elements into the
        // new one
        if (cs == ms)
        {
            int *oldarr = arr;
            ms = 2 * ms;
            arr = new int[ms];
            for (int i = 0; i <= cs; i++)
            {
                arr[i] = oldarr[i];
            }
            delete[] oldarr;
        }
        // case 2- if we simply just need to add the element at the back of the arr
        arr[cs] = d;
        cs++;
    }

    void pop_back()
    {
        if (cs >= 0)
        {
            cs--;
        }
    }

    // to check if the vector is empty or not
    bool isEmpty()
    {
        return cs == 0;
    }

    int front() const
    {
        return arr[0];
    }

    int back()
    {
        return arr[cs - 1];
    }

    int at(const int i) const
    {
        return arr[i];
    }

    int size() const
    {
        return cs;
    }

    int capacity() const
    {
        return ms;
    }

    int operator[](const int i)
    {
        return arr[i];
    }
};

int main()
{
    Vector v;
    v.push_back(1);
    v.push_back(7);
    v.push_back(4);
    v.push_back(3);
    v.push_back(2);
    v.push_back(15);

    v.pop_back();

    cout << v.size() << endl;
    cout << v.capacity() << endl;
    cout << v.front() << endl;
    cout << v.back() << endl;
    cout << v.at(2) << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ",";
    }
    return 0;
}