#include <iostream>
#include "list.h"
using namespace std;

void reverse_list(Node *&head)
{
    Node *current = head;
    Node *temp;
    Node *prev = NULL;

    while (current != NULL)
    {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    head = prev;
}

int main()
{
    List l;
    l.push_front(1);
    l.push_front(0);
    l.push_back(2);
    l.push_front(10);
    l.pop_front();
    l.insert(5, 2);
    l.remove(2);
    l.insert(15, 0);
    l.push_back(12);
    l.push_back(22);

    Node *head = l.begin();

    l.print(head);

    // cout << l.search(101) << endl;

    // int key;
    // cin >> key;
    // cout << l.recursive_search(key) << endl;
    cout << endl;
    head = l.begin();
    l.pop_back();

    l.print(head);

    head = l.begin();

    reverse_list(head);
    cout << endl;

    l.print(head);

    return 0;
}