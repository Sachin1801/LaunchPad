#include <iostream>
using namespace std;
class List;

class Node
{
    int data;

public:
    Node *next;
    Node(int d) : data(d), next(NULL) {}

    int getData()
    {
        return data;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }

    friend class List;
};

class List
{
    Node *head;
    Node *tail;

    int helper(Node *start, int key)
    {
        if (start == NULL)
        {
            return -1;
        }

        // value matches
        if (start->data == key)
        {
            return 0;
        }

        int subidx = helper(start->next, key);

        if (subidx == -1)
        {
            return -1;
        }
        return subidx + 1;
    }

public:
    List() : head(NULL), tail(NULL) {}

    Node *begin()
    {
        return head;
    }

    void push_front(int data)
    {
        if (head == NULL)
        {
            Node *n = new Node(data);
            head = tail = n;
        }
        else
        {
            Node *n = new Node(data);
            n->next = head;
            head = n;
        }
    }

    void push_back(int data)
    {
        if (head == NULL)
        {
            Node *n = new Node(data);
            head = tail = n;
        }
        else
        {
            Node *n = new Node(data);
            tail->next = n;
            tail = n;
        }
    }

    void insert(int data, int pos)
    {
        if (pos == 0)
        {
            push_front(data);
            return;
        }
        else
        {
            Node *n = new Node(data);
            Node *temp = head;

            while (pos != 1)
            {
                temp = temp->next;
                pos--;
            }
            n->next = temp->next;
            temp->next = n;
        }
    }

    int search(int key)
    {
        Node *temp = head;
        int idx = 0;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1;
    }

    int recursive_search(int key)
    {
        int idx = helper(head, key);
        return idx;
    }

    void pop_front()
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void remove(int pos)
    {
        if (pos == 0)
        {
            pop_front();
        }
        Node *n = head->next;
        Node *temp = head;
        while (pos != 1)
        {
            n = n->next;
            temp = temp->next;
            pos--;
        }
        temp->next = n->next;
        n->next = NULL;
        delete n;
    }

    void pop_back()
    {
        Node *n = head->next;
        Node *temp = head;
        while (n->next != NULL)
        {
            n = n->next;
            temp = temp->next;
        }
        temp->next = NULL;
        delete n;
    }

    void print(Node *head)
    {
        while (head != NULL)
        {
            cout << head->getData() << "->";
            head = head->next;
        }
    }

    ~List()
    {
        if (head != NULL)
        {
            delete head;
            head = NULL;
        }
    }
};