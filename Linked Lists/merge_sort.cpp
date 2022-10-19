// merge_sort.cpp
#include<iostream>
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

node* merge(node* a, node* b)
{
	//base case
	if(a==NULL)
		return b;

	if(b==NULL)
		return a;

	//rec case 
	node* c;

	if(a->data <= b->data)
	{
		c= a;
		c->next = merge(a->next, b);
	}
	else{
		c= b;
		c->next = merge(a,b->next);
	}

	return c;
}

node* midPoint(node* head)
{
	node*slow = head;
	node* fast = head->next;

	while(fast!= NULL and fast->next!=NULL)
	{
		slow = slow->next;
		fast = fast->next->next;


	}
	return slow;
}

node* mergeSort(node*head)
{
	if(head==NULL or head->next==NULL)
	{
		return head;
	}

	//rec case 
	node*mid = midPoint(head);

	node*a = head;
	node*b = mid->next;
	mid->next = NULL;

	//rec sort
	a = mergeSort(a);
	b= mergeSort(b);
	

	//Merge 
	return merge(a,b);
}


int main(){
	node* a= NULL,*at= NULL;
	push_back(a,at,1);
	push_back(a,at,4);
	push_back(a,at,10);
	push_back(a,at,15);
	push_back(a,at,9);
	push_back(a,at,7);

	print(a);

	a= mergeSort(a);

	print(a);

	return 0;
}

