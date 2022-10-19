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

void insert(node *head, node *tail, int data, int pos)
{
    if (pos == 0)
    {
        push_front(head, tail, data);
        return;
    }
    else if (pos == length(head))
    {
        push_back(head, tail, data);
    }
    else
    {
        node *n = new node(data);
        node *temp = head;
        while (pos != 1)
        {
            temp = temp->next;
            pos--;
        }
        n->next = temp->next;
        temp->next = n;
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

// Delete Function
void deleteAtFront(node *&head, node *&tail)
{
    if (head == NULL)
    {
        return;
    }
    else if (head->next == NULL)
    {
        delete head;
        head = tail = NULL;
    }
    else
    {
        node *t = head;
        head = head->next;
        delete t;
    }
}

void deleteAtEnd(node *&head, node *&tail)
{
    if (head == NULL)
    {
        return;
    }
    else if (head == tail)
    {
        delete head;
        head = tail = NULL;
    }
    else if (head->next == tail)
    {
        head->next = NULL;
        tail = head;
    }
    else
    {
        node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        delete tail;
        temp->next = NULL;
        tail = temp;
    }
}

node *recursive_reverse(node *head)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }

    // rec case
    node *sHead = recursive_reverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return sHead;
}

// Iterative approach
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

int main()
{
    node *head = NULL, *tail = NULL;

    push_back(head, tail, 1);
    push_back(head, tail, 2);
    push_back(head, tail, 3);
    push_back(head, tail, 4);
    push_back(head, tail, 5);

    print(head);

    reverse(head);

    print(head);

    return 0;
}
