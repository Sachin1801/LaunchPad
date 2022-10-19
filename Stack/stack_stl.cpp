#include <iostream>
#include <stack>
using namespace std;

int main()
{

    stack<string> books;

    books.push("Python");
    books.push("OOPs");
    books.push("Java");
    books.push("C++");

    while (!books.empty())
    {
        cout << books.top() << endl;
        books.pop();
    }

    return 0;
}