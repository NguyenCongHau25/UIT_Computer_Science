/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
stable_sort
partial_sort
partial_sort_copy
sort_heap
set
multi_set
map
unordered_map
include
[
]
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -

struct ao
{
    string loai;
    int so;
};

void input(ao a)
{
    cin >> a.loai >> a.so;
}

struct Node
{
    ao data;
    Node* next;
};

struct List
{
    Node *head, *tail;
};

void CreateList(List &l)
{
    l.head = l.tail = NULL;
}

Node* CreateNode(ao x)
{
    Node*p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

void AddTail(List &l, ao x)
{
    Node *p = CreateNode(x);
    if ( p == NULL)
        return;
    if (l.head == NULL)
    {
        l.head = l.tail = p;
        return;
    }

        l.tail->next = p;
        l.tail = p;

}

void PrintList(List l)
{
    Node *p = l.head;
    while(p != NULL)
    {
        cout << p->data.loai << " " << p->data.so << endl;
        p=p->next;
    }

}

int main()
{
    ao x;
    List L;
    CreateList(L);
    while (true)
    {
        input(x);
        if (x.loai == "-1")
            break;
        AddTail(L, x);
    }
    int m;
    cin >> m;
    PrintList(L);
    return 0;
}
