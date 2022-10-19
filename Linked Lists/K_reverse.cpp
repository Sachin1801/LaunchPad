#include <iostream>
using namespace std;

class node
{

public:
    int data;
    node *next;

    node(int d) : data(d), next(NULL) {}
};

int length(node *head)
{
    int ans = 0;
    while (head != NULL)
    {
        head = head->next;
        ans++;
    }
    return ans;
}

void push_front(node *&head, node *&tail, int data)
{
    if (head == NULL)
    {
        node *n = new node(data);
        head = tail = n;
    }
    else
    {
        node *n = new node(data);
        n->next = head;
        head = n;
    }
}

void push_back(node *&head, node *&tail, int d)
{
    if (!head)
    {
        head = tail = new node(d);
    }
    else
    {
        node *n = new node(d);
        tail->next = n;
        tail = n;
    }
}

void print(node *h)
{
    while (h != NULL)
    {
        cout << h->data << "->";
        h = h->next;
    }
    cout << "NULL" << endl;
}

void reverse(node *&head)
{
    node *curr = head, *prev = NULL, *temp;

    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
}

node *k_reverse(node *head, int k)
{
    // base case
    if (head == NULL)
    {
        return NULL;
    }

    // rec case
    // reverser the first k elements

    node *curr = head, *prev = NULL, *temp;
    int cnt = 1;

    while (curr != NULL and cnt <= k)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        cnt++;
    }

    if (temp != NULL)
    {
        head->next = k_reverse(temp, k);
    }

    return prev;
}

int main()
{
    node *head = NULL, *tail = NULL;

    push_back(head, tail, 1);
    push_back(head, tail, 2);
    push_back(head, tail, 3);
    push_back(head, tail, 4);
    push_back(head, tail, 5);
    push_back(head, tail, 6);
    push_back(head, tail, 7);
    push_back(head, tail, 8);

    print(head);

    head = k_reverse(head, 3);

    print(head);

    return 0;
}
